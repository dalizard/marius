#include "vm.hpp"
#include "code.hpp"
#include "method.hpp"
#include "class.hpp"
#include "environment.hpp"
#include "state.hpp"
#include "disassembler.hpp"
#include "closure.hpp"
#include "stack_frame.hpp"
#include "tuple.hpp"
#include "exception.hpp"
#include "invoke_info.hpp"

#include <stdio.h>

#define TRACE

namespace marius {

  VM::VM(bool debug)
    : debug_(debug)
  {
    stack_size_ = cInitialStack;
    stack_ = new OOP[cInitialStack];
    frames_ = new StackFrame[cInitialStack];
    top_frame_ = frames_ - 1;
  }

  OOP VM::run(State& S, Method* meth) {
    return run(S, meth, stack_);
  }

  struct ExceptionHandler {
    int reg;
    int ip;

    ExceptionHandler(int r, int i)
      : reg(r)
      , ip(i)
    {}
  };

  class FrameTracker {
    VM* vm_;

  public:
    FrameTracker(VM* vm)
      : vm_(vm)
    {
      vm_->top_frame_++;
    }

    ~FrameTracker() {
      vm_->top_frame_--;
    }
  };

  OOP VM::run(State& S, Method* meth, OOP* fp) {
    FrameTracker ft(this);
    top_frame_->method = meth;

    Code& code = *meth->code();

    Closure* clos = new(S) Closure(code.closed_over_vars(), meth->closure());

    top_frame_->closure = clos;

    Instruction* start = code.code();
    Instruction* seq = start;
    Instruction* end = seq + code.size();

    std::vector<ExceptionHandler> es;

    OOP t;
    ExceptionHandler te(0,0);

#ifdef TRACE
    Disassembler dis(code);
#endif

    while(seq < end) {
#ifdef TRACE
      if(debug_) {
        int ip = seq - code.code();
        printf("[%04d] ", ip);
        dis.print_one(seq);
      }
#endif

      switch(*seq++) {
      case MOVI8:
        fp[seq[0]] = OOP::integer(seq[1]);
        seq += 2;
        break;
      case MOVI32:
        fp[seq[0]] = OOP::integer(*((int*)seq));
        seq += 5;
        break;
      case MOVR:
        fp[seq[0]] = fp[seq[1]];
        seq += 2;
        break;

      case MOVN:
        fp[seq[0]] = OOP();
        seq += 1;
        break;
      case MOVT:
        fp[seq[0]] = OOP::true_();
        seq += 1;
        break;
      case MOVF:
        fp[seq[0]] = OOP::false_();
        seq += 1;
        break;

      case SENDI:
        top_frame_->ip = (seq - start) - 1;

        t = run_method(S,
                       fp[seq[2]], as_string(fp[seq[1]]),
                       seq[3],     fp + (seq[2] + 1));

        if(t.unwind_p()) {
          if(es.size() == 0) return t;
          te = es.back();
          es.pop_back();

          fp[te.reg] = t.unwind_value();

          seq = code.code() + te.ip;
        } else {
          fp[seq[0]] = t;
          seq += 4;
        }

        break;

      case SENDI_KW:
        top_frame_->ip = (seq - start) - 1;

        t = run_kw_method(S,
                          fp[seq[2]], as_string(fp[seq[1]]),
                          seq[3],     fp + (seq[2] + 1),
                          code.keywords(seq[4]));

        if(t.unwind_p()) {
          if(es.size() == 0) return t;
          te = es.back();
          es.pop_back();

          fp[te.reg] = t.unwind_value();

          seq = code.code() + te.ip;
        } else {
          fp[seq[0]] = t;
          seq += 5;
        }

        break;

      case CALL:
        top_frame_->ip = (seq - start) - 1;

        t = run_method(S,
                       fp[seq[2]], code.string(seq[1]),
                       seq[3],     fp + (seq[2] + 1));

        if(t.unwind_p()) {
          if(es.size() == 0) return t;
          te = es.back();
          es.pop_back();

          fp[te.reg] = t.unwind_value();

          seq = code.code() + te.ip;
        } else {
          fp[seq[0]] = t;
          seq += 4;
        }

        break;
      case CALL_KW:
        top_frame_->ip = (seq - start) - 1;

        t = run_kw_method(S,
                          fp[seq[2]], code.string(seq[1]),
                          seq[3],     fp + (seq[2] + 1),
                          code.keywords(seq[4]));

        if(t.unwind_p()) {
          if(es.size() == 0) return t;
          te = es.back();
          es.pop_back();

          fp[te.reg] = t.unwind_value();

          seq = code.code() + te.ip;
        } else {
          fp[seq[0]] = t;
          seq += 5;
        }

        break;

      case LATTR:
        top_frame_->ip = (seq - start) - 1;

        t = load_attr(S, code.string(seq[1]), fp[seq[2]],
                      fp + (seq[2] + 1));

        if(t.unwind_p()) {
          if(es.size() == 0) return t;
          te = es.back();
          es.pop_back();

          fp[te.reg] = t.unwind_value();

          seq = code.code() + te.ip;
        } else {
          fp[seq[0]] = t;
          seq += 3;
        }

        break;

      case IVA:
        fp[-1].set_attribute(S, code.string(seq[0]), fp[seq[1]]);
        seq += 2;
        break;

      case IVR:
        fp[seq[0]] = fp[-1].attribute(code.string(seq[1]), 0);
        seq += 2;
        break;

      case LOADS:
        fp[seq[0]] = OOP(code.string(seq[1]));

        seq += 2;
        break;

      case LOADC:
        fp[seq[0]] = OOP(new(S) Method(meth->scope(), code.code(seq[1]), clos));

        seq += 2;
        break;

      case SELF:
        fp[seq[0]] = fp[-1];

        seq += 1;
        break;

      case RET:
        return fp[*seq++];

      case JMPF:
        seq += (seq[0] + 1);
        break;

      case JMPB:
        S.check();
        seq -= (seq[0] + 1);
        break;

      case JMPIT:
        if(fp[seq[0]].true_condition_p()) {
          seq += (seq[1] + 1);
        } else {
          seq += 2;
        }

        break;

      case JMPIF:
        if(!fp[seq[0]].true_condition_p()) {
          seq += (seq[1] + 1);
        } else {
          seq += 2;
        }

        break;

      case REGE:
        es.push_back(ExceptionHandler(seq[0], seq[1]));
        seq += 2;

        break;

      case POPE:
        es.pop_back();
        break;

      case LVAR:
        fp[seq[0]] = clos->get_at_depth(seq[1], seq[2]);
        seq += 3;

        break;
      case SVAR:
        clos->set_at_depth(seq[0], seq[1], fp[(int)(char)seq[2]]);
        seq += 3;

        break;
      case RAISE:
        top_frame_->ip = (seq - start) - 1;
        return OOP::make_unwind(Exception::wrap(S, fp[seq[0]]));

      case NOT:
        if(fp[seq[1]].true_condition_p()) {
          fp[seq[0]] = OOP::false_();
        } else {
          fp[seq[0]] = OOP::true_();
        }

        seq += 2;

        break;

      case TUPLE:
        fp[seq[0]] = Tuple::make(S, &fp[seq[1]], seq[2]);
        seq += 3;
        break;


      default:
        printf("UNKNOWN INSTRUCTION: %d\n", seq[-1]);
        check(false);
      }
    }

    return OOP::nil();
  }

  OOP VM::run_method(State& S,
                     OOP recv, String* name, int argc, OOP* fp)
  {
    Method* meth = recv.find_method(name);

    if(!meth) {
      return OOP::make_unwind(
          Exception::create(S, "NoMethodError",
                               "Unable to find method '%s'", name->c_str()));
    }

    S.last_fp = fp;

    Arguments args(S, argc, fp);

    return meth->run(S, recv, args);
  }

  void VM::reorg_args(OOP* fp, Method* meth, ArgMap& keywords) {
    Code* code = meth->code();
    check(code);

    ArgMap& args = code->args();

    OOP* temp = fp + args.size();

    for(ArgMap::iterator i = args.begin();
        i != args.end();
        ++i) {
      int req = (*i).second;

      ArgMap::iterator f = keywords.find((*i).first);

      if(f == keywords.end()) {
        temp[req] = fp[req];
      } else {
        int is   = (*f).second;
        temp[req] = fp[is];
      }
    }

    for(size_t i = 0; i < args.size(); i++) {
      fp[i] = temp[i];
    }
  }

  OOP VM::run_kw_method(State& S,
                        OOP recv, String* name, int argc, OOP* fp,
                        ArgMap& keywords)
  {
    Method* meth = recv.find_method(name);

    if(!meth) {
      return OOP::make_unwind(
          Exception::create(S, "NoMethodError",
                               "Unable to method '%s'", name->c_str()));
    }

    if(!meth->simple_p()) {
      reorg_args(fp, meth, keywords);
    }

    S.last_fp = fp;

    Arguments args(S, argc, fp, keywords);

    return meth->run(S, recv, args);
  }

  OOP VM::load_attr(State& S, String* name, OOP recv, OOP* fp) {
    bool found = false;
    OOP val = recv.attribute(name, &found);
    if(found) return val;

    return OOP::nil();
  }

  String* VM::as_string(OOP val) {
    return val.as_string();
  }

  void VM::print_call_stack(State& S) {
    int i = 0;

    StackFrame* sf = top_frame_;

    while(sf >= frames_) {
      printf("%02d: %s#%s\n", i++, sf->method->scope()->c_str(),
                              sf->method->name(S)->c_str());
      sf--;
    }
  }

  InvokeInfo* VM::invoke_info(State& S) {
    StackFrame* sf = frames_;

    InvokeInfo* last = 0;

    while(sf <= top_frame_) {
      InvokeInfo* i = new(S) InvokeInfo(last, sf->ip, sf->method);
      last = i;
      sf++;
    }

    return last;
  }
}

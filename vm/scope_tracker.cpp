#include "ast.hpp"
#include "string_map.hpp"
#include "local.hpp"

#include <list>

namespace r5 {
  using namespace ast;

  class ScopeTracker : public Visitor {
    typedef StringMap<Local*>::type LocalScope;

    r5::State& S;
    LocalScope* scope_;

    std::list<LocalScope*> stack_;
    ArgMap& globals_;
    LocalMap& locals_;

    std::list<ast::Trait*> trait_stack_;

  public:
    ScopeTracker(r5::State& S, ArgMap& globals, LocalMap& locals)
      : S(S)
      , scope_(new LocalScope)
      , globals_(globals)
      , locals_(locals)
    {}

    void visit(Import* imp) {
      int depth = stack_.size();

      ArgMap::iterator i = globals_.find(String::internalize(S, "Importer"));

      assert(i != globals_.end());
      Local* l = new Local;
      l->make_global(i->second, depth);

      Local* lv = locals_.add(imp);
      lv->set_extra(l);

      scope_->insert(LocalScope::value_type(imp->name(), lv));
    }

    void before_visit(ast::Trait* trait) {
      trait_stack_.push_back(trait);
    }

    void visit(ast::Trait* trait) {
      int depth = stack_.size();

      ArgMap::iterator i = globals_.find(String::internalize(S, "Trait"));

      assert(i != globals_.end());
      Local* l = new Local;
      l->make_global(i->second, depth);

      Local* lv = locals_.add(trait);
      lv->set_extra(l);

      scope_->insert(LocalScope::value_type(trait->name(), lv));

      trait_stack_.pop_back();
    }

    bool in_trait_p() {
      return !trait_stack_.empty();
    }

    void visit(ast::Call* call) {
      // This implements half of the the Markov rule
      if(call->self_less_p()) {
        if(find_scoped(call, call->name())) return;
      }

      if(in_trait_p()) {
        if(call->recv()->self_p()) {
          ast::Trait* t = trait_stack_.back();
          t->add_call(call->name());
        }
      }
    }

    void visit(ast::Dictionary* dict) {
      int depth = stack_.size();

      ArgMap::iterator i = globals_.find(String::internalize(S, "Dictionary"));

      assert(i != globals_.end());
      Local* l = new Local;
      l->make_global(i->second, depth);

      locals_.add(dict, l);
    }

    void before_visit(ast::Class* cls) {
      scope_->insert(LocalScope::value_type(cls->name(),
                                            locals_.add(cls->body())));
    }

    void before_visit(Scope* s) {
      stack_.push_back(scope_);
      scope_ = new LocalScope;

      // ArgMap& args = s->arguments();

      ArgumentList& args = s->arg_objs();

      for(ArgumentList::iterator i = args.begin();
          i != args.end();
          ++i)
      {
        Argument* a = *i;
        Local* l = new Local;
        l->make_arg(a->position());

        locals_.add(a, l);

        scope_->insert(LocalScope::value_type(a->name(), l));
      }

      Argument* a = s->self();
      if(a) {
        Local* l = new Local;
        l->make_arg(a->position());

        locals_.add(a, l);
        scope_->insert(LocalScope::value_type(a->name(), l));
      }
    }

    void visit(Scope* s) {
      int regs = 0;
      int closed = 0;

      for(LocalScope::iterator i = scope_->begin();
          i != scope_->end();
          ++i) {
        Local* l = i->second;
        if(l->reg_p()) {
          int r;

          if(l->needs_reg_p()) {
            r = regs++;
            i->second->set_reg(r);
          } else {
            r = i->second->reg();
          }

          s->add_local(i->first, r);
        } else {
          int c = closed++;
          i->second->set_reg(c);
          s->add_closed_local(i->first, c);
        }
      }

      delete scope_;

      scope_ = stack_.back();

      stack_.pop_back();
    }

    void visit(Assign* a) {
      LocalScope::iterator j = scope_->find(a->name());
      if(j != scope_->end()) {
        locals_.add(a, j->second);
        return;
      }

      int d = 1;
      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, d++)
      {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(a->name());
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(a);
          l->make_closure_access(j->second, d);
          return;
        }
      }

      scope_->insert(LocalScope::value_type(a->name(), locals_.add(a)));
    }

    void start_try_body(Try* t) {
      if(!t->id()) return;

      LocalScope::iterator j = scope_->find(t->id());
      if(j != scope_->end()) {
        locals_.add(t, j->second);
        return;
      }

      int d = 0;
      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, d++)
      {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(t->id());
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(t);
          l->make_closure_access(j->second, d);
        }
      }

      scope_->insert(LocalScope::value_type(t->id(), locals_.add(t)));
    }

    void visit(AssignOp* a) {
      LocalScope::iterator j = scope_->find(a->name());
      if(j != scope_->end()) {
        locals_.add(a, j->second);
        return;
      }

      int d = 0;
      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, d++)
      {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(a->name());
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(a);
          l->make_closure_access(j->second, d);
        }
      }

      scope_->insert(LocalScope::value_type(a->name(), locals_.add(a)));
    }

    bool find_scoped(Node* n, String* name) {
      LocalScope::iterator j = scope_->find(name);
      if(j != scope_->end()) {
        locals_.add(n, j->second);
        return true;
      }

      int depth = 1;

      for(std::list<LocalScope*>::reverse_iterator i = stack_.rbegin();
          i != stack_.rend();
          ++i, depth++) {
        LocalScope* s = *i;

        LocalScope::iterator j = s->find(name);
        if(j != s->end()) {
          j->second->make_closure();
          Local* l = locals_.add(n);
          l->make_closure_access(j->second, depth);
          return true;
        }
      }

      ArgMap::iterator i = globals_.find(name);
      if(i != globals_.end()) {
        Local* l = locals_.add(n);
        l->make_global(i->second, depth-1);
        return true;
      }

      return false;
    }

    void visit(Named* n) {
      find_scoped(n, n->name());
    }

    void visit(Self* s) {
      find_scoped(s, String::internalize(S, "self"));
    }
  };

  void calculate_locals(r5::State& S, ast::Node* top,
                        ArgMap& globals, LocalMap& locals) {
    ScopeTracker tracker(S, globals, locals);
    top->accept(&tracker);
  }
}

#ifndef METHOD_HPP
#define METHOD_HPP

#include "oop.hpp"
#include "simple_func.hpp"
#include "memory_object.hpp"

namespace marius {
  class VM;
  class Environment;
  class Code;
  class Closure;

  class Method {
    String& scope_;
    SimpleFunc func_;
    Code* code_;
    int arity_;
    Closure* closure_;

  public:
    Method(String& scope, SimpleFunc func, int arity, Closure* closure=0);
    Method(String& scope, Code& code, Closure* closure=0);

    Code* code() {
      return code_;
    }

    int arity() {
      return arity_;
    }

    Closure* closure() {
      return closure_;
    }

    String& scope() {
      return scope_;
    }

    String& name();

    OOP closed_over_variable(int depth, int idx);
    void set_closed_over_variable(int depth, int idx, OOP val);

    OOP run(State& S, OOP recv, Arguments& args);
  };
}

#endif

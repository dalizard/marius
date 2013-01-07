#ifndef MODULE_HPP
#define MODULE_HPP

#include "method_table.hpp"
#include "simple_func.hpp"

namespace marius {
  class Module {
    MethodTable method_table_;

  public:
    Method* lookup(String& name);
    void add_method(const char* name, SimpleFunc func);
  };
}

#endif
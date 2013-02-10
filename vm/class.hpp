#ifndef CLASS_HPP
#define CLASS_HPP

#include "oop.hpp"
#include "simple_func.hpp"
#include "method_table.hpp"
#include "memory_object.hpp"
#include "attributes.hpp"

namespace marius {
  class Method;
  class String;
  class MethodTable;

  class Class : public MemoryObject, public Attributes {
    String& name_;
    Class* superclass_;
    MethodTable method_table_;

  public:
    enum Boot { Boot };
    Class(Class* sup, String& name);
    Class(enum Boot, Class* cls, Class* sup, String& name);

    String& name() {
      return name_;
    }

    static void init_base(Class** tbl);

    static Class* base_class(int idx);

    static String& metaclass_name(String& name);

    Method* lookup(String& name);
    void add_method(const char* name, SimpleFunc func, int arity);
    void add_native_method(const char* name, Method* meth);

    void add_class_method(const char* name, SimpleFunc func, int arity);
  };
}

#endif

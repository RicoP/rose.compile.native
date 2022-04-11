#pragma once

#include <rose/hash.h>
#include <rose/typetraits.h>
#include <serializer/serializer.h>

///////////////////////////////////////////////////////////////////
//  AUTOGEN                                                      //
//  command:
//    rose.parser -I options.h -O rose.compile.serializer.h
///////////////////////////////////////////////////////////////////

struct                CompileOptions;
namespace rose {
  namespace ecs {
    void        serialize(CompileOptions &o, ISerializer &s);
    void      deserialize(CompileOptions &o, IDeserializer &s);
  }
  hash_value         hash(const CompileOptions &o);
  template<>
  struct type_id<CompileOptions> {
    inline static hash_value VALUE = 14990800497510514649ULL;
  };
  void construct_defaults(      CompileOptions &o); // implement me
}
bool operator==(const CompileOptions &lhs, const CompileOptions &rhs);
bool operator!=(const CompileOptions &lhs, const CompileOptions &rhs);


#ifdef IMPL_SERIALIZER

    #ifndef IMPL_SERIALIZER_UTIL
    #define IMPL_SERIALIZER_UTIL
    #include <cstring>

    namespace {
    //internal helper methods
    template<class T>
    bool rose_parser_equals(const T& lhs, const T& rhs) {
      return lhs == rhs;
    }

    template<class T, size_t N>
    bool rose_parser_equals(const T(&lhs)[N], const T(&rhs)[N]) {
      for (size_t i = 0; i != N; ++i) {
        if (lhs[i] != rhs[i]) return false;
      }
      return true;
    }

    template<size_t N>
    bool rose_parser_equals(const char(&lhs)[N], const char(&rhs)[N]) {
      for (size_t i = 0; i != N; ++i) {
        if (lhs[i] != rhs[i]) return false;
        if (lhs[i] == 0) return true;
      }
      return true;
    }

    template<class T>
    bool rose_parser_equals(const std::vector<T> &lhs, const std::vector<T> &rhs) {
      if (lhs.size() != rhs.size()) return false;
      for (size_t i = 0; i != lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) return false;
      }
      return true;
    }

    template<class TL, class TR>
    void assign(TL& lhs, TR&& rhs) {
      lhs = rhs;
    }

    template<class T>
    void construct_default(std::vector<T> & v) {
      c.clear();
    }
    }
    #endif
  
///////////////////////////////////////////////////////////////////
//  struct CompileOptions
///////////////////////////////////////////////////////////////////
bool operator==(const CompileOptions &lhs, const CompileOptions &rhs) {
  return
    rose_parser_equals(lhs.includePaths, rhs.includePaths) ;
}

bool operator!=(const CompileOptions &lhs, const CompileOptions &rhs) {
  return
    !rose_parser_equals(lhs.includePaths, rhs.includePaths) ;
}

void rose::ecs::serialize(CompileOptions &o, ISerializer &s) {
  if(s.node_begin("CompileOptions", rose::hash("CompileOptions"), &o)) {
    s.key("includePaths");
    serialize(o.includePaths, s);
    s.node_end();
  }
  s.end();
}

void rose::ecs::deserialize(CompileOptions &o, IDeserializer &s) {
  //implement me
  //construct_defaults(o);

  while (s.next_key()) {
    switch (s.hash_key()) {
      case rose::hash("includePaths"):
        deserialize(o.includePaths, s);
        break;
      default: s.skip_key(); break;
    }
  }
}

rose::hash_value rose::hash(const CompileOptions &o) {
  rose::hash_value h = rose::hash(o.includePaths);
  return h;
}

#endif

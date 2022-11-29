---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group/Add.cpp
    title: algebra/group/Add.cpp
  - icon: ':question:'
    path: algebra/monoid/Min.cpp
    title: algebra/monoid/Min.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/group/Add.cpp\"\ntemplate<typename X>\nstruct GroupAdd\
    \ {\n  using value_type = X;\n  static constexpr X op(const X &x, const X &y)\
    \ noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, long long n) noexcept\
    \ { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static\
    \ constexpr bool commute = true;\n};\n#line 1 \"algebra/monoid/Min.cpp\"\ntemplate<typename\
    \ X>\nstruct MonoidMin{\n  using value_type = X;\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x,y); }\n  static constexpr X unit()\
    \ { return numeric_limits<X>::max()/2; }\n  static constexpr bool commute = true;\n\
    };\n#line 4 \"algebra/lazy/RangeAddRangeMin.cpp\"\ntemplate<typename X>\nstruct\
    \ LazyRangeAddRangeMin{\n  using MX=MonoidMin<X>;\n  using MF=GroupAdd<X>;\n \
    \ static constexpr X mapping(const X&f,const X&x){\n    return f+x;\n  }\n};\n"
  code: "#pragma once\n#include \"algebra/group/Add.cpp\"\n#include \"algebra/monoid/Min.cpp\"\
    \ntemplate<typename X>\nstruct LazyRangeAddRangeMin{\n  using MX=MonoidMin<X>;\n\
    \  using MF=GroupAdd<X>;\n  static constexpr X mapping(const X&f,const X&x){\n\
    \    return f+x;\n  }\n};"
  dependsOn:
  - algebra/group/Add.cpp
  - algebra/monoid/Min.cpp
  isVerificationFile: false
  path: algebra/lazy/RangeAddRangeMin.cpp
  requiredBy: []
  timestamp: '2022-11-29 20:35:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
documentation_of: algebra/lazy/RangeAddRangeMin.cpp
layout: document
redirect_from:
- /library/algebra/lazy/RangeAddRangeMin.cpp
- /library/algebra/lazy/RangeAddRangeMin.cpp.html
title: algebra/lazy/RangeAddRangeMin.cpp
---

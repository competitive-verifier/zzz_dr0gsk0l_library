---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/Min.cpp
    title: algebra/monoid/Min.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/Set.cpp
    title: algebra/monoid/Set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid/Min.cpp\"\ntemplate<typename X>\nstruct MonoidMin{\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x,y); }\n  static constexpr X unit() { return numeric_limits<X>::max()/2;\
    \ }\n  static constexpr bool commute = true;\n};\n#line 2 \"algebra/monoid/Set.cpp\"\
    \ntemplate<typename X>\nstruct MonoidSet{\n  using O=optional<X>;\n  using value_type=O;\n\
    \  static constexpr O op(const O &x,const O &y)noexcept{ return (x.has_value()?x:y);\
    \ }\n  static constexpr O unit()noexcept{ return nullopt; }\n  static constexpr\
    \ bool commute=false;\n};\n#line 4 \"algebra/lazy/SetMin.cpp\"\ntemplate<typename\
    \ X>\nstruct LazySetMin{\n  using MX=MonoidMin<X>;\n  using MF=MonoidSet<X>;\n\
    \  using F=typename MF::value_type;\n  static constexpr X mapping(const F&f,const\
    \ X&x){\n    return f.value_or(x);\n  }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid/Min.cpp\"\n#include \"algebra/monoid/Set.cpp\"\
    \ntemplate<typename X>\nstruct LazySetMin{\n  using MX=MonoidMin<X>;\n  using\
    \ MF=MonoidSet<X>;\n  using F=typename MF::value_type;\n  static constexpr X mapping(const\
    \ F&f,const X&x){\n    return f.value_or(x);\n  }\n};"
  dependsOn:
  - algebra/monoid/Min.cpp
  - algebra/monoid/Set.cpp
  isVerificationFile: false
  path: algebra/lazy/SetMin.cpp
  requiredBy: []
  timestamp: '2022-11-29 21:38:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
documentation_of: algebra/lazy/SetMin.cpp
layout: document
redirect_from:
- /library/algebra/lazy/SetMin.cpp
- /library/algebra/lazy/SetMin.cpp.html
title: algebra/lazy/SetMin.cpp
---

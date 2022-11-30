---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/AddMin.cpp
    title: algebra/lazy/AddMin.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/SetMin.cpp
    title: algebra/lazy/SetMin.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid/Min.cpp\"\ntemplate<typename X>\nstruct MonoidMin{\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x,y); }\n  static constexpr X unit() { return numeric_limits<X>::max()/2;\
    \ }\n  static constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct MonoidMin{\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x,y); }\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max()/2; }\n  static constexpr\
    \ bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/Min.cpp
  requiredBy:
  - algebra/lazy/SetMin.cpp
  - algebra/lazy/AddMin.cpp
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
documentation_of: algebra/monoid/Min.cpp
layout: document
redirect_from:
- /library/algebra/monoid/Min.cpp
- /library/algebra/monoid/Min.cpp.html
title: algebra/monoid/Min.cpp
---

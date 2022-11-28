---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algebra/lazy/RangeSetRangeMin.cpp
    title: algebra/lazy/RangeSetRangeMin.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
  - algebra/lazy/RangeSetRangeMin.cpp
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
documentation_of: algebra/monoid/Min.cpp
layout: document
redirect_from:
- /library/algebra/monoid/Min.cpp
- /library/algebra/monoid/Min.cpp.html
title: algebra/monoid/Min.cpp
---

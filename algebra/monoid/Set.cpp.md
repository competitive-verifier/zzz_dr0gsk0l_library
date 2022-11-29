---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/RangeSetRangeMin.cpp
    title: algebra/lazy/RangeSetRangeMin.cpp
  - icon: ':x:'
    path: algebra/lazy/RangeSetRangeSum.cpp
    title: algebra/lazy/RangeSetRangeSum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/Set.cpp\"\ntemplate<typename X>\nstruct MonoidSet{\n\
    \  using O=optional<X>;\n  using value_type=O;\n  static constexpr O op(const\
    \ O &x,const O &y)noexcept{ return (x.has_value()?x:y); }\n  static constexpr\
    \ O unit()noexcept{ return nullopt; }\n  static constexpr bool commute=false;\n\
    };\n"
  code: "#pragma once\ntemplate<typename X>\nstruct MonoidSet{\n  using O=optional<X>;\n\
    \  using value_type=O;\n  static constexpr O op(const O &x,const O &y)noexcept{\
    \ return (x.has_value()?x:y); }\n  static constexpr O unit()noexcept{ return nullopt;\
    \ }\n  static constexpr bool commute=false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/Set.cpp
  requiredBy:
  - algebra/lazy/RangeSetRangeMin.cpp
  - algebra/lazy/RangeSetRangeSum.cpp
  timestamp: '2022-11-29 06:44:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
documentation_of: algebra/monoid/Set.cpp
layout: document
redirect_from:
- /library/algebra/monoid/Set.cpp
- /library/algebra/monoid/Set.cpp.html
title: algebra/monoid/Set.cpp
---

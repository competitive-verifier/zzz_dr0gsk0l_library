---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/Reverse.cpp
    title: algebra/Reverse.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/Reverse.cpp\"\ntemplate<typename Algebra>\nstruct\
    \ AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static constexpr\
    \ X op(const X& x, const X& y){ return Algebra::op(y,x); }\n};\n#line 3 \"algebra/lazy/Reverse.cpp\"\
    \ntemplate<typename Lazy>\nstruct LazyReverse:Lazy{\n  using MX=AlgebraReverse<typename\
    \ Lazy::MX>;\n};\n"
  code: "#pragma once\n#include \"algebra/Reverse.cpp\"\ntemplate<typename Lazy>\n\
    struct LazyReverse:Lazy{\n  using MX=AlgebraReverse<typename Lazy::MX>;\n};\n"
  dependsOn:
  - algebra/Reverse.cpp
  isVerificationFile: false
  path: algebra/lazy/Reverse.cpp
  requiredBy: []
  timestamp: '2022-11-30 11:57:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy/Reverse.cpp
layout: document
redirect_from:
- /library/algebra/lazy/Reverse.cpp
- /library/algebra/lazy/Reverse.cpp.html
title: algebra/lazy/Reverse.cpp
---

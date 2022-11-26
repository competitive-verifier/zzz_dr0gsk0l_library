---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/Reverse.cpp\"\ntemplate<typename Algebra>\nstruct\
    \ AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static constexpr\
    \ X op(const X& x, const X& y){ return Algebra::op(y,x); }\n};\n"
  code: "#pragma once\ntemplate<typename Algebra>\nstruct AlgebraReverse:Algebra{\n\
    \  using X=typename Algebra::value_type;\n  static constexpr X op(const X& x,\
    \ const X& y){ return Algebra::op(y,x); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/Reverse.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
documentation_of: algebra/Reverse.cpp
layout: document
redirect_from:
- /library/algebra/Reverse.cpp
- /library/algebra/Reverse.cpp.html
title: algebra/Reverse.cpp
---

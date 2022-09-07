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
  bundledCode: "#line 1 \"algebra/algebra_reverse.cpp\"\ntemplate<typename Algebra>\n\
    struct Algebra_Reverse:Algebra{\n  using X=typename Algebra::value_type;\n  static\
    \ constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n};\n"
  code: "template<typename Algebra>\nstruct Algebra_Reverse:Algebra{\n  using X=typename\
    \ Algebra::value_type;\n  static constexpr X op(const X& x, const X& y){ return\
    \ Algebra::op(y,x); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/algebra_reverse.cpp
  requiredBy: []
  timestamp: '2022-09-07 14:33:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
documentation_of: algebra/algebra_reverse.cpp
layout: document
redirect_from:
- /library/algebra/algebra_reverse.cpp
- /library/algebra/algebra_reverse.cpp.html
title: algebra/algebra_reverse.cpp
---

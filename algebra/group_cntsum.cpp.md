---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_range_affine_range_sum.cpp
    title: algebra/lazy_range_affine_range_sum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_cntsum.cpp\"\ntemplate<typename X>\nstruct\
    \ Group_CntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n  static constexpr\
    \ P op(const P &x, const P &y){\n    return {x.first + y.first, x.second + y.second};\n\
    \  }\n  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }\n  static\
    \ constexpr P unit() { return {0, 0}; }\n  static constexpr bool commute = true;\n\
    };\n"
  code: "template<typename X>\nstruct Group_CntSum{\n  using P=pair<X,X>;\n  using\
    \ value_type=P;\n  static constexpr P op(const P &x, const P &y){\n    return\
    \ {x.first + y.first, x.second + y.second};\n  }\n  static constexpr P inverse(const\
    \ P &x){ return {-x.fi, -x.se}; }\n  static constexpr P unit() { return {0, 0};\
    \ }\n  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_cntsum.cpp
  requiredBy:
  - algebra/lazy_range_affine_range_sum.cpp
  timestamp: '2022-11-25 19:28:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
documentation_of: algebra/group_cntsum.cpp
layout: document
redirect_from:
- /library/algebra/group_cntsum.cpp
- /library/algebra/group_cntsum.cpp.html
title: algebra/group_cntsum.cpp
---

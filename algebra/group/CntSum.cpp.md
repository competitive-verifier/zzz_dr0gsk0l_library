---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy/RangeAffineRangeSum.cpp
    title: algebra/lazy/RangeAffineRangeSum.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group/CntSum.cpp\"\ntemplate<typename X>\nstruct\
    \ GroupCntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n  static constexpr\
    \ P op(const P &x, const P &y){\n    return {x.first + y.first, x.second + y.second};\n\
    \  }\n  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }\n  static\
    \ constexpr P unit() { return {0, 0}; }\n  static constexpr bool commute = true;\n\
    };\n"
  code: "template<typename X>\nstruct GroupCntSum{\n  using P=pair<X,X>;\n  using\
    \ value_type=P;\n  static constexpr P op(const P &x, const P &y){\n    return\
    \ {x.first + y.first, x.second + y.second};\n  }\n  static constexpr P inverse(const\
    \ P &x){ return {-x.fi, -x.se}; }\n  static constexpr P unit() { return {0, 0};\
    \ }\n  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group/CntSum.cpp
  requiredBy:
  - algebra/lazy/RangeAffineRangeSum.cpp
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group/CntSum.cpp
layout: document
redirect_from:
- /library/algebra/group/CntSum.cpp
- /library/algebra/group/CntSum.cpp.html
title: algebra/group/CntSum.cpp
---

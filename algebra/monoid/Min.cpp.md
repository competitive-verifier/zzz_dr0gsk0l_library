---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid/Min.cpp
layout: document
redirect_from:
- /library/algebra/monoid/Min.cpp
- /library/algebra/monoid/Min.cpp.html
title: algebra/monoid/Min.cpp
---

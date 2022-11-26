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
  bundledCode: "#line 1 \"algebra/monoid/Max.cpp\"\ntemplate<typename X>\nstruct MonoidMax{\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x,y); }\n  static constexpr X unit() { return numeric_limits<X>::min()/2;\
    \ }\n  static constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct MonoidMax{\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return max(x,y); }\n  static\
    \ constexpr X unit() { return numeric_limits<X>::min()/2; }\n  static constexpr\
    \ bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/Max.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid/Max.cpp
layout: document
redirect_from:
- /library/algebra/monoid/Max.cpp
- /library/algebra/monoid/Max.cpp.html
title: algebra/monoid/Max.cpp
---

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
  bundledCode: "#line 1 \"algebra/monoid/Gcd.cpp\"\ntemplate<typename X>\nstruct MonoidGcd{\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return gcd(x,y); }\n  static constexpr X unit() { return 0; }\n  static constexpr\
    \ bool commute = true;\n};\n"
  code: "template<typename X>\nstruct MonoidGcd{\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return gcd(x,y); }\n  static\
    \ constexpr X unit() { return 0; }\n  static constexpr bool commute = true;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/Gcd.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid/Gcd.cpp
layout: document
redirect_from:
- /library/algebra/monoid/Gcd.cpp
- /library/algebra/monoid/Gcd.cpp.html
title: algebra/monoid/Gcd.cpp
---

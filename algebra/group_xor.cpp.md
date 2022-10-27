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
  bundledCode: "#line 1 \"algebra/group_xor.cpp\"\ntemplate<typename X>\nstruct Group_Xor\
    \ {\n  using value_type = X;\n  static constexpr X op(const X &x, const X &y)\
    \ noexcept { return x ^ y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return x; }\n  static constexpr X power(const X &x, long long n) noexcept\
    \ { return (n&1?x:0); }\n  static constexpr X unit() { return X(0); }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct Group_Xor {\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x ^ y; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return x; }\n  static constexpr X\
    \ power(const X &x, long long n) noexcept { return (n&1?x:0); }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_xor.cpp
  requiredBy: []
  timestamp: '2022-10-27 21:47:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group_xor.cpp
layout: document
redirect_from:
- /library/algebra/group_xor.cpp
- /library/algebra/group_xor.cpp.html
title: algebra/group_xor.cpp
---

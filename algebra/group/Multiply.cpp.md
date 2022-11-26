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
  bundledCode: "#line 1 \"algebra/group/Multiply.cpp\"\ntemplate<typename X>\nstruct\
    \ GroupMultiply {\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x * y; }\n  static constexpr X inverse(const X\
    \ &x) noexcept { return x.inv(); }\n  static constexpr X power(const X &x, long\
    \ long n) noexcept { return x.pow(n); }\n  static constexpr X unit() { return\
    \ X(1); }\n  static constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct GroupMultiply {\n  using value_type = X;\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return x * y; }\n \
    \ static constexpr X inverse(const X &x) noexcept { return x.inv(); }\n  static\
    \ constexpr X power(const X &x, long long n) noexcept { return x.pow(n); }\n \
    \ static constexpr X unit() { return X(1); }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group/Multiply.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group/Multiply.cpp
layout: document
redirect_from:
- /library/algebra/group/Multiply.cpp
- /library/algebra/group/Multiply.cpp.html
title: algebra/group/Multiply.cpp
---

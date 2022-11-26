---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algebra/lazy/RangeAffineRangeSum.cpp
    title: algebra/lazy/RangeAffineRangeSum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group/Affine.cpp\"\n// op(f,g) = f(g(x))\ntemplate<typename\
    \ K>\nstruct GroupAffine{\n  using F = pair<K, K>;\n  using value_type = F;\n\
    \  static constexpr F op(const F &f, const F &g) noexcept {\n    return F({f.first\
    \ * g.first, f.first * g.second + f.second});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a,\
    \ a * (-b)};\n  }\n  /*\n  static constexpr F power(const F& f,long long n) noexcept\
    \ {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n};\n"
  code: "// op(f,g) = f(g(x))\ntemplate<typename K>\nstruct GroupAffine{\n  using\
    \ F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const F &f,\
    \ const F &g) noexcept {\n    return F({f.first * g.first, f.first * g.second\
    \ + f.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n \
    \ /*\n  static constexpr F power(const F& f,long long n) noexcept {\n    if(a==1)return\
    \ {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n  }\n  */\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept {\n\
    \    return f.first * x + f.second;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group/Affine.cpp
  requiredBy:
  - algebra/lazy/RangeAffineRangeSum.cpp
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
documentation_of: algebra/group/Affine.cpp
layout: document
redirect_from:
- /library/algebra/group/Affine.cpp
- /library/algebra/group/Affine.cpp.html
title: algebra/group/Affine.cpp
---

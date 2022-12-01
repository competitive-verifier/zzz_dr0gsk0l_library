---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group/Affine.cpp
    title: algebra/group/Affine.cpp
  - icon: ':question:'
    path: algebra/group/CntSum.cpp
    title: algebra/group/CntSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group/CntSum.cpp\"\ntemplate<typename X>\nstruct\
    \ GroupCntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n  static constexpr\
    \ P op(const P &x, const P &y){\n    return {x.first + y.first, x.second + y.second};\n\
    \  }\n  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }\n  static\
    \ constexpr P unit() { return {0, 0}; }\n  static constexpr bool commute = true;\n\
    };\ntemplate<typename X>\nvector<pair<X,X>> cnt_init(int n,const X&x){\n  return\
    \ vector<pair<X,X>>(n,{x,1});\n}\ntemplate<typename X>\nvector<pair<X,X>> cnt_init(const\
    \ vector<X>&v){\n  int n=v.size();\n  vector<pair<X,X>> res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n\
    \  return res;\n}\n#line 1 \"algebra/group/Affine.cpp\"\n// op(f,g) = f(g(x))\n\
    template<typename K>\nstruct GroupAffine{\n  using F = pair<K, K>;\n  using value_type\
    \ = F;\n  static constexpr F op(const F &f, const F &g) noexcept {\n    return\
    \ F({f.first * g.first, f.first * g.second + f.second});\n  }\n  static constexpr\
    \ F inverse(const F &x) {\n    auto [a, b] = x; assert(a!=0);\n    a = K(1) /\
    \ a;\n    return {a, a * (-b)};\n  }\n  /*\n  static constexpr F power(const F&\
    \ f,long long n) noexcept {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n\
    \    return {an,b*((1-an)/(1-a))};\n  }\n  */\n  static constexpr F unit() { return\
    \ {K(1), K(0)}; }\n  static constexpr bool commute = false;\n\n  static constexpr\
    \ K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n\
    };\n#line 4 \"algebra/lazy/AffineSum.cpp\"\ntemplate<typename X>\nstruct LazyAffineSum{\n\
    \  using MX=GroupCntSum<X>;\n  using MF=GroupAffine<X>;\n  using P=typename MX::value_type;\n\
    \  using F=typename MF::value_type;\n  static constexpr P mapping(const F&f,const\
    \ P&x){\n    return {f.first*x.first+f.second*x.second, x.second};\n  }\n};\n"
  code: "#pragma once\n#include \"algebra/group/CntSum.cpp\"\n#include \"algebra/group/Affine.cpp\"\
    \ntemplate<typename X>\nstruct LazyAffineSum{\n  using MX=GroupCntSum<X>;\n  using\
    \ MF=GroupAffine<X>;\n  using P=typename MX::value_type;\n  using F=typename MF::value_type;\n\
    \  static constexpr P mapping(const F&f,const P&x){\n    return {f.first*x.first+f.second*x.second,\
    \ x.second};\n  }\n};\n"
  dependsOn:
  - algebra/group/CntSum.cpp
  - algebra/group/Affine.cpp
  isVerificationFile: false
  path: algebra/lazy/AffineSum.cpp
  requiredBy: []
  timestamp: '2022-11-29 21:38:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
documentation_of: algebra/lazy/AffineSum.cpp
layout: document
redirect_from:
- /library/algebra/lazy/AffineSum.cpp
- /library/algebra/lazy/AffineSum.cpp.html
title: algebra/lazy/AffineSum.cpp
---

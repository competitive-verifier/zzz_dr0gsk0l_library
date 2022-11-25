---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group_cntsum.cpp
    title: algebra/group_cntsum.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/group_linear.cpp
    title: algebra/group_linear.cpp
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
  bundledCode: "#line 1 \"algebra/group_cntsum.cpp\"\ntemplate<typename X>\nstruct\
    \ Group_CntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n  static constexpr\
    \ P op(const P &x, const P &y){\n    return {x.first + y.first, x.second + y.second};\n\
    \  }\n  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }\n  static\
    \ constexpr P unit() { return {0, 0}; }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"algebra/group_linear.cpp\"\n// op(f,g) = f(g(x))\ntemplate<typename\
    \ K>\nstruct Group_Affine{\n  using F = pair<K, K>;\n  using value_type = F;\n\
    \  static constexpr F op(const F &f, const F &g) noexcept {\n    return F({f.first\
    \ * g.first, f.first * g.second + f.second});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a,\
    \ a * (-b)};\n  }\n  /*\n  static constexpr F power(const F& f,long long n) noexcept\
    \ {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n};\n#line 3 \"algebra/lazy_range_affine_range_sum.cpp\"\
    \ntemplate<typename X>\nstruct Lazy_Range_Affine_Range_Sum{\n  using MX=Group_CntSum<X>;\n\
    \  using MF=Group_Affine<X>;\n  using P=typename MX::value_type;\n  using F=typename\
    \ MF::value_type;\n  static constexpr P mapping(const F&f,const P&x){\n    return\
    \ {f.first*x.first+f.second*x.second, x.second};\n  }\n};\n"
  code: "#include \"algebra/group_cntsum.cpp\"\n#include \"algebra/group_linear.cpp\"\
    \ntemplate<typename X>\nstruct Lazy_Range_Affine_Range_Sum{\n  using MX=Group_CntSum<X>;\n\
    \  using MF=Group_Affine<X>;\n  using P=typename MX::value_type;\n  using F=typename\
    \ MF::value_type;\n  static constexpr P mapping(const F&f,const P&x){\n    return\
    \ {f.first*x.first+f.second*x.second, x.second};\n  }\n};"
  dependsOn:
  - algebra/group_cntsum.cpp
  - algebra/group_linear.cpp
  isVerificationFile: false
  path: algebra/lazy_range_affine_range_sum.cpp
  requiredBy: []
  timestamp: '2022-11-25 19:28:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
documentation_of: algebra/lazy_range_affine_range_sum.cpp
layout: document
redirect_from:
- /library/algebra/lazy_range_affine_range_sum.cpp
- /library/algebra/lazy_range_affine_range_sum.cpp.html
title: algebra/lazy_range_affine_range_sum.cpp
---

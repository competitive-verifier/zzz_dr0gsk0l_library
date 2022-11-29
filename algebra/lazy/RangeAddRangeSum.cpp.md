---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group/Add.cpp
    title: algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/group/CntSum.cpp
    title: algebra/group/CntSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
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
    \  return res;\n}\n#line 2 \"algebra/group/Add.cpp\"\ntemplate<typename X>\nstruct\
    \ GroupAdd {\n  using value_type = X;\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, long long n) noexcept\
    \ { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static\
    \ constexpr bool commute = true;\n};\n#line 4 \"algebra/lazy/RangeAddRangeSum.cpp\"\
    \ntemplate<typename X>\nstruct LazyRangeAddRangeSum{\n  using MX=GroupCntSum<X>;\n\
    \  using MF=GroupAdd<X>;\n  using S=typename MX::value_type;\n  static constexpr\
    \ S mapping(const X&f,const S&x){\n    return {x.first+f*x.second,x.second};\n\
    \  }\n};\n"
  code: "#pragma once\n#include \"algebra/group/CntSum.cpp\"\n#include \"algebra/group/Add.cpp\"\
    \ntemplate<typename X>\nstruct LazyRangeAddRangeSum{\n  using MX=GroupCntSum<X>;\n\
    \  using MF=GroupAdd<X>;\n  using S=typename MX::value_type;\n  static constexpr\
    \ S mapping(const X&f,const S&x){\n    return {x.first+f*x.second,x.second};\n\
    \  }\n};"
  dependsOn:
  - algebra/group/CntSum.cpp
  - algebra/group/Add.cpp
  isVerificationFile: false
  path: algebra/lazy/RangeAddRangeSum.cpp
  requiredBy: []
  timestamp: '2022-11-29 20:41:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_G.test.cpp
documentation_of: algebra/lazy/RangeAddRangeSum.cpp
layout: document
redirect_from:
- /library/algebra/lazy/RangeAddRangeSum.cpp
- /library/algebra/lazy/RangeAddRangeSum.cpp.html
title: algebra/lazy/RangeAddRangeSum.cpp
---

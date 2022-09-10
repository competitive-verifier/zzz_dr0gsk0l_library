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
  bundledCode: "#line 1 \"bitwise/convolution.cpp\"\n/*\nZETA,LOWER [S]: sum T\u2286\
    S v[T]\nZETA,UPPER [S]: sum T\u2287S v[T]\nMOEBIUS,LOWER [S]: sum T\u2286S (-1)^(|S\\\
    T|) v[T]\nMOEBIUS,LOWER [S]: sum T\u2286S (-1)^(|T\\S|) v[T] \n*/\n\n#define REP_(i,n)\
    \ for(int i=0;i<(n);i++)\nenum Query_Type{\n  ZETA = 1;\n  MOEBIUS = -1;\n  LOWER\
    \ = true;\n  UPPER = false;\n};\ntemplate<typename T>\nvector<T> bitwise_convolution(vector<T>\
    \ v,Query_Type q1,Query_Type q2){\n  int n=__builtin_ctz(int(v.size()));\n  REP_(k,n)REP_(S,1<<n)if(q2\
    \ ^ ((S>>k)&1))v[S]+=q1*v[S^(1<<k)];\n  return v;\n}\n#undef REP_\n"
  code: "/*\nZETA,LOWER [S]: sum T\u2286S v[T]\nZETA,UPPER [S]: sum T\u2287S v[T]\n\
    MOEBIUS,LOWER [S]: sum T\u2286S (-1)^(|S\\T|) v[T]\nMOEBIUS,LOWER [S]: sum T\u2286\
    S (-1)^(|T\\S|) v[T] \n*/\n\n#define REP_(i,n) for(int i=0;i<(n);i++)\nenum Query_Type{\n\
    \  ZETA = 1;\n  MOEBIUS = -1;\n  LOWER = true;\n  UPPER = false;\n};\ntemplate<typename\
    \ T>\nvector<T> bitwise_convolution(vector<T> v,Query_Type q1,Query_Type q2){\n\
    \  int n=__builtin_ctz(int(v.size()));\n  REP_(k,n)REP_(S,1<<n)if(q2 ^ ((S>>k)&1))v[S]+=q1*v[S^(1<<k)];\n\
    \  return v;\n}\n#undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: bitwise/convolution.cpp
  requiredBy: []
  timestamp: '2022-09-10 18:21:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bitwise/convolution.cpp
layout: document
redirect_from:
- /library/bitwise/convolution.cpp
- /library/bitwise/convolution.cpp.html
title: bitwise/convolution.cpp
---

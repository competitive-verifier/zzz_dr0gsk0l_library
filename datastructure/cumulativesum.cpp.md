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
  bundledCode: "#line 1 \"datastructure/cumulativesum.cpp\"\ntemplate<typename T>\n\
    struct CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long long,T >;\n\
    \  vector<U> A;\n  CumulativeSum():A(1,0){}\n  CumulativeSum(const vector<T>&v):A(v.size()+1,0){\n\
    \    for(int i=0;i<v.size();i++)A[i+1]=A[i]+v[i];\n  }\n  void add(const T&a){\
    \ A.push_back(A.back()+a); }\n  U sum(int l,int r){ return A[r]-A[l]; }\n  U sum(){\
    \ return A.back(); }\n};\n"
  code: "template<typename T>\nstruct CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T >;\n  vector<U> A;\n  CumulativeSum():A(1,0){}\n  CumulativeSum(const\
    \ vector<T>&v):A(v.size()+1,0){\n    for(int i=0;i<v.size();i++)A[i+1]=A[i]+v[i];\n\
    \  }\n  void add(const T&a){ A.push_back(A.back()+a); }\n  U sum(int l,int r){\
    \ return A[r]-A[l]; }\n  U sum(){ return A.back(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulativesum.cpp
  requiredBy: []
  timestamp: '2022-10-27 21:47:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/cumulativesum.cpp
layout: document
redirect_from:
- /library/datastructure/cumulativesum.cpp
- /library/datastructure/cumulativesum.cpp.html
title: datastructure/cumulativesum.cpp
---

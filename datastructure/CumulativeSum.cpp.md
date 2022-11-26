---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
    title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/CumulativeSum.cpp\"\ntemplate<typename T>\n\
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
  path: datastructure/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:34:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/StaticRangeSum.test.cpp
documentation_of: datastructure/CumulativeSum.cpp
layout: document
redirect_from:
- /library/datastructure/CumulativeSum.cpp
- /library/datastructure/CumulativeSum.cpp.html
title: datastructure/CumulativeSum.cpp
---

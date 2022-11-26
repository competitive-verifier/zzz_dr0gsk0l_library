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
  bundledCode: "#line 1 \"datastructure/2D/CumulativeSum.cpp\"\ntemplate<typename\
    \ T>\nclass CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long long,T\
    \ >;\n  int h,w;\n  vector<vector<U>> A;\n  bool prepared;\npublic:\n  CumulativeSum(int\
    \ h=0,int w=0):h(h),w(w),A(h+1,vector<U>(w+1,0)),prepared(false){}\n  CumulativeSum(const\
    \ vector<vector<T>>&v):h(v.size()),w(v[0].size()),A(h+1,vector<U>(w+1,0)),prepared(false){\n\
    \    for(int i=0;i<h;i++)for(int j=0;j<w;j++)A[i+1][j+1]=v[i][j];\n    build();\n\
    \  }\n  void add(int y,int x,const T&val=1){\n    assert(!prepared);\n    assert(0<=y\
    \ and y<h and 0<=x and x<w);\n    A[y+1][x+1]+=val;\n  }\n  void build(){\n  \
    \  assert(!prepared);prepared=true;\n    for(int i=0;i<h;i++)for(int j=0;j<=w;j++)A[i+1][j]+=A[i][j];\n\
    \    for(int i=0;i<=h;i++)for(int j=0;j<w;j++)A[i][j+1]+=A[i][j];\n  }\n  U sum(int\
    \ u,int d,int l,int r){\n    assert(prepared);\n    assert(0<=u and u<=d and u<=h);\n\
    \    assert(0<=l and l<=r and r<=w);\n    return A[d][r]-A[d][l]-A[u][r]+A[u][l];\n\
    \  }\n  U sum(){\n    assert(prepared);\n    return A.back().back();\n  }\n};\n"
  code: "template<typename T>\nclass CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T >;\n  int h,w;\n  vector<vector<U>> A;\n  bool prepared;\npublic:\n \
    \ CumulativeSum(int h=0,int w=0):h(h),w(w),A(h+1,vector<U>(w+1,0)),prepared(false){}\n\
    \  CumulativeSum(const vector<vector<T>>&v):h(v.size()),w(v[0].size()),A(h+1,vector<U>(w+1,0)),prepared(false){\n\
    \    for(int i=0;i<h;i++)for(int j=0;j<w;j++)A[i+1][j+1]=v[i][j];\n    build();\n\
    \  }\n  void add(int y,int x,const T&val=1){\n    assert(!prepared);\n    assert(0<=y\
    \ and y<h and 0<=x and x<w);\n    A[y+1][x+1]+=val;\n  }\n  void build(){\n  \
    \  assert(!prepared);prepared=true;\n    for(int i=0;i<h;i++)for(int j=0;j<=w;j++)A[i+1][j]+=A[i][j];\n\
    \    for(int i=0;i<=h;i++)for(int j=0;j<w;j++)A[i][j+1]+=A[i][j];\n  }\n  U sum(int\
    \ u,int d,int l,int r){\n    assert(prepared);\n    assert(0<=u and u<=d and u<=h);\n\
    \    assert(0<=l and l<=r and r<=w);\n    return A[d][r]-A[d][l]-A[u][r]+A[u][l];\n\
    \  }\n  U sum(){\n    assert(prepared);\n    return A.back().back();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/2D/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:34:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/2D/CumulativeSum.cpp
layout: document
redirect_from:
- /library/datastructure/2D/CumulativeSum.cpp
- /library/datastructure/2D/CumulativeSum.cpp.html
title: datastructure/2D/CumulativeSum.cpp
---

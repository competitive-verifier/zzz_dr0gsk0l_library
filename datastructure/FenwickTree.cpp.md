---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/FenwickTree.cpp\"\ntemplate<typename AbelGroup>\n\
    class FenwickTree{\n  using T=typename AbelGroup::value_type;\n  int n;\n  vector<T>\
    \ dat,raw;\n  void chop(T&a,T b){ a=AbelGroup::op(a,b); }\npublic:\n  FenwickTree(){\n\
    \    assert(AbelGroup::commute);\n  }\n  FenwickTree(int n):n(n){\n    assert(AbelGroup::commute);\n\
    \    dat=raw=vector<T>(n,AbelGroup::unit());\n  }\n  FenwickTree(const vector<T>&v):n(v.size()),raw(v),dat(v){\n\
    \    assert(AbelGroup::commute);\n    for(int i=1;i<=n;i++){\n      int j=i+(i&-i);\n\
    \      if(j<=n)chop(dat[j-1],dat[i-1]);\n    }\n  }\n\n  T operator[](int k)const{\
    \ return raw[k]; }\n\n  void set(int k,const T&x){\n    T diff=AbelGroup::op(x,AbelGroup::inverse(raw[k]));\n\
    \    raw[k]=x;\n    for(++k;k<=n;k+=k&-k)chop(dat[k-1],diff);\n  }\n  void multiply(int\
    \ k,const T&x){\n    chop(raw[k],x);\n    for(++k;k<=n;k+=k&-k)chop(dat[k-1],x);\n\
    \  }\n\n  T prod(int k){\n    T res=AbelGroup::unit();\n    while(k>0){\n    \
    \  chop(res, dat[k-1]);\n      k -= k&-k;\n    }\n    return res;\n  }\n  T prod(int\
    \ L,int R){\n    T pos=AbelGroup::unit();\n    while(L<R){\n      chop(pos,dat[R-1]);\n\
    \      R -= R&-R;\n    }\n    T neg=AbelGroup::unit();\n    while(R<L){\n    \
    \  chop(neg, dat[L - 1]);\n      L -= L&-L;\n    }\n    chop(pos,AbelGroup::inverse(neg));\n\
    \    return pos;\n  }\n};\n"
  code: "#pragma once\ntemplate<typename AbelGroup>\nclass FenwickTree{\n  using T=typename\
    \ AbelGroup::value_type;\n  int n;\n  vector<T> dat,raw;\n  void chop(T&a,T b){\
    \ a=AbelGroup::op(a,b); }\npublic:\n  FenwickTree(){\n    assert(AbelGroup::commute);\n\
    \  }\n  FenwickTree(int n):n(n){\n    assert(AbelGroup::commute);\n    dat=raw=vector<T>(n,AbelGroup::unit());\n\
    \  }\n  FenwickTree(const vector<T>&v):n(v.size()),raw(v),dat(v){\n    assert(AbelGroup::commute);\n\
    \    for(int i=1;i<=n;i++){\n      int j=i+(i&-i);\n      if(j<=n)chop(dat[j-1],dat[i-1]);\n\
    \    }\n  }\n\n  T operator[](int k)const{ return raw[k]; }\n\n  void set(int\
    \ k,const T&x){\n    T diff=AbelGroup::op(x,AbelGroup::inverse(raw[k]));\n   \
    \ raw[k]=x;\n    for(++k;k<=n;k+=k&-k)chop(dat[k-1],diff);\n  }\n  void multiply(int\
    \ k,const T&x){\n    chop(raw[k],x);\n    for(++k;k<=n;k+=k&-k)chop(dat[k-1],x);\n\
    \  }\n\n  T prod(int k){\n    T res=AbelGroup::unit();\n    while(k>0){\n    \
    \  chop(res, dat[k-1]);\n      k -= k&-k;\n    }\n    return res;\n  }\n  T prod(int\
    \ L,int R){\n    T pos=AbelGroup::unit();\n    while(L<R){\n      chop(pos,dat[R-1]);\n\
    \      R -= R&-R;\n    }\n    T neg=AbelGroup::unit();\n    while(R<L){\n    \
    \  chop(neg, dat[L - 1]);\n      L -= L&-L;\n    }\n    chop(pos,AbelGroup::inverse(neg));\n\
    \    return pos;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/FenwickTree.cpp
  requiredBy: []
  timestamp: '2022-12-02 21:17:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_B.test.cpp
documentation_of: datastructure/FenwickTree.cpp
layout: document
redirect_from:
- /library/datastructure/FenwickTree.cpp
- /library/datastructure/FenwickTree.cpp.html
title: datastructure/FenwickTree.cpp
---

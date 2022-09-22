---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: util/compress.cpp
    title: util/compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/inversion_number.cpp\"\n#include <atcoder/fenwicktree>\n\
    using namespace atcoder;\n\n#line 1 \"util/compress.cpp\"\ntemplate<typename T>\n\
    struct Compress{\n  map<T,int> mp;\n  vector<T> rev;\n\n  Compress()=default;\n\
    \  Compress(const vector<T>&v,bool banpei=false){\n    for(const T&a:v)mp[a];\n\
    \    if(banpei)mp[numeric_limits<T>::max()],mp[numeric_limits<T>::min()];\n  \
    \  build();\n  }\n  \n  void add(T a){ mp[a]; }\n  void build(){\n    int cnt=0;\n\
    \    rev.resize(mp.size());\n    for(auto&[val,id]:mp){\n      rev[cnt]=val;\n\
    \      id=cnt++;\n    }\n  }\n\n  int operator[](T a)const{return mp.at(a);}\n\
    \  int geq(T a)const{return mp.lower_bound(a)->second;}\n  int leq(T a)const{return\
    \ (--mp.upper_bound(a))->second;}\n  int gt(T a)const{return mp.upper_bound(a)->second;}\n\
    \  int lt(T a)const{return (--mp.lower_bound(a))->second;}\n\n  T r(int id)const{return\
    \ rev[id];}\n\n  int size()const{return mp.size();}\n};\n#line 5 \"util/inversion_number.cpp\"\
    \n\ntemplate <typename T>\nlong long inversion_number(const vector<T> &v){\n \
    \ Compress cmp(v);\n  fenwick_tree<int> ft(cmp.size());\n  long long res=0;\n\
    \  for(int i=int(v.size())-1;i>=0;i--){\n    int j=cmp[v[i]];\n    res+=ft.sum(0,j);\n\
    \    ft.add(j,1);\n  }\n  return res;\n}\n"
  code: "#include <atcoder/fenwicktree>\nusing namespace atcoder;\n\n#include \"util/compress.cpp\"\
    \n\ntemplate <typename T>\nlong long inversion_number(const vector<T> &v){\n \
    \ Compress cmp(v);\n  fenwick_tree<int> ft(cmp.size());\n  long long res=0;\n\
    \  for(int i=int(v.size())-1;i>=0;i--){\n    int j=cmp[v[i]];\n    res+=ft.sum(0,j);\n\
    \    ft.add(j,1);\n  }\n  return res;\n}"
  dependsOn:
  - util/compress.cpp
  isVerificationFile: false
  path: util/inversion_number.cpp
  requiredBy: []
  timestamp: '2022-09-22 11:37:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: util/inversion_number.cpp
layout: document
redirect_from:
- /library/util/inversion_number.cpp
- /library/util/inversion_number.cpp.html
title: util/inversion_number.cpp
---

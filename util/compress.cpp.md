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
  bundledCode: "#line 1 \"util/compress.cpp\"\ntemplate<typename T>\nstruct Compress{\n\
    \  map<T,int> mp;\n  vector<T> rev;\n\n  Compress()=default;\n  Compress(const\
    \ vector<T>&v,bool banpei=false){\n    for(const T&a:v)mp[a];\n    if(banpei)mp[numeric_limits<T>::max()],mp[numeric_limits<T>::min()];\n\
    \    build();\n  }\n  \n  void add(T a){ mp[a]; }\n  void build(){\n    int cnt=0;\n\
    \    rev.resize(mp.size());\n    for(auto&[val,id]:mp){\n      rev[cnt]=val;\n\
    \      id=cnt++;\n    }\n  }\n\n  int operator[](T a)const{return mp.at(a);}\n\
    \  int geq(T a)const{return mp.lower_bound(a)->second;}\n  int leq(T a)const{return\
    \ (--mp.upper_bound(a))->second;}\n  int gt(T a)const{return mp.upper_bound(a)->second;}\n\
    \  int lt(T a)const{return (--mp.lower_bound(a))->second;}\n\n  T r(int id)const{return\
    \ rev[id];}\n\n  int size()const{return mp.size();}\n};\n"
  code: "template<typename T>\nstruct Compress{\n  map<T,int> mp;\n  vector<T> rev;\n\
    \n  Compress()=default;\n  Compress(const vector<T>&v,bool banpei=false){\n  \
    \  for(const T&a:v)mp[a];\n    if(banpei)mp[numeric_limits<T>::max()],mp[numeric_limits<T>::min()];\n\
    \    build();\n  }\n  \n  void add(T a){ mp[a]; }\n  void build(){\n    int cnt=0;\n\
    \    rev.resize(mp.size());\n    for(auto&[val,id]:mp){\n      rev[cnt]=val;\n\
    \      id=cnt++;\n    }\n  }\n\n  int operator[](T a)const{return mp.at(a);}\n\
    \  int geq(T a)const{return mp.lower_bound(a)->second;}\n  int leq(T a)const{return\
    \ (--mp.upper_bound(a))->second;}\n  int gt(T a)const{return mp.upper_bound(a)->second;}\n\
    \  int lt(T a)const{return (--mp.lower_bound(a))->second;}\n\n  T r(int id)const{return\
    \ rev[id];}\n\n  int size()const{return mp.size();}\n};"
  dependsOn: []
  isVerificationFile: false
  path: util/compress.cpp
  requiredBy: []
  timestamp: '2022-09-22 11:37:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/compress.cpp
layout: document
redirect_from:
- /library/util/compress.cpp
- /library/util/compress.cpp.html
title: util/compress.cpp
---

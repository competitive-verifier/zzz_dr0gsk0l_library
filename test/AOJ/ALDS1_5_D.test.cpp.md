---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: util/compress.cpp
    title: util/compress.cpp
  - icon: ':heavy_check_mark:'
    path: util/inversion_number.cpp
    title: util/inversion_number.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
  bundledCode: "#line 1 \"test/AOJ/ALDS1_5_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"util/inversion_number.cpp\"\
    \n#include <atcoder/fenwicktree>\nusing namespace atcoder;\n\n#line 1 \"util/compress.cpp\"\
    \ntemplate<typename T>\nstruct Compress{\n  map<T,int> mp;\n  vector<T> rev;\n\
    \n  Compress()=default;\n  Compress(const vector<T>&v,bool banpei=false){\n  \
    \  for(const T&a:v)mp[a];\n    if(banpei)mp[numeric_limits<T>::max()],mp[numeric_limits<T>::min()];\n\
    \    build();\n  }\n  \n  void add(T a){ mp[a]; }\n  void build(){\n    int cnt=0;\n\
    \    rev.resize(mp.size());\n    for(auto&[val,id]:mp){\n      rev[cnt]=val;\n\
    \      id=cnt++;\n    }\n  }\n\n  int operator[](T a)const{return mp.at(a);}\n\
    \  int geq(T a)const{return mp.lower_bound(a)->second;}\n  int leq(T a)const{return\
    \ (--mp.upper_bound(a))->second;}\n  int gt(T a)const{return mp.upper_bound(a)->second;}\n\
    \  int lt(T a)const{return (--mp.lower_bound(a))->second;}\n\n  T r(int id)const{return\
    \ rev[id];}\n\n  int size()const{return mp.size();}\n};\n#line 5 \"util/inversion_number.cpp\"\
    \n\ntemplate <typename T>\nlong long inversion_number(const vector<T> &v){\n \
    \ Compress cmp(v);\n  fenwick_tree<int> ft(cmp.size());\n  long long res=0;\n\
    \  for(int i=int(v.size())-1;i>=0;i--){\n    int j=cmp[v[i]];\n    res+=ft.sum(0,j);\n\
    \    ft.add(j,1);\n  }\n  return res;\n}\n#line 6 \"test/AOJ/ALDS1_5_D.test.cpp\"\
    \n\nint main(){\n  int n;cin>>n;\n  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  cout<<inversion_number(v)<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"util/inversion_number.cpp\"\
    \n\nint main(){\n  int n;cin>>n;\n  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  cout<<inversion_number(v)<<endl;\n}"
  dependsOn:
  - util/inversion_number.cpp
  - util/compress.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2022-09-22 11:37:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_5_D.test.cpp
- /verify/test/AOJ/ALDS1_5_D.test.cpp.html
title: test/AOJ/ALDS1_5_D.test.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/BellmanFord.cpp\"\ntemplate<typename WG,typename T=typename\
    \ WG::weight_type>\noptional<pair<vector<T>,vector<int>>> bellman_ford(const WG&g,int\
    \ s=0){\n  int n=g.n;\n  static constexpr T INF=numeric_limits<T>::max()/2;\n\
    \  vector<T> d(n,INF);\n  vector<int> pre(n,-1);\n  d[s]=0;\n  while(n--)\n  \
    \  for(const auto&e:g.edges)\n      if(d[e.to]>d[e.from]+e.weight){\n        if(!n)return\
    \ nullopt;\n        d[e.to]=d[e.from]+e.weight;\n        pre[e.to]=e.from;\n \
    \     }\n  return make_pair(d,pre);\n}\n"
  code: "template<typename WG,typename T=typename WG::weight_type>\noptional<pair<vector<T>,vector<int>>>\
    \ bellman_ford(const WG&g,int s=0){\n  int n=g.n;\n  static constexpr T INF=numeric_limits<T>::max()/2;\n\
    \  vector<T> d(n,INF);\n  vector<int> pre(n,-1);\n  d[s]=0;\n  while(n--)\n  \
    \  for(const auto&e:g.edges)\n      if(d[e.to]>d[e.from]+e.weight){\n        if(!n)return\
    \ nullopt;\n        d[e.to]=d[e.from]+e.weight;\n        pre[e.to]=e.from;\n \
    \     }\n  return make_pair(d,pre);\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2022-12-01 19:31:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
documentation_of: graph/BellmanFord.cpp
layout: document
redirect_from:
- /library/graph/BellmanFord.cpp
- /library/graph/BellmanFord.cpp.html
title: graph/BellmanFord.cpp
---

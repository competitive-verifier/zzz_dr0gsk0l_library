---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/ShortestPath.test.cpp
    title: test/library-checker/ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\ntemplate<typename T>\nusing pqg=priority_queue<T,vector<T>,greater<T>>;\n\
    \ntemplate<typename T>\npair<vector<T>,vector<int>> dijkstra(const WeightedGraph<T>\
    \ &g,int s=0){\n  int n=g.size();\n  vector<T> d(n,-1);\n  vector<int> pre(n,-1);\n\
    \  pqg< pair<T,int> > que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n\
    \    auto [now,id]=que.top();que.pop();\n    if(d[id]<now)continue;\n    for(const\
    \ auto&[to,co]:g[id])\n      if(d[to]==-1 || d[to]>now+co){\n        d[to]=now+co;\n\
    \        pre[to]=id;\n        que.emplace(d[to],to);\n      }\n  }\n  return {d,pre};\n\
    }\n"
  code: "template<typename T>\nusing pqg=priority_queue<T,vector<T>,greater<T>>;\n\
    \ntemplate<typename T>\npair<vector<T>,vector<int>> dijkstra(const WeightedGraph<T>\
    \ &g,int s=0){\n  int n=g.size();\n  vector<T> d(n,-1);\n  vector<int> pre(n,-1);\n\
    \  pqg< pair<T,int> > que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n\
    \    auto [now,id]=que.top();que.pop();\n    if(d[id]<now)continue;\n    for(const\
    \ auto&[to,co]:g[id])\n      if(d[to]==-1 || d[to]>now+co){\n        d[to]=now+co;\n\
    \        pre[to]=id;\n        que.emplace(d[to],to);\n      }\n  }\n  return {d,pre};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2022-09-22 12:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/ShortestPath.test.cpp
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/ShortestPath.test.cpp
    title: test/library-checker/Graph/ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Dijkstra.cpp\"\ntemplate<typename WG,typename T=typename\
    \ WG::weight_type>\npair<vector<T>,vector<int>> dijkstra(WG&g,int s=0){\n  assert(g.is_prepared());\n\
    \  vector<T> d(g.n,-1);\n  vector<int> pre(g.n,-1);\n  priority_queue< pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(const auto&e:g[id])\n      if(d[e.to]==-1\
    \ || d[e.to]>now+e.weight){\n        d[e.to]=now+e.weight;\n        pre[e.to]=id;\n\
    \        que.emplace(d[e.to],e.to);\n      }\n  }\n  return {d,pre};\n}\n"
  code: "template<typename WG,typename T=typename WG::weight_type>\npair<vector<T>,vector<int>>\
    \ dijkstra(WG&g,int s=0){\n  assert(g.is_prepared());\n  vector<T> d(g.n,-1);\n\
    \  vector<int> pre(g.n,-1);\n  priority_queue< pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(const auto&e:g[id])\n      if(d[e.to]==-1\
    \ || d[e.to]>now+e.weight){\n        d[e.to]=now+e.weight;\n        pre[e.to]=id;\n\
    \        que.emplace(d[e.to],e.to);\n      }\n  }\n  return {d,pre};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2022-12-01 19:31:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/ShortestPath.test.cpp
documentation_of: graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/graph/Dijkstra.cpp
- /library/graph/Dijkstra.cpp.html
title: graph/Dijkstra.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: graph/dijkstra.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/library-checker/ShortestPath.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"graph/WeightedGraph.cpp\"\ntemplate<typename\
    \ T>\nstruct Edge{\n  int to;\n  T cost;\n  Edge()=default;\n  Edge(int to,T cost):to(to),cost(cost){}\n\
    };\n\ntemplate<typename T>\nstruct WeightedGraph:vector<vector<Edge<T>>>{\n  using\
    \ vector<vector<Edge<T>>>::resize;\n  using vector<vector<Edge<T>>>::at;\n\n \
    \ using cost_type=T;\n  using edge_type=Edge<T>;\n\n  WeightedGraph(){}\n  WeightedGraph(int\
    \ n){ resize(n); }\n  WeightedGraph(int n,int m,bool directed=false,int index=1){\n\
    \    resize(n);\n    while(m--){\n      int from,to;T cost;cin>>from>>to>>cost;\n\
    \      if(directed)add_arc(from-index,to-index,cost);\n      else add_edge(from-index,to-index,cost);\n\
    \    }\n  }\n\n  void add_arc(int from,int to,T cost){\n    at(from).emplace_back(to,cost);\n\
    \  }\n\n  void add_edge(int u,int v,T cost){\n    add_arc(u,v,cost);\n    add_arc(v,u,cost);\n\
    \  }\n};\n#line 1 \"graph/dijkstra.cpp\"\ntemplate<typename T>\nusing pqg=priority_queue<T,vector<T>,greater<T>>;\n\
    \ntemplate<typename T>\npair<vector<T>,vector<int>> dijkstra(const WeightedGraph<T>\
    \ &g,int s=0){\n  int n=g.size();\n  vector<T> d(n,-1);\n  vector<int> pre(n,-1);\n\
    \  pqg< pair<T,int> > que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n\
    \    auto [now,id]=que.top();que.pop();\n    if(d[id]<now)continue;\n    for(const\
    \ auto&[to,co]:g[id])\n      if(d[to]==-1 || d[to]>now+co){\n        d[to]=now+co;\n\
    \        pre[to]=id;\n        que.emplace(d[to],to);\n      }\n  }\n  return {d,pre};\n\
    }\n#line 7 \"test/library-checker/ShortestPath.test.cpp\"\n\nusing ll=long long;\n\
    \nint main(){\n  int n,m,s,t;cin>>n>>m>>s>>t;\n  WeightedGraph<ll> g(n,m,true,0);\n\
    \  auto [d,pre]=dijkstra(g,s);\n\n  cout<<d[t];\n  if(d[t]<0){\n    cout<<\"\\\
    n\";\n    return 0;\n  }\n\n  vector<pair<int,int>> ans;\n  while(t!=s){\n   \
    \ ans.emplace_back(pre[t],t);\n    t=pre[t];\n  }\n  reverse(ans.begin(),ans.end());\n\
    \  cout<<\" \"<<ans.size()<<\"\\n\";\n  for(const auto&[from,to]:ans)cout<<from<<\"\
    \ \"<<to<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/WeightedGraph.cpp\"\
    \n#include \"graph/dijkstra.cpp\"\n\nusing ll=long long;\n\nint main(){\n  int\
    \ n,m,s,t;cin>>n>>m>>s>>t;\n  WeightedGraph<ll> g(n,m,true,0);\n  auto [d,pre]=dijkstra(g,s);\n\
    \n  cout<<d[t];\n  if(d[t]<0){\n    cout<<\"\\n\";\n    return 0;\n  }\n\n  vector<pair<int,int>>\
    \ ans;\n  while(t!=s){\n    ans.emplace_back(pre[t],t);\n    t=pre[t];\n  }\n\
    \  reverse(ans.begin(),ans.end());\n  cout<<\" \"<<ans.size()<<\"\\n\";\n  for(const\
    \ auto&[from,to]:ans)cout<<from<<\" \"<<to<<\"\\n\";\n}"
  dependsOn:
  - graph/WeightedGraph.cpp
  - graph/dijkstra.cpp
  isVerificationFile: true
  path: test/library-checker/ShortestPath.test.cpp
  requiredBy: []
  timestamp: '2022-09-22 12:20:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/ShortestPath.test.cpp
- /verify/test/library-checker/ShortestPath.test.cpp.html
title: test/library-checker/ShortestPath.test.cpp
---

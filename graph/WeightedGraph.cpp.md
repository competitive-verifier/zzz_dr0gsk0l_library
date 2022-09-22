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
  bundledCode: "#line 1 \"graph/WeightedGraph.cpp\"\ntemplate<typename T>\nstruct\
    \ Edge{\n  int to;\n  T cost;\n  Edge()=default;\n  Edge(int to,T cost):to(to),cost(cost){}\n\
    };\n\ntemplate<typename T>\nstruct WeightedGraph:vector<vector<Edge<T>>>{\n  using\
    \ vector<vector<Edge<T>>>::resize;\n  using vector<vector<Edge<T>>>::at;\n\n \
    \ using cost_type=T;\n  using edge_type=Edge<T>;\n\n  WeightedGraph(){}\n  WeightedGraph(int\
    \ n){ resize(n); }\n  WeightedGraph(int n,int m,bool directed=false,int index=1){\n\
    \    resize(n);\n    while(m--){\n      int from,to;T cost;cin>>from>>to>>cost;\n\
    \      if(directed)add_arc(from-index,to-index,cost);\n      else add_edge(from-index,to-index,cost);\n\
    \    }\n  }\n\n  void add_arc(int from,int to,T cost){\n    at(from).emplace_back(to,cost);\n\
    \  }\n\n  void add_edge(int u,int v,T cost){\n    add_arc(u,v,cost);\n    add_arc(v,u,cost);\n\
    \  }\n};\n"
  code: "template<typename T>\nstruct Edge{\n  int to;\n  T cost;\n  Edge()=default;\n\
    \  Edge(int to,T cost):to(to),cost(cost){}\n};\n\ntemplate<typename T>\nstruct\
    \ WeightedGraph:vector<vector<Edge<T>>>{\n  using vector<vector<Edge<T>>>::resize;\n\
    \  using vector<vector<Edge<T>>>::at;\n\n  using cost_type=T;\n  using edge_type=Edge<T>;\n\
    \n  WeightedGraph(){}\n  WeightedGraph(int n){ resize(n); }\n  WeightedGraph(int\
    \ n,int m,bool directed=false,int index=1){\n    resize(n);\n    while(m--){\n\
    \      int from,to;T cost;cin>>from>>to>>cost;\n      if(directed)add_arc(from-index,to-index,cost);\n\
    \      else add_edge(from-index,to-index,cost);\n    }\n  }\n\n  void add_arc(int\
    \ from,int to,T cost){\n    at(from).emplace_back(to,cost);\n  }\n\n  void add_edge(int\
    \ u,int v,T cost){\n    add_arc(u,v,cost);\n    add_arc(v,u,cost);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/WeightedGraph.cpp
  requiredBy: []
  timestamp: '2022-09-22 12:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/ShortestPath.test.cpp
documentation_of: graph/WeightedGraph.cpp
layout: document
redirect_from:
- /library/graph/WeightedGraph.cpp
- /library/graph/WeightedGraph.cpp.html
title: graph/WeightedGraph.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/Dinic.cpp
    title: flow/Dinic.cpp
  - icon: ':heavy_check_mark:'
    path: flow/MCF.cpp
    title: flow/MCF.cpp
  - icon: ':warning:'
    path: graph/01BFS.cpp
    title: graph/01BFS.cpp
  - icon: ':heavy_check_mark:'
    path: graph/Dijkstra.cpp
    title: graph/Dijkstra.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_B.test.cpp
    title: test/AOJ/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/ShortestPath.test.cpp
    title: test/library-checker/Graph/ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/WeightedGraph.cpp\"\ntemplate<typename T>\nstruct\
    \ WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int from,int to,T cost):from(from),to(to),cost(cost){}\n\
    \  int from,to;\n  T cost;\n};\n\ntemplate<typename T>\nstruct WeightedGraph{\n\
    \  int n;\n  using cost_type=T;\n  using edge_type=WeightedEdge<T>;\n  vector<edge_type>\
    \ edges;\nprivate:\n  vector<int> in_deg;\n  bool prepared;\n  class OutgoingEdges{\n\
    \    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]);\
    \ }\n    edge_type* end(){ return &(g->edges[r]); }\n    edge_type& operator[](int\
    \ i){ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\npublic:\n\
    \  OutgoingEdges operator[](int v){\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1]\
    \ };\n  }\n\n  bool is_prepared()const{ return prepared; }\n\n  WeightedGraph():n(0),in_deg(1,0),prepared(false){}\n\
    \  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  WeightedGraph(int\
    \ n,int m,bool directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){\
    \ scan(m,directed,indexed); }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int\
    \ from,int to,T cost){\n    assert(!prepared);\n    assert(0<=from and from<n\
    \ and 0<=to and to<n);\n    edges.emplace_back(from,to,cost);\n    in_deg[from+1]++;\n\
    \  }\n  void add_edge(int u,int v,T cost){\n    add_arc(u,v,cost);\n    add_arc(v,u,cost);\n\
    \  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n    edges.reserve(directed?m:2*m);\n\
    \    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      T cost;cin>>cost;\n\
    \      if(directed)add_arc(u,v,cost);\n      else add_edge(u,v,cost);\n    }\n\
    \    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<\"(\"<<edges[i].to<<\",\"<<edges[i].cost<<\")\";\n      cerr<<\"\
    \\n\";\n    }\n  }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct WeightedEdge{\n  WeightedEdge()=default;\n\
    \  WeightedEdge(int from,int to,T cost):from(from),to(to),cost(cost){}\n  int\
    \ from,to;\n  T cost;\n};\n\ntemplate<typename T>\nstruct WeightedGraph{\n  int\
    \ n;\n  using cost_type=T;\n  using edge_type=WeightedEdge<T>;\n  vector<edge_type>\
    \ edges;\nprivate:\n  vector<int> in_deg;\n  bool prepared;\n  class OutgoingEdges{\n\
    \    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]);\
    \ }\n    edge_type* end(){ return &(g->edges[r]); }\n    edge_type& operator[](int\
    \ i){ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\npublic:\n\
    \  OutgoingEdges operator[](int v){\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1]\
    \ };\n  }\n\n  bool is_prepared()const{ return prepared; }\n\n  WeightedGraph():n(0),in_deg(1,0),prepared(false){}\n\
    \  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  WeightedGraph(int\
    \ n,int m,bool directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){\
    \ scan(m,directed,indexed); }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int\
    \ from,int to,T cost){\n    assert(!prepared);\n    assert(0<=from and from<n\
    \ and 0<=to and to<n);\n    edges.emplace_back(from,to,cost);\n    in_deg[from+1]++;\n\
    \  }\n  void add_edge(int u,int v,T cost){\n    add_arc(u,v,cost);\n    add_arc(v,u,cost);\n\
    \  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n    edges.reserve(directed?m:2*m);\n\
    \    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      T cost;cin>>cost;\n\
    \      if(directed)add_arc(u,v,cost);\n      else add_edge(u,v,cost);\n    }\n\
    \    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<\"(\"<<edges[i].to<<\",\"<<edges[i].cost<<\")\";\n      cerr<<\"\
    \\n\";\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/WeightedGraph.cpp
  requiredBy:
  - flow/Dinic.cpp
  - flow/MCF.cpp
  - graph/01BFS.cpp
  - graph/Dijkstra.cpp
  timestamp: '2022-11-30 18:56:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_6_B.test.cpp
  - test/AOJ/GRL_6_A.test.cpp
  - test/library-checker/Graph/ShortestPath.test.cpp
documentation_of: graph/WeightedGraph.cpp
layout: document
redirect_from:
- /library/graph/WeightedGraph.cpp
- /library/graph/WeightedGraph.cpp.html
title: graph/WeightedGraph.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
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
  bundledCode: "#line 2 \"graph/WeightedGraph.cpp\"\ntemplate<typename T>\nstruct\
    \ WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int from,int to,T cost):from(from),to(to),cost(cost){}\n\
    \  int from,to;\n  T cost;\n};\n\ntemplate<typename T>\nstruct WeightedGraph{\n\
    \  int n;\n  using cost_type=T;\n  using edge_type=WeightedEdge<T>;\nprivate:\n\
    \  vector<edge_type> edges;\n  vector<int> in_deg;\n  bool prepared;\n  class\
    \ OutgoingEdges{\n    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
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
    \\n\";\n    }\n  }\n};\n#line 2 \"graph/Dijkstra.cpp\"\ntemplate<typename WG,typename\
    \ T=typename WG::cost_type>\npair<vector<T>,vector<int>> dijkstra(WG&g,int s=0){\n\
    \  assert(g.is_prepared());\n  vector<T> d(g.n,-1);\n  vector<int> pre(g.n,-1);\n\
    \  priority_queue< pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;\n\
    \  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(const auto&e:g[id])\n      if(d[e.to]==-1\
    \ || d[e.to]>now+e.cost){\n        d[e.to]=now+e.cost;\n        pre[e.to]=id;\n\
    \        que.emplace(d[e.to],e.to);\n      }\n  }\n  return {d,pre};\n}\n"
  code: "#include \"graph/WeightedGraph.cpp\"\ntemplate<typename WG,typename T=typename\
    \ WG::cost_type>\npair<vector<T>,vector<int>> dijkstra(WG&g,int s=0){\n  assert(g.is_prepared());\n\
    \  vector<T> d(g.n,-1);\n  vector<int> pre(g.n,-1);\n  priority_queue< pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(const auto&e:g[id])\n      if(d[e.to]==-1\
    \ || d[e.to]>now+e.cost){\n        d[e.to]=now+e.cost;\n        pre[e.to]=id;\n\
    \        que.emplace(d[e.to],e.to);\n      }\n  }\n  return {d,pre};\n}"
  dependsOn:
  - graph/WeightedGraph.cpp
  isVerificationFile: false
  path: graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2022-11-26 20:25:33+09:00'
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

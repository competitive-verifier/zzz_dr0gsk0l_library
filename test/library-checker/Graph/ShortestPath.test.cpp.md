---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dijkstra.cpp
    title: graph/Dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
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
  bundledCode: "#line 1 \"test/library-checker/Graph/ShortestPath.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"graph/WeightedGraph.cpp\"\ntemplate<typename\
    \ T>\nstruct WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int from,int\
    \ to,T cost):from(from),to(to),cost(cost){}\n  int from,to;\n  T cost;\n};\n\n\
    template<typename T>\nstruct WeightedGraph{\n  int n;\n  using cost_type=T;\n\
    \  using edge_type=WeightedEdge<T>;\nprivate:\n  vector<edge_type> edges;\n  vector<int>\
    \ in_deg;\n  bool prepared;\n  class OutgoingEdges{\n    const WeightedGraph*\
    \ g;\n    int l,r;\n  public:\n    OutgoingEdges(const WeightedGraph* g,int l,int\
    \ r):g(g),l(l),r(r){}\n    const edge_type* begin()const{ return &(g->edges[l]);\
    \ }\n    const edge_type* end()const{ return &(g->edges[r]); }\n    const edge_type*\
    \ operator[](int i)const{ return &(g->edges[l+i]); }\n    int size()const{ return\
    \ r-l; }\n  };\npublic:\n  OutgoingEdges operator[](int v)const{\n    assert(prepared);\n\
    \    return { this,in_deg[v],in_deg[v+1] };\n  }\n  edge_type* mutable_edge(int\
    \ from,int edge_id){\n    assert(prepared);\n    return &edges[in_deg[from]+edge_id];\n\
    \  }\n\n  bool is_prepared()const{ return prepared; }\n\n  WeightedGraph():n(0),in_deg(1,0),prepared(false){}\n\
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
    \        cerr<<\"(\"<<edges[i].to<<\",\"<<edges[i].cost<<\")\";\n      cerr<<endl;\n\
    \    }\n  }\n};\n#line 2 \"graph/Dijkstra.cpp\"\ntemplate<typename WG,typename\
    \ T=typename WG::cost_type>\npair<vector<T>,vector<int>> dijkstra(const WG&g,int\
    \ s=0){\n  assert(g.is_prepared());\n  vector<T> d(g.n,-1);\n  vector<int> pre(g.n,-1);\n\
    \  priority_queue< pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;\n\
    \  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(const auto&e:g[id])\n      if(d[e.to]==-1\
    \ || d[e.to]>now+e.cost){\n        d[e.to]=now+e.cost;\n        pre[e.to]=id;\n\
    \        que.emplace(d[e.to],e.to);\n      }\n  }\n  return {d,pre};\n}\n#line\
    \ 7 \"test/library-checker/Graph/ShortestPath.test.cpp\"\n\nusing ll=long long;\n\
    \nint main(){\n  int n,m,s,t;cin>>n>>m>>s>>t;\n  WeightedGraph<ll> g(n,m,true,0);\n\
    \  auto [d,pre]=dijkstra(g,s);\n\n  cout<<d[t];\n  if(d[t]<0){\n    cout<<\"\\\
    n\";\n    return 0;\n  }\n\n  vector<pair<int,int>> ans;\n  while(t!=s){\n   \
    \ ans.emplace_back(pre[t],t);\n    t=pre[t];\n  }\n  reverse(ans.begin(),ans.end());\n\
    \  cout<<\" \"<<ans.size()<<\"\\n\";\n  for(const auto&[from,to]:ans)cout<<from<<\"\
    \ \"<<to<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/WeightedGraph.cpp\"\
    \n#include \"graph/Dijkstra.cpp\"\n\nusing ll=long long;\n\nint main(){\n  int\
    \ n,m,s,t;cin>>n>>m>>s>>t;\n  WeightedGraph<ll> g(n,m,true,0);\n  auto [d,pre]=dijkstra(g,s);\n\
    \n  cout<<d[t];\n  if(d[t]<0){\n    cout<<\"\\n\";\n    return 0;\n  }\n\n  vector<pair<int,int>>\
    \ ans;\n  while(t!=s){\n    ans.emplace_back(pre[t],t);\n    t=pre[t];\n  }\n\
    \  reverse(ans.begin(),ans.end());\n  cout<<\" \"<<ans.size()<<\"\\n\";\n  for(const\
    \ auto&[from,to]:ans)cout<<from<<\" \"<<to<<\"\\n\";\n}"
  dependsOn:
  - graph/WeightedGraph.cpp
  - graph/Dijkstra.cpp
  isVerificationFile: true
  path: test/library-checker/Graph/ShortestPath.test.cpp
  requiredBy: []
  timestamp: '2022-11-26 19:38:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Graph/ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/ShortestPath.test.cpp
- /verify/test/library-checker/Graph/ShortestPath.test.cpp.html
title: test/library-checker/Graph/ShortestPath.test.cpp
---

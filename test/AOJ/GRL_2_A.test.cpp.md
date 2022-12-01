---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.cpp
    title: datastructure/UnionFind.cpp
  - icon: ':heavy_check_mark:'
    path: graph/MinimumSpanningTree.cpp
    title: graph/MinimumSpanningTree.cpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/AOJ/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/WeightedGraph.cpp\"\
    \ntemplate<typename T>\nstruct WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int\
    \ from,int to,T weight):from(from),to(to),weight(weight){}\n  int from,to;\n \
    \ T weight;\n};\n\ntemplate<typename T>\nstruct WeightedGraph{\n  int n;\n  using\
    \ weight_type=T;\n  using edge_type=WeightedEdge<T>;\n  vector<edge_type> edges;\n\
    protected:\n  vector<int> in_deg;\n  bool prepared;\n  class OutgoingEdges{\n\
    \    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]);\
    \ }\n    edge_type* end(){ return &(g->edges[r]); }\n    edge_type& operator[](int\
    \ i){ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\npublic:\n\
    \  OutgoingEdges operator[](int v){\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1]\
    \ };\n  }\n\n  bool is_prepared()const{ return prepared; }\n\n  WeightedGraph():n(0),in_deg(1,0),prepared(false){}\n\
    \  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  WeightedGraph(int\
    \ n,int m,bool directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){\
    \ scan(m,directed,indexed); }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int\
    \ from,int to,T weight){\n    assert(!prepared);\n    assert(0<=from and from<n\
    \ and 0<=to and to<n);\n    edges.emplace_back(from,to,weight);\n    in_deg[from+1]++;\n\
    \  }\n  void add_edge(int u,int v,T weight){\n    add_arc(u,v,weight);\n    add_arc(v,u,weight);\n\
    \  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n    edges.reserve(directed?m:2*m);\n\
    \    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      T weight;cin>>weight;\n\
    \      if(directed)add_arc(u,v,weight);\n      else add_edge(u,v,weight);\n  \
    \  }\n    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<\"(\"<<edges[i].to<<\",\"<<edges[i].weight<<\")\";\n      cerr<<\"\
    \\n\";\n    }\n  }\n};\n#line 1 \"datastructure/UnionFind.cpp\"\nclass UnionFind{\n\
    \  int n,num;\n  vector<int> sz,parent;\npublic:\n  UnionFind()=default;\n  UnionFind(int\
    \ n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}\n \
    \ \n  int leader(int x){ \n    assert(0<=x and x<n);\n    return (x==parent[x]?\
    \ x : parent[x]=leader(parent[x])); \n  }\n  \n  bool same(int x,int y){\n   \
    \ assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y); \n\
    \  }\n  \n  bool merge(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    x=leader(x);y=leader(y);\n    if(x==y)return false;\n    if(sz[x]<sz[y])swap(x,y);\n\
    \    sz[x]+=sz[y];\n    parent[y]=x;\n    num--;\n    return true;\n  }\n  \n\
    \  int size(const int x){\n    assert(0<=x and x<n);\n    return sz[leader(x)];\n\
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n#line 2 \"graph/MinimumSpanningTree.cpp\"\
    \ntemplate<typename WG,typename E=typename WG::edge_type,typename W=typename WG::weight_type>\n\
    pair<W,vector<E>> minimum_spanning_tree(const WG&g){\n  int n=g.n;\n  UnionFind\
    \ uf(n);\n  auto edges=g.edges;\n  sort(edges.begin(),edges.end(),[](const E&e1,const\
    \ E&e2){\n    return e1.weight<e2.weight;\n  });\n  W res=0;\n  vector<E> tree;\n\
    \  for(const auto&[from,to,weight]:edges){\n    if(uf.same(from,to))continue;\n\
    \    tree.emplace_back(from,to,weight);\n    uf.merge(from,to);\n    res+=weight;\n\
    \  }\n  assert(uf.count()==1);\n  return {res,tree};\n}\n#line 7 \"test/AOJ/GRL_2_A.test.cpp\"\
    \n\nint main(){\n  int n,m;cin>>n>>m;\n  WeightedGraph<int> g(n,m,false,0);\n\
    \  auto [sum,tree]=minimum_spanning_tree(g);\n  cout<<sum<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/WeightedGraph.cpp\"\
    \n#include \"graph/MinimumSpanningTree.cpp\"\n\nint main(){\n  int n,m;cin>>n>>m;\n\
    \  WeightedGraph<int> g(n,m,false,0);\n  auto [sum,tree]=minimum_spanning_tree(g);\n\
    \  cout<<sum<<endl;\n}"
  dependsOn:
  - graph/WeightedGraph.cpp
  - graph/MinimumSpanningTree.cpp
  - datastructure/UnionFind.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 14:25:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_2_A.test.cpp
- /verify/test/AOJ/GRL_2_A.test.cpp.html
title: test/AOJ/GRL_2_A.test.cpp
---

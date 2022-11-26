---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/Graph.cpp
    title: graph/Graph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Tree/LowestCommonAncestor.test.cpp
    title: test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/Graph.cpp\"\nstruct Edge{\n  int from,to;\n  Edge()=default;\n\
    \  Edge(int from,int to):from(from),to(to){}\n};\n\nstruct Graph{\n  int n;\n\
    \  using edge_type=Edge;\nprivate:\n  vector<edge_type> edges;\n  vector<int>\
    \ in_deg;\n  bool prepared;\n class OutgoingEdges{\n    Graph* g;\n    int l,r;\n\
    \  public:\n    OutgoingEdges(Graph* g,int l,int r):g(g),l(l),r(r){}\n    edge_type&\
    \ begin(){ return g->edges[l]; }\n    edge_type& end(){ return g->edges[r]; }\n\
    \    edge_type& operator[](int i){ return g->edges[l+i]; }\n    int size()const{\
    \ return r-l; }\n  };\npublic:\n  OutgoingEdges operator[](int v){\n    assert(prepared);\n\
    \    return { this,in_deg[v],in_deg[v+1] };\n  }\n\n  bool is_prepared()const{\
    \ return prepared; }\n\n  Graph():n(0),in_deg(1,0),prepared(false){}\n  Graph(int\
    \ n):n(n),in_deg(n+1,0),prepared(false){}\n  Graph(int n,int m,bool directed=false,int\
    \ indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){ scan(m,directed,indexed);\
    \ }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int from,int to){\n    assert(!prepared);\n\
    \    assert(0<=from and from<n and 0<=to and to<n);\n    edges.emplace_back(from,to);\n\
    \    in_deg[from+1]++;\n  }\n  void add_edge(int u,int v){\n    add_arc(u,v);\n\
    \    add_arc(v,u);\n  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n\
    \    edges.reserve(directed?m:2*m);\n    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n\
    \      if(directed)add_arc(u,v);\n      else add_edge(u,v);\n    }\n    build();\n\
    \  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n\
    \    vector<edge_type> new_edges(in_deg.back());\n    auto counter=in_deg;\n \
    \   for(auto&&e:edges)new_edges[ counter[e.from]++ ]=e;\n    edges=new_edges;\n\
    \  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n    return;\n  #endif\n\
    \    assert(prepared);\n    for(int from=0;from<n;from++){\n      cerr<<from<<\"\
    ;\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n        cerr<<edges[i].to<<\"\
    \ \";\n      cerr<<\"\\n\";\n    }\n  }\n};\n#line 3 \"tree/Tree.cpp\"\nstruct\
    \ Tree:Graph{\n  using Graph::Graph;\n  int root=-1;\n  vector<vector<int>> son;\n\
    \  vector<int> DFS,BFS,parent,depth;\n\n  void scan_root(int indexed=1){\n   \
    \ for(int i=1;i<n;i++){\n      int p;cin>>p;\n      add_edge(p-indexed,i);\n \
    \   }\n    build();\n  }\n  void scan(int indexed=1){\n    Graph::scan(n-1,false,indexed);\n\
    \    build();\n  }\n\nprivate:\n  void dfs(int idx,int pre=-1){\n    parent[idx]=pre;\n\
    \    for(const auto&e:(*this)[idx])if(e.to!=pre){\n      depth[e.to]=depth[idx]+1;\n\
    \      dfs(e.to,idx);\n      son[idx].push_back(e.to);\n    }\n    DFS.push_back(idx);\n\
    \  }\npublic:\n  void build(int r=0){\n    if(!is_prepared())Graph::build();\n\
    \    if(~root){\n      assert(r==root);\n      return;\n    }\n    root=r;\n \
    \   son.resize(n);parent.resize(n);depth.resize(n);\n    DFS.reserve(n);BFS.reserve(n);\n\
    \    depth[root]=0;\n    dfs(root);\n    queue<int> que;\n    que.push(root);\n\
    \    while(que.size()){\n      int p=que.front();que.pop();\n      BFS.push_back(p);\n\
    \      for(int c:son[p])que.push(c);\n    }\n  }\n};\n"
  code: "#pragma once\n#include \"graph/Graph.cpp\"\nstruct Tree:Graph{\n  using Graph::Graph;\n\
    \  int root=-1;\n  vector<vector<int>> son;\n  vector<int> DFS,BFS,parent,depth;\n\
    \n  void scan_root(int indexed=1){\n    for(int i=1;i<n;i++){\n      int p;cin>>p;\n\
    \      add_edge(p-indexed,i);\n    }\n    build();\n  }\n  void scan(int indexed=1){\n\
    \    Graph::scan(n-1,false,indexed);\n    build();\n  }\n\nprivate:\n  void dfs(int\
    \ idx,int pre=-1){\n    parent[idx]=pre;\n    for(const auto&e:(*this)[idx])if(e.to!=pre){\n\
    \      depth[e.to]=depth[idx]+1;\n      dfs(e.to,idx);\n      son[idx].push_back(e.to);\n\
    \    }\n    DFS.push_back(idx);\n  }\npublic:\n  void build(int r=0){\n    if(!is_prepared())Graph::build();\n\
    \    if(~root){\n      assert(r==root);\n      return;\n    }\n    root=r;\n \
    \   son.resize(n);parent.resize(n);depth.resize(n);\n    DFS.reserve(n);BFS.reserve(n);\n\
    \    depth[root]=0;\n    dfs(root);\n    queue<int> que;\n    que.push(root);\n\
    \    while(que.size()){\n      int p=que.front();que.pop();\n      BFS.push_back(p);\n\
    \      for(int c:son[p])que.push(c);\n    }\n  }\n};"
  dependsOn:
  - graph/Graph.cpp
  isVerificationFile: false
  path: tree/Tree.cpp
  requiredBy: []
  timestamp: '2022-11-26 20:03:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
documentation_of: tree/Tree.cpp
layout: document
redirect_from:
- /library/tree/Tree.cpp
- /library/tree/Tree.cpp.html
title: tree/Tree.cpp
---

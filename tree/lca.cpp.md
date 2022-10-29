---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/LowestCommonAncestor.test.cpp
    title: test/library-checker/Tree/LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/tree.cpp\"\nstruct Tree:vector<vector<int>>{\n  int\
    \ n;\n  vector<vector<int>> son;\n  vector<int> DFS,BFS,parent,depth;\n  \n  Tree(int\
    \ n):n(n),son(n),parent(n,-1),depth(n){\n    DFS.reserve(n);\n    BFS.reserve(n);\n\
    \    resize(n);\n  }\n\n  void scan(int index=1){\n    for(int i=0;i<n-1;i++){\n\
    \      int u,v;cin>>u>>v;\n      add_edge(u-index,v-index);\n    }\n  }\n  void\
    \ scan_root(int index=1){\n    for(int i=1;i<n;i++){\n      int p;cin>>p;\n  \
    \    add_edge(p-index,i);\n    }\n  }\n\n  void add_edge(int u,int v){\n    at(u).push_back(v);\n\
    \    at(v).push_back(u);\n  }\n\n  vector<int>& operator[](int k){return at(k);}\n\
    private:\n  void dfs(int idx,int pre=-1){\n    parent[idx]=pre;\n    for(int p:at(idx))if(p!=pre){\n\
    \      depth[p]=depth[idx]+1;\n      dfs(p,idx);\n      son[idx].push_back(p);\n\
    \    }\n    DFS.push_back(idx);\n  }\npublic:\n  void build(int root=0){\n   \
    \ depth[root]=0;\n    dfs(root);\n    queue<int> que;\n    que.push(root);\n \
    \   while(que.size()){\n      int p=que.front();que.pop();\n      BFS.push_back(p);\n\
    \      for(int c:son[p])que.push(c);\n    }\n  }\n};\n#line 2 \"tree/lca.cpp\"\
    \n\nstruct LCA{\n  Tree T;\n  int n,root,log;\n  vector<vector<int>> ancestor;\n\
    \  \npublic:\n  LCA(const Tree&T_,int root_=0):T(T_),root(root_){\n    n=T.n;\n\
    \    for(log=0;(1<<log)<=n;log++){}\n    ancestor.resize(n, vector<int>(log,root)\
    \ );\n\n    T.build(root);\n    reverse(T.DFS.begin(),T.DFS.end());\n    for(int\
    \ p:T.DFS)if(p!=root){\n      ancestor[p][0]=T.parent[p];\n      for(int i=1;i<log;i++)ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];\n\
    \    }\n  }\n\n  int lca(int u,int v){\n    if(T.depth[u]>T.depth[v])swap(u,v);\n\
    \    for(int diff=T.depth[v]-T.depth[u],cnt=0;diff;cnt++,diff>>=1)\n      if(diff&1)v=ancestor[v][cnt];\n\
    \    if(u==v)return u;\n    for(int k=log-1;k>=0;k--)\n      if(ancestor[u][k]!=ancestor[v][k])\n\
    \        u=ancestor[u][k],v=ancestor[v][k];\n    return ancestor[u][0];\n  }\n\
    \n  int diameter(int u,int v){\n    int w=lca(u,v);\n    return T.depth[u]+T.depth[v]-2*T.depth[w];\n\
    \  }\n};\n"
  code: "#include \"tree/tree.cpp\"\n\nstruct LCA{\n  Tree T;\n  int n,root,log;\n\
    \  vector<vector<int>> ancestor;\n  \npublic:\n  LCA(const Tree&T_,int root_=0):T(T_),root(root_){\n\
    \    n=T.n;\n    for(log=0;(1<<log)<=n;log++){}\n    ancestor.resize(n, vector<int>(log,root)\
    \ );\n\n    T.build(root);\n    reverse(T.DFS.begin(),T.DFS.end());\n    for(int\
    \ p:T.DFS)if(p!=root){\n      ancestor[p][0]=T.parent[p];\n      for(int i=1;i<log;i++)ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];\n\
    \    }\n  }\n\n  int lca(int u,int v){\n    if(T.depth[u]>T.depth[v])swap(u,v);\n\
    \    for(int diff=T.depth[v]-T.depth[u],cnt=0;diff;cnt++,diff>>=1)\n      if(diff&1)v=ancestor[v][cnt];\n\
    \    if(u==v)return u;\n    for(int k=log-1;k>=0;k--)\n      if(ancestor[u][k]!=ancestor[v][k])\n\
    \        u=ancestor[u][k],v=ancestor[v][k];\n    return ancestor[u][0];\n  }\n\
    \n  int diameter(int u,int v){\n    int w=lca(u,v);\n    return T.depth[u]+T.depth[v]-2*T.depth[w];\n\
    \  }\n};\n"
  dependsOn:
  - tree/tree.cpp
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy: []
  timestamp: '2022-10-29 12:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Tree/LowestCommonAncestor.test.cpp
documentation_of: tree/lca.cpp
layout: document
redirect_from:
- /library/tree/lca.cpp
- /library/tree/lca.cpp.html
title: tree/lca.cpp
---

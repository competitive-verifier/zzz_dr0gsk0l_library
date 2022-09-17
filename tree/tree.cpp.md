---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: tree/lca.cpp
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
    \ n;\n  vector<vector<int>> son;\n  vector<int> DFS,BFS,parent;\n  \n  Tree(int\
    \ n):n(n),son(n),parent(n,-1){\n    DFS.reserve(n);\n    BFS.reserve(n);\n   \
    \ resize(n);\n  }\n\n  void scan(int index=1){\n    for(int i=0;i<n-1;i++){\n\
    \      int u,v;cin>>u>>v;\n      add_edge(u-index,v-index);\n    }\n  }\n  void\
    \ scan_root(int index=1){\n    for(int i=1;i<n;i++){\n      int p;cin>>p;\n  \
    \    add_edge(p-index,i);\n    }\n  }\n\n  void add_edge(int u,int v){\n    at(u).push_back(v);\n\
    \    at(v).push_back(u);\n  }\n\n  vector<int>& operator[](int k){return at(k);}\n\
    private:\n  void dfs(int idx,int pre=-1){\n    parent[idx]=pre;\n    for(int p:at(idx))if(p!=pre){\n\
    \      dfs(p,idx);\n      son[idx].push_back(p);\n    }\n    DFS.push_back(idx);\n\
    \  }\npublic:\n  void build(int root=0){ \n    dfs(root);\n    queue<int> que;\n\
    \    que.push(root);\n    while(que.size()){\n      int p=que.front();que.pop();\n\
    \      BFS.push_back(p);\n      for(int c:son[p])que.push(c);\n    }\n  }\n};\n"
  code: "struct Tree:vector<vector<int>>{\n  int n;\n  vector<vector<int>> son;\n\
    \  vector<int> DFS,BFS,parent;\n  \n  Tree(int n):n(n),son(n),parent(n,-1){\n\
    \    DFS.reserve(n);\n    BFS.reserve(n);\n    resize(n);\n  }\n\n  void scan(int\
    \ index=1){\n    for(int i=0;i<n-1;i++){\n      int u,v;cin>>u>>v;\n      add_edge(u-index,v-index);\n\
    \    }\n  }\n  void scan_root(int index=1){\n    for(int i=1;i<n;i++){\n     \
    \ int p;cin>>p;\n      add_edge(p-index,i);\n    }\n  }\n\n  void add_edge(int\
    \ u,int v){\n    at(u).push_back(v);\n    at(v).push_back(u);\n  }\n\n  vector<int>&\
    \ operator[](int k){return at(k);}\nprivate:\n  void dfs(int idx,int pre=-1){\n\
    \    parent[idx]=pre;\n    for(int p:at(idx))if(p!=pre){\n      dfs(p,idx);\n\
    \      son[idx].push_back(p);\n    }\n    DFS.push_back(idx);\n  }\npublic:\n\
    \  void build(int root=0){ \n    dfs(root);\n    queue<int> que;\n    que.push(root);\n\
    \    while(que.size()){\n      int p=que.front();que.pop();\n      BFS.push_back(p);\n\
    \      for(int c:son[p])que.push(c);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree.cpp
  requiredBy:
  - tree/lca.cpp
  timestamp: '2022-09-17 20:42:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Tree/LowestCommonAncestor.test.cpp
documentation_of: tree/tree.cpp
layout: document
redirect_from:
- /library/tree/tree.cpp
- /library/tree/tree.cpp.html
title: tree/tree.cpp
---

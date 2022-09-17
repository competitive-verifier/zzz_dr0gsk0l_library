---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: tree/lca.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library-checker/Tree/LowestCommonAncestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"tree/tree.cpp\"\nstruct Tree:vector<vector<int>>{\n\
    \  int n;\n  vector<vector<int>> son;\n  vector<int> DFS,BFS,parent;\n  \n  Tree(int\
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
    \      BFS.push_back(p);\n      for(int c:son[p])que.push(c);\n    }\n  }\n};\n\
    #line 2 \"tree/lca.cpp\"\n\nstruct LCA{\n  Tree T;\n  int n,root,log;\n  vector<vector<int>>\
    \ ancestor;\n  vector<int> depth;\n  \npublic:\n  LCA(const Tree&T_,int root_=0):T(T_),root(root_){\n\
    \    n=T.n;\n    for(log=0;(1<<log)<=n;log++){}\n    ancestor.resize(n, vector<int>(log,root)\
    \ );\n    depth.resize(n,0);\n\n    T.build(root);\n    reverse(T.DFS.begin(),T.DFS.end());\n\
    \    for(int p:T.DFS)if(p!=root){\n      depth[p]=depth[T.parent[p]]+1;\n    \
    \  ancestor[p][0]=T.parent[p];\n      for(int i=1;i<log;i++)ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];\n\
    \    }\n  }\n\n  int lca(int u,int v){\n    if(depth[u]>depth[v])swap(u,v);\n\
    \    for(int diff=depth[v]-depth[u],cnt=0;diff;cnt++,diff>>=1)\n      if(diff&1)v=ancestor[v][cnt];\n\
    \    if(u==v)return u;\n    for(int k=log-1;k>=0;k--)\n      if(ancestor[u][k]!=ancestor[v][k])\n\
    \        u=ancestor[u][k],v=ancestor[v][k];\n    return ancestor[u][0];\n  }\n\
    \n  int diameter(int u,int v){\n    int w=lca(u,v);\n    return depth[u]+depth[v]-2*depth[w];\n\
    \  }\n};\n#line 6 \"test/library-checker/Tree/LowestCommonAncestor.test.cpp\"\n\
    \nint main(){\n  int n,q;cin>>n>>q;\n  Tree t(n);\n  t.scan_root(0);\n  LCA lca(t);\n\
    \  while(q--){\n    int u,v;cin>>u>>v;\n    cout<<lca.lca(u,v)<<\"\\n\";\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"tree/lca.cpp\"\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  Tree t(n);\n  t.scan_root(0);\n  LCA lca(t);\n  while(q--){\n    int u,v;cin>>u>>v;\n\
    \    cout<<lca.lca(u,v)<<\"\\n\";\n  }\n}"
  dependsOn:
  - tree/lca.cpp
  - tree/tree.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2022-09-17 20:42:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Tree/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/LowestCommonAncestor.test.cpp
- /verify/test/library-checker/Tree/LowestCommonAncestor.test.cpp.html
title: test/library-checker/Tree/LowestCommonAncestor.test.cpp
---

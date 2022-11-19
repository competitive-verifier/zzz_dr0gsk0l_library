---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: tree/TreeMonoid.cpp
    title: tree/TreeMonoid.cpp
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
  bundledCode: "#line 1 \"tree/hld.cpp\"\ntemplate<typename TREE>\nstruct HLD{\n \
    \ int n;\n  TREE T;\n  vector<int> sz,head,id,id2;\n  bool prepared;\n  HLD(TREE\
    \ T_):T(T_),n(T_.n),sz(n),head(n),id(n),id2(n),prepared(false){}\nprivate:\n \
    \ void dfs_sz(int v){\n    sz[v]=1;\n    for(int c:T.son[v]){\n      sz[v]+=sz[c];\n\
    \      if(sz[c]>sz[T.son[v][0]])swap(c,T.son[v][0]);\n    }\n  }\n  void dfs_hld(int\
    \ v,int& k){\n    id[v]=k++;\n    for(int c:T.son[v]){\n      head[c]=(c==T.son[v][0]?head[v]:c);\n\
    \      dfs_hld(c,k);\n    }\n    id2[v]=k;\n  }\npublic:\n  vector<int> build(int\
    \ r=0){\n    assert(!prepared);prepared=true;\n    if(~T.root)assert(T.root==r);\n\
    \    else T.build(r);\n    head[r]=r;\n    dfs_sz(r);\n    int k=0;\n    dfs_hld(r,k);\n\
    \    return id;\n  }\n\n  int lca(int u,int v){\n    assert(prepared);\n    while(head[u]!=head[v]){\n\
    \      if(T.depth[head[u]]>T.depth[head[v]])u=T.parent[head[u]];\n      else v=T.parent[head[v]];\n\
    \    }\n    return (T.depth[u]<T.depth[v]?u:v);\n  }\n\n  // l=lca(u,v) \u3068\
    \u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\u30B9 \u3092\u9589\
    \u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\n  using path_t=vector<pair<int,int>>;\n\
    \  pair<path_t,path_t> path(int u,int v){\n    assert(prepared);\n    path_t path_u,path_v;\n\
    \    while(u!=v){\n      if(head[u]==head[v]){\n        if(T.depth[u]<T.depth[v])\n\
    \          path_v.emplace_back(id[v],id[u]);\n        else\n          path_u.emplace_back(id[u],id[v]);\n\
    \        break;\n      }\n      if(T.depth[head[u]]<T.depth[head[v]]){\n     \
    \   path_v.emplace_back(id[v],id[head[v]]);\n        v=T.parent[head[v]];\n  \
    \    }\n      else{\n        path_u.emplace_back(id[u],id[head[u]]);\n       \
    \ u=T.parent[head[u]];\n      }\n    }\n    if(u==v)path_u.emplace_back(id[u],id[u]);\n\
    \    return {path_u,path_v};\n  }\n\n  // [l,r) \u304C v \u306E\u90E8\u5206\u6728\
    \n  pair<int,int> subtree(int v){\n    assert(prepared);\n    return {id[v],id2[v]};\
    \ \n  }\n};\n"
  code: "template<typename TREE>\nstruct HLD{\n  int n;\n  TREE T;\n  vector<int>\
    \ sz,head,id,id2;\n  bool prepared;\n  HLD(TREE T_):T(T_),n(T_.n),sz(n),head(n),id(n),id2(n),prepared(false){}\n\
    private:\n  void dfs_sz(int v){\n    sz[v]=1;\n    for(int c:T.son[v]){\n    \
    \  sz[v]+=sz[c];\n      if(sz[c]>sz[T.son[v][0]])swap(c,T.son[v][0]);\n    }\n\
    \  }\n  void dfs_hld(int v,int& k){\n    id[v]=k++;\n    for(int c:T.son[v]){\n\
    \      head[c]=(c==T.son[v][0]?head[v]:c);\n      dfs_hld(c,k);\n    }\n    id2[v]=k;\n\
    \  }\npublic:\n  vector<int> build(int r=0){\n    assert(!prepared);prepared=true;\n\
    \    if(~T.root)assert(T.root==r);\n    else T.build(r);\n    head[r]=r;\n   \
    \ dfs_sz(r);\n    int k=0;\n    dfs_hld(r,k);\n    return id;\n  }\n\n  int lca(int\
    \ u,int v){\n    assert(prepared);\n    while(head[u]!=head[v]){\n      if(T.depth[head[u]]>T.depth[head[v]])u=T.parent[head[u]];\n\
    \      else v=T.parent[head[v]];\n    }\n    return (T.depth[u]<T.depth[v]?u:v);\n\
    \  }\n\n  // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068\
    \ [v,l] \u30D1\u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\
    \n  using path_t=vector<pair<int,int>>;\n  pair<path_t,path_t> path(int u,int\
    \ v){\n    assert(prepared);\n    path_t path_u,path_v;\n    while(u!=v){\n  \
    \    if(head[u]==head[v]){\n        if(T.depth[u]<T.depth[v])\n          path_v.emplace_back(id[v],id[u]);\n\
    \        else\n          path_u.emplace_back(id[u],id[v]);\n        break;\n \
    \     }\n      if(T.depth[head[u]]<T.depth[head[v]]){\n        path_v.emplace_back(id[v],id[head[v]]);\n\
    \        v=T.parent[head[v]];\n      }\n      else{\n        path_u.emplace_back(id[u],id[head[u]]);\n\
    \        u=T.parent[head[u]];\n      }\n    }\n    if(u==v)path_u.emplace_back(id[u],id[u]);\n\
    \    return {path_u,path_v};\n  }\n\n  // [l,r) \u304C v \u306E\u90E8\u5206\u6728\
    \n  pair<int,int> subtree(int v){\n    assert(prepared);\n    return {id[v],id2[v]};\
    \ \n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.cpp
  requiredBy:
  - tree/TreeMonoid.cpp
  timestamp: '2022-11-18 23:47:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
documentation_of: tree/hld.cpp
layout: document
redirect_from:
- /library/tree/hld.cpp
- /library/tree/hld.cpp.html
title: tree/hld.cpp
---

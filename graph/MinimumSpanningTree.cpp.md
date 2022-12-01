---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/UnionFind.cpp
    title: datastructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/UnionFind.cpp\"\nclass UnionFind{\n  int n,num;\n\
    \  vector<int> sz,parent;\npublic:\n  UnionFind()=default;\n  UnionFind(int n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}\n\
    \  \n  int leader(int x){ \n    assert(0<=x and x<n);\n    return (x==parent[x]?\
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
    \  }\n  assert(uf.count()==1);\n  return {res,tree};\n}\n"
  code: "#include \"datastructure/UnionFind.cpp\"\ntemplate<typename WG,typename E=typename\
    \ WG::edge_type,typename W=typename WG::weight_type>\npair<W,vector<E>> minimum_spanning_tree(const\
    \ WG&g){\n  int n=g.n;\n  UnionFind uf(n);\n  auto edges=g.edges;\n  sort(edges.begin(),edges.end(),[](const\
    \ E&e1,const E&e2){\n    return e1.weight<e2.weight;\n  });\n  W res=0;\n  vector<E>\
    \ tree;\n  for(const auto&[from,to,weight]:edges){\n    if(uf.same(from,to))continue;\n\
    \    tree.emplace_back(from,to,weight);\n    uf.merge(from,to);\n    res+=weight;\n\
    \  }\n  assert(uf.count()==1);\n  return {res,tree};\n}"
  dependsOn:
  - datastructure/UnionFind.cpp
  isVerificationFile: false
  path: graph/MinimumSpanningTree.cpp
  requiredBy: []
  timestamp: '2022-12-01 14:25:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_2_A.test.cpp
documentation_of: graph/MinimumSpanningTree.cpp
layout: document
redirect_from:
- /library/graph/MinimumSpanningTree.cpp
- /library/graph/MinimumSpanningTree.cpp.html
title: graph/MinimumSpanningTree.cpp
---

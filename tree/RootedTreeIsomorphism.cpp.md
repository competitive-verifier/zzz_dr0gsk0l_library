---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
    title: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/RootedTreeIsomorphism.cpp\"\ntemplate<typename TREE>\n\
    pair<int,vector<int>> rooted_tree_isomorphism(TREE&t){\n  assert(~t.root);\n \
    \ vector<int> res(t.n);\n  map<vector<int>,int> mp;\n  for(const int v:t.DFS){\n\
    \    vector<int> h;\n    for(const auto&e:t.son(v))h.push_back(res[e.to]);\n \
    \   sort(h.begin(),h.end());\n    if(!mp.count(h))mp[h]=mp.size();\n    res[v]=mp[h];\n\
    \  }\n  return {mp.size(),res};\n}\n"
  code: "template<typename TREE>\npair<int,vector<int>> rooted_tree_isomorphism(TREE&t){\n\
    \  assert(~t.root);\n  vector<int> res(t.n);\n  map<vector<int>,int> mp;\n  for(const\
    \ int v:t.DFS){\n    vector<int> h;\n    for(const auto&e:t.son(v))h.push_back(res[e.to]);\n\
    \    sort(h.begin(),h.end());\n    if(!mp.count(h))mp[h]=mp.size();\n    res[v]=mp[h];\n\
    \  }\n  return {mp.size(),res};\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/RootedTreeIsomorphism.cpp
  requiredBy: []
  timestamp: '2022-12-01 12:35:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
documentation_of: tree/RootedTreeIsomorphism.cpp
layout: document
redirect_from:
- /library/tree/RootedTreeIsomorphism.cpp
- /library/tree/RootedTreeIsomorphism.cpp.html
title: tree/RootedTreeIsomorphism.cpp
---

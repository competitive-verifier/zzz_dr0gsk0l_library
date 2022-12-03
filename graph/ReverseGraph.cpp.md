---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/SCC.cpp
    title: graph/SCC.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/SCC.test.cpp
    title: test/library-checker/Graph/SCC.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/ReverseGraph.cpp\"\ntemplate<typename GRAPH>\nGRAPH\
    \ reverse_graph(const GRAPH&g){\n  GRAPH r(g.n);\n  for(auto e:g.edges){\n   \
    \ swap(e.from,e.to);\n    r.add_arc(e);\n  }\n  r.build();\n  return r;\n}\n"
  code: "#pragma once\ntemplate<typename GRAPH>\nGRAPH reverse_graph(const GRAPH&g){\n\
    \  GRAPH r(g.n);\n  for(auto e:g.edges){\n    swap(e.from,e.to);\n    r.add_arc(e);\n\
    \  }\n  r.build();\n  return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/ReverseGraph.cpp
  requiredBy:
  - graph/SCC.cpp
  timestamp: '2022-12-03 17:21:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/SCC.test.cpp
documentation_of: graph/ReverseGraph.cpp
layout: document
redirect_from:
- /library/graph/ReverseGraph.cpp
- /library/graph/ReverseGraph.cpp.html
title: graph/ReverseGraph.cpp
---

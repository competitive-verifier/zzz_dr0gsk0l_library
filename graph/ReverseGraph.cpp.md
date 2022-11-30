---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ReverseGraph.cpp\"\ntemplate<typename GRAPH>\nGRAPH\
    \ reverse_graph(const GRAPH&g){\n  GRAPH r(g.n);\n  for(const auto&e:g.edges)\n\
    \    r.add_arc(e.to,e.from,e.cost);\n  r.build();\n  return r;\n}\n"
  code: "template<typename GRAPH>\nGRAPH reverse_graph(const GRAPH&g){\n  GRAPH r(g.n);\n\
    \  for(const auto&e:g.edges)\n    r.add_arc(e.to,e.from,e.cost);\n  r.build();\n\
    \  return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/ReverseGraph.cpp
  requiredBy: []
  timestamp: '2022-11-30 18:57:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ReverseGraph.cpp
layout: document
redirect_from:
- /library/graph/ReverseGraph.cpp
- /library/graph/ReverseGraph.cpp.html
title: graph/ReverseGraph.cpp
---

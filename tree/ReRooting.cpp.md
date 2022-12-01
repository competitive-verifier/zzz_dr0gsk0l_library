---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_5_A.test.cpp
    title: test/AOJ/GRL_5_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/ReRooting.cpp\"\ntemplate<typename TREE,typename Data>\n\
    class ReRooting{\n  int n;\n  TREE T;\npublic:\n  ReRooting(TREE&T):T(T),n(T.n){}\n\
    \n  template<typename F1,typename F2>\n  vector<Data> build(const F1&score,const\
    \ F2&merge,const Data&unit){\n    if(!~T.root)T.build(0);\n    vector<Data> dp1(n,unit),dp2(n);\n\
    \    for(int v:T.DFS)\n      for(const auto&e:T.son(v)){\n        dp2[e.to]=score(dp1[e.to],e);\n\
    \        merge(dp1[v],dp2[e.to]);\n      }\n    vector<Data> top(n,unit),res(n);\n\
    \    for(int v:T.BFS){\n      Data now=(T.root==v?unit:score(top[v],T.parent(v)));\n\
    \      for(const auto&e:T.son(v)){\n        top[e.to]=now;\n        merge(now,dp2[e.to]);\n\
    \      }\n      res[v]=now;\n      now=unit;\n      for(int i=T.son(v).size()-1;i>=0;i--){\n\
    \        const auto&e=T.son(v)[i];\n        merge(top[e.to],now);\n        merge(now,dp2[e.to]);\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  code: "template<typename TREE,typename Data>\nclass ReRooting{\n  int n;\n  TREE\
    \ T;\npublic:\n  ReRooting(TREE&T):T(T),n(T.n){}\n\n  template<typename F1,typename\
    \ F2>\n  vector<Data> build(const F1&score,const F2&merge,const Data&unit){\n\
    \    if(!~T.root)T.build(0);\n    vector<Data> dp1(n,unit),dp2(n);\n    for(int\
    \ v:T.DFS)\n      for(const auto&e:T.son(v)){\n        dp2[e.to]=score(dp1[e.to],e);\n\
    \        merge(dp1[v],dp2[e.to]);\n      }\n    vector<Data> top(n,unit),res(n);\n\
    \    for(int v:T.BFS){\n      Data now=(T.root==v?unit:score(top[v],T.parent(v)));\n\
    \      for(const auto&e:T.son(v)){\n        top[e.to]=now;\n        merge(now,dp2[e.to]);\n\
    \      }\n      res[v]=now;\n      now=unit;\n      for(int i=T.son(v).size()-1;i>=0;i--){\n\
    \        const auto&e=T.son(v)[i];\n        merge(top[e.to],now);\n        merge(now,dp2[e.to]);\n\
    \      }\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/ReRooting.cpp
  requiredBy: []
  timestamp: '2022-12-01 12:04:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_5_A.test.cpp
documentation_of: tree/ReRooting.cpp
layout: document
redirect_from:
- /library/tree/ReRooting.cpp
- /library/tree/ReRooting.cpp.html
title: tree/ReRooting.cpp
---

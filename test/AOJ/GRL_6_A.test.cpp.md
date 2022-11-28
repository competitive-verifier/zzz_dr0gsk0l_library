---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/Dinic.cpp
    title: flow/Dinic.cpp
  - icon: ':question:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/Dinic.cpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"flow/Dinic.cpp\"\
    \n\nint main(){\n  int n,m;cin>>n>>m;\n  Dinic<int> fl(n,0,n-1);\n  while(m--){\n\
    \    int u,v,c;cin>>u>>v>>c;\n    fl.add_edge(u,v,c);\n  }\n  cout<<fl.flow()<<endl;\n\
    }"
  dependsOn:
  - flow/Dinic.cpp
  - graph/WeightedGraph.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2022-11-28 17:05:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_6_A.test.cpp
- /verify/test/AOJ/GRL_6_A.test.cpp.html
title: test/AOJ/GRL_6_A.test.cpp
---

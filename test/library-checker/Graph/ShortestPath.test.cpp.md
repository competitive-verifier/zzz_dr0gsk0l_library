---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/Dijkstra.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/WeightedGraph.cpp\"\
    \n#include \"graph/Dijkstra.cpp\"\n\nusing ll=long long;\n\nint main(){\n  int\
    \ n,m,s,t;cin>>n>>m>>s>>t;\n  WeightedGraph<ll> g(n,m,true,0);\n  auto [d,pre]=dijkstra(g,s);\n\
    \n  cout<<d[t];\n  if(d[t]<0){\n    cout<<\"\\n\";\n    return 0;\n  }\n\n  vector<pair<int,int>>\
    \ ans;\n  while(t!=s){\n    ans.emplace_back(pre[t],t);\n    t=pre[t];\n  }\n\
    \  reverse(ans.begin(),ans.end());\n  cout<<\" \"<<ans.size()<<\"\\n\";\n  for(const\
    \ auto&[from,to]:ans)cout<<from<<\" \"<<to<<\"\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Graph/ShortestPath.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/ShortestPath.test.cpp
- /verify/test/library-checker/Graph/ShortestPath.test.cpp.html
title: test/library-checker/Graph/ShortestPath.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/Modint61.cpp
    title: mod/Modint61.cpp
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.cpp
    title: string/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
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
    \ string/RollingHash.cpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"string/RollingHash.cpp\"\
    \n\nint main(){\n  string t;cin>>t;\n  RollingHash T(t);\n  string p;cin>>p;\n\
    \  auto h=RollingHash::full_hash(p);\n  for(int i=0;i+p.size()<=t.size();i++)\n\
    \    if(T.get_hash(i,i+p.size())==h)\n      cout<<i<<\"\\n\";\n}"
  dependsOn:
  - string/RollingHash.cpp
  - mod/Modint61.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-02 18:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_14_B.test.cpp
- /verify/test/AOJ/ALDS1_14_B.test.cpp.html
title: test/AOJ/ALDS1_14_B.test.cpp
---

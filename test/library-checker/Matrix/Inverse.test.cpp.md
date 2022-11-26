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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linearalgebra/Matrix.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"linearalgebra/Matrix.cpp\"\
    \n#include \"mod/Modint.cpp\"\n\nusing mint=Mint<long long,998244353>;\nusing\
    \ M=Matrix<mint>;\n\n#define REP(i,n) for(int i=0;i<(n);i++)\n\nint main(){\n\t\
    int n;cin>>n;\n\tM A(n,n);\n\tcin>>A;\n\tauto B=A.inv();\n\tif(B.has_value())\n\
    \t\tREP(i,n)REP(j,n)cout<<B.value()[i][j]<<\"\\n \"[j+1<n];\n\telse\n\t\tcout<<-1<<\"\
    \\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Matrix/Inverse.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Matrix/Inverse.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Matrix/Inverse.test.cpp
- /verify/test/library-checker/Matrix/Inverse.test.cpp.html
title: test/library-checker/Matrix/Inverse.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_csr.hpp
    title: ac-library/atcoder/internal_csr.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/internal_scc.hpp
    title: ac-library/atcoder/internal_scc.hpp
  - icon: ':heavy_check_mark:'
    path: ac-library/atcoder/twosat.hpp
    title: ac-library/atcoder/twosat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/Math/2Sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <atcoder/twosat>\n\
    using namespace atcoder;\n\nint main(){\n  string hoge;cin>>hoge>>hoge;\n  int\
    \ n,m;cin>>n>>m;\n  two_sat ts(n);\n  while(m--){\n    int a,b,c;cin>>a>>b>>c;\n\
    \    bool f_a=a>0,f_b=b>0;\n    ts.add_clause(abs(a)-1,f_a,abs(b)-1,f_b);\n  }\n\
    \  if(ts.satisfiable()){\n    cout<<\"s SATISFIABLE\\n\";\n    cout<<\"v \";\n\
    \    auto A=ts.answer();\n    for(int i=0;i<n;i++)cout<<(A[i]?i+1:-(i+1))<<\"\
    \ \";\n    cout<<\"0\\n\";\n  }\n  else cout<<\"s UNSATISFIABLE\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include <atcoder/twosat>\nusing namespace atcoder;\n\n\
    int main(){\n  string hoge;cin>>hoge>>hoge;\n  int n,m;cin>>n>>m;\n  two_sat ts(n);\n\
    \  while(m--){\n    int a,b,c;cin>>a>>b>>c;\n    bool f_a=a>0,f_b=b>0;\n    ts.add_clause(abs(a)-1,f_a,abs(b)-1,f_b);\n\
    \  }\n  if(ts.satisfiable()){\n    cout<<\"s SATISFIABLE\\n\";\n    cout<<\"v\
    \ \";\n    auto A=ts.answer();\n    for(int i=0;i<n;i++)cout<<(A[i]?i+1:-(i+1))<<\"\
    \ \";\n    cout<<\"0\\n\";\n  }\n  else cout<<\"s UNSATISFIABLE\\n\";\n}"
  dependsOn:
  - ac-library/atcoder/twosat.hpp
  - ac-library/atcoder/internal_scc.hpp
  - ac-library/atcoder/internal_csr.hpp
  isVerificationFile: true
  path: test/Math/2Sat.test.cpp
  requiredBy: []
  timestamp: '2022-09-07 15:30:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Math/2Sat.test.cpp
layout: document
redirect_from:
- /verify/test/Math/2Sat.test.cpp
- /verify/test/Math/2Sat.test.cpp.html
title: test/Math/2Sat.test.cpp
---

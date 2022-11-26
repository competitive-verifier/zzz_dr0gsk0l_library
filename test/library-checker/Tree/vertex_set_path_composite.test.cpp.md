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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segtree/Segtree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"algebra/group/Affine.cpp\"\
    \n#include \"algebra/Reverse.cpp\"\n#include \"segtree/SegmentTree.cpp\"\n#include\
    \ \"tree/Tree.cpp\"\n#include \"tree/HLD.cpp\"\n#include \"tree/TreeMonoid.cpp\"\
    \n\n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace\
    \ atcoder;\nusing mint=modint998244353;\nostream& operator<<(ostream &os,mint\
    \ a){os<<a.val();return os;}\nistream& operator>>(istream &is,mint &a){\n  long\
    \ long b;is>>b;a=b;\n  return is;\n}\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  using G=AlgebraReverse<GroupAffine<mint>>;\n  using F=G::value_type;\n\
    \n  int n,q;cin>>n>>q; \n\n  vector<F> f(n);\n  for(int i=0;i<n;i++){\n    mint\
    \ a,b;cin>>a>>b;\n    f[i]={a,b};\n  }\n\n  Tree t(n);\n  t.scan(0);\n\n  TreeMonoid<Tree,G>\
    \ TM(t,f);\n\n  while(q--){\n    int c;cin>>c;\n    if(c){\n      int u,v,x;cin>>u>>v>>x;\n\
    \      F g=TM.path_prod(u,v);\n      cout<<G::eval(g,x)<<endl;\n    }\n    else{\n\
    \      int p,c,d;cin>>p>>c>>d;\n      TM.set(p,{c,d});\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Tree/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/vertex_set_path_composite.test.cpp
- /verify/test/library-checker/Tree/vertex_set_path_composite.test.cpp.html
title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
---

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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/Modint.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"segtree/SegmentTree.cpp\"\
    \n#include \"algebra/group/Affine.cpp\"\n#include \"algebra/Reverse.cpp\"\n#include\
    \ \"mod/Modint.cpp\"\n\nusing ll=long long;\nusing mint=Mint<ll>;\nusing G_=GroupAffine<mint>;\n\
    using G=AlgebraReverse<G_>;\nusing F=G::value_type;\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  vector<F> v(n);\n  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;\n  SegmentTree<G>\
    \ seg(v);\n  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n    if(t)cout<<G::eval(seg.prod(l,r),x)<<\"\
    \\n\";\n    else seg.set(l,F(r,x));\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp.html
title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
---

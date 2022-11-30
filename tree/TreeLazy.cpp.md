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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/Lazy/Reverse.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"segtree/LazySegmentTree.cpp\"\n#include \"algebra/Lazy/Reverse.cpp\"\
    \n#include \"tree/HLD.cpp\"\ntemplate<typename TREE,typename Lazy>\nstruct TreeLazy{\n\
    \  using MX=typename Lazy::MX;\n  using MF=typename Lazy::MF;\n  using X=typename\
    \ MX::value_type;\n  using F=typename MF::value_type;\n  using Lazy_r=LazyReverse<Lazy>;\n\
    \  int n;\n  TREE T;\n  HLD<Tree> hld;\n  vector<int> hld_id,euler_in,euler_out;\n\
    \  LazySegmentTree<Lazy> seg;\n  LazySegmentTree<Lazy_r> seg_r; \n  \n  TreeLazy(TREE\
    \ T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){\n    T.build(r);\n    hld_id=hld.build(r);\n\
    \  }\n  TreeLazy(TREE T,vector<X> a,int r=0):T(T),hld(T),n(T.n){\n    T.build(r);\n\
    \    hld_id=hld.build(r);\n    vector<X> hld_a(n);\n    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];\n\
    \    seg=LazySegmentTree<Lazy>(hld_a);\n    seg_r=LazySegmentTree<Lazy_r>(hld_a);\n\
    \  }\n\n  void set(int v,X x){\n    seg.set(hld_id[v],x);\n    seg_r.set(hld_id[v],x);\n\
    \  }\n  void multiply(int v,X x){\n    seg.multiply(hld_id[v],x);\n    seg_r.multiply(hld_id[v],x);\n\
    \  }\n  X get(int v){ return seg.get(hld_id[v]); }\n  \n  // [u,v]\u30D1\u30B9\
    \u306E monoid \u7A4D\n  X path_prod(int u,int v){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    X prod_u=MX::unit(),prod_v=MX::unit();\n    for(const auto&[l,r]:path_u){\n\
    \      X val=seg_r.prod(r,l+1);\n      prod_u=MX::op(prod_u,val);\n    }\n   \
    \ for(const auto&[l,r]:path_v){\n      X val=seg.prod(r,l+1);\n      prod_v=MX::op(val,prod_v);\n\
    \    }\n    return MX::op(prod_u,prod_v);\n  }\n  // root -> path\n  X path_root_prod(int\
    \ v){ return path_prod(T.root,v); }\n\n  void path_apply(int u,int v,const F&f){\n\
    \    auto [path_u,path_v]=hld.path(u,v);\n    for(const auto&[l,r]:path_u){\n\
    \      seg.apply(r,l+1,f);\n      seg_r.apply(r,l+1,f);\n    }\n    for(const\
    \ auto&[l,r]:path_v){\n      seg.apply(r,l+1,f);\n      seg_r.apply(r,l+1,f);\n\
    \    }\n  }\n  void path_root_apply(int v,const F&f){ path_apply(T.root,v,f);\
    \ }\n\n  X subtree_prod(int v){\n    assert(MX::commute);\n    auto [l,r]=hld.subtree(v);\n\
    \    return seg.prod(l,r);\n  }\n  void subtree_apply(int v,const F&f){\n    auto\
    \ [l,r]=hld.subtree(v);\n    seg.apply(l,r,f);\n    seg_r.apply(l,r,f);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: tree/TreeLazy.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/TreeLazy.cpp
layout: document
redirect_from:
- /library/tree/TreeLazy.cpp
- /library/tree/TreeLazy.cpp.html
title: tree/TreeLazy.cpp
---

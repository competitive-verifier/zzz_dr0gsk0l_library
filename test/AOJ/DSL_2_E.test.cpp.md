---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group/Add.cpp
    title: algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/RangeAddRangeMin.cpp
    title: algebra/lazy/RangeAddRangeMin.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/Min.cpp
    title: algebra/monoid/Min.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/DualSegmentTree.cpp
    title: segtree/DualSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/AOJ/DSL_2_E.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"algebra/group/Add.cpp\"\
    \ntemplate<typename X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr X unit()\
    \ { return X(0); }\n  static constexpr bool commute = true;\n};\n#line 1 \"algebra/monoid/Min.cpp\"\
    \ntemplate<typename X>\nstruct MonoidMin{\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x,y); }\n  static constexpr\
    \ X unit() { return numeric_limits<X>::max()/2; }\n  static constexpr bool commute\
    \ = true;\n};\n#line 4 \"algebra/lazy/RangeAddRangeMin.cpp\"\ntemplate<typename\
    \ X>\nstruct LazyRangeAddRangeMin{\n  using MX=MonoidMin<X>;\n  using MF=GroupAdd<X>;\n\
    \  static constexpr X mapping(const X&f,const X&x){\n    return f+x;\n  }\n};\n\
    #line 1 \"segtree/DualSegmentTree.cpp\"\ntemplate<typename Lazy>\nclass DualSegmentTree{\n\
    \  using MX = typename Lazy::MX;\n  using MF = typename Lazy::MF;\n  using X =\
    \ typename MX::value_type;\n  using F = typename MF::value_type;\n  int n,log,size;\n\
    \  vector<X> dat;\n  vector<F> laz;\n\n  void point_apply(int k,const F&f){\n\
    \    if(k<size)laz[k]=MF::op(f,laz[k]);\n    else dat[k-size]=Lazy::mapping(f,dat[k-size]);\n\
    \  }\n  void push(int k){\n    point_apply(2*k,laz[k]);\n    point_apply(2*k+1,laz[k]);\n\
    \    laz[k]=MF::unit();\n  }\n  void thrust(int k){ for(int i=log;i;i--)push(k>>i);\
    \ }\n\npublic:\n  DualSegmentTree() : DualSegmentTree(0) {}\n  DualSegmentTree(int\
    \ n):DualSegmentTree(vector<X>(n,MX::unit())) {}\n  DualSegmentTree(const vector<X>&v)\
    \ : n(v.size()),dat(v) {\n    for(log=1;(1<<log)<n;log++){}\n    size=1<<log;\n\
    \    laz.assign(size,MF::unit());\n  }\n\n  void set(int p,X x){\n    assert(0<=p\
    \ and p<n);\n    thrust(p+size);\n    dat[p]=x;\n  }\n\n  X operator[](int p){\n\
    \    assert(0<=p and p<n);\n    thrust(p+size);\n    return dat[p];\n  }\n\n \
    \ void apply(int l,int r,F f){\n    assert(0 <= l && l <= r && r <= n);\n    if(l==r)return;\n\
    \    thrust(l+=size);\n    thrust(r+=size-1);\n    for(int L=l,R=r+1;L<R;L>>=1,R>>=1){\n\
    \      if(L&1)point_apply(L++,f);\n      if(R&1)point_apply(--R,f);\n    }\n \
    \ }\n};\n#line 7 \"test/AOJ/DSL_2_E.test.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n  DualSegmentTree< LazyRangeAddRangeMin<int>\
    \ > seg(vector<int>(n,0));\n  while(q--){\n    int t;cin>>t;\n    if(t){\n   \
    \   int x;cin>>x;x--;\n      cout<<seg[x]<<\"\\n\";\n    }\n    else{\n      int\
    \ l,r,x;cin>>l>>r>>x;l--;\n      seg.apply(l,r,x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"algebra/lazy/RangeAddRangeMin.cpp\"\
    \n#include \"segtree/DualSegmentTree.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n  DualSegmentTree< LazyRangeAddRangeMin<int>\
    \ > seg(vector<int>(n,0));\n  while(q--){\n    int t;cin>>t;\n    if(t){\n   \
    \   int x;cin>>x;x--;\n      cout<<seg[x]<<\"\\n\";\n    }\n    else{\n      int\
    \ l,r,x;cin>>l>>r>>x;l--;\n      seg.apply(l,r,x);\n    }\n  }\n}"
  dependsOn:
  - algebra/lazy/RangeAddRangeMin.cpp
  - algebra/group/Add.cpp
  - algebra/monoid/Min.cpp
  - segtree/DualSegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2022-11-29 20:46:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_E.test.cpp
- /verify/test/AOJ/DSL_2_E.test.cpp.html
title: test/AOJ/DSL_2_E.test.cpp
---

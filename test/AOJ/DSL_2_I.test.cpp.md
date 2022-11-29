---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group/CntSum.cpp
    title: algebra/group/CntSum.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/RangeSetRangeSum.cpp
    title: algebra/lazy/RangeSetRangeSum.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/Set.cpp
    title: algebra/monoid/Set.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/LazySegmentTree.cpp
    title: segtree/LazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"test/AOJ/DSL_2_I.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"algebra/group/CntSum.cpp\"\
    \ntemplate<typename X>\nstruct GroupCntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n\
    \  static constexpr P op(const P &x, const P &y){\n    return {x.first + y.first,\
    \ x.second + y.second};\n  }\n  static constexpr P inverse(const P &x){ return\
    \ {-x.fi, -x.se}; }\n  static constexpr P unit() { return {0, 0}; }\n  static\
    \ constexpr bool commute = true;\n};\ntemplate<typename X>\nvector<pair<X,X>>\
    \ cnt_init(int n,const X&x){\n  return vector<pair<X,X>>(n,{x,1});\n}\ntemplate<typename\
    \ X>\nvector<pair<X,X>> cnt_init(const vector<X>&v){\n  int n=v.size();\n  vector<pair<X,X>>\
    \ res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n  return res;\n}\n#line 2 \"\
    algebra/monoid/Set.cpp\"\ntemplate<typename X>\nstruct MonoidSet{\n  using O=optional<X>;\n\
    \  using value_type=O;\n  static constexpr O op(const O &x,const O &y)noexcept{\
    \ return (x.has_value()?x:y); }\n  static constexpr O unit()noexcept{ return nullopt;\
    \ }\n  static constexpr bool commute=false;\n};\n#line 4 \"algebra/lazy/RangeSetRangeSum.cpp\"\
    \ntemplate<typename X>\nstruct LazyRangeSetRangeSum{\n  using MX=GroupCntSum<X>;\n\
    \  using MF=MonoidSet<X>;\n  using P=typename MX::value_type;\n  using F=typename\
    \ MF::value_type;\n  static constexpr P mapping(const F&f,const P&x){\n    if(f.has_value())return\
    \ {f.value()*x.second,x.second};\n    return x;\n  }\n};\n#line 2 \"segtree/LazySegmentTree.cpp\"\
    \n\ntemplate<typename Lazy>\nclass LazySegmentTree{\n  using MX = typename Lazy::MX;\n\
    \  using MF = typename Lazy::MF;\n  using X = typename MX::value_type;\n  using\
    \ F = typename MF::value_type;\n  int n,log,size;\n  vector<X> dat;\n  vector<F>\
    \ laz;\n\n  X reflect(int k){\n    if(k<size)return Lazy::mapping(laz[k],dat[k]);\n\
    \    return dat[k];\n  }\n  void point_apply(int k,const F&f){\n    if(k<size)laz[k]=MF::op(f,laz[k]);\n\
    \    else dat[k]=Lazy::mapping(f,dat[k]);\n  }\n  void push(int k){\n    dat[k]=reflect(k);\n\
    \    point_apply(2*k,laz[k]);\n    point_apply(2*k+1,laz[k]);\n    laz[k]=MF::unit();\n\
    \  }\n  void thrust(int k){ for(int i=log;i;i--)push(k>>i); }\n  void update(int\
    \ i){ dat[i]=MX::op(reflect(2*i),reflect(2*i+1)); }\n  void recalc(int k){ while(k>>=1)update(k);\
    \ }\n\npublic:\n  LazySegmentTree() : LazySegmentTree(0) {}\n  LazySegmentTree(int\
    \ n):LazySegmentTree(vector<X>(n,MX::unit())) {}\n  LazySegmentTree(const vector<X>&v)\
    \ : n(v.size()) {\n    for(log=1;(1<<log)<n;log++){}\n    size=1<<log;\n    dat.assign(size<<1,MX::unit());\n\
    \    laz.assign(size,MF::unit());\n    for(int i=0;i<n;++i)dat[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;--i)update(i);\n  }\n\n  void set(int p,X x){\n   \
    \ assert(0<=p and p<n);\n    thrust(p+=size);\n    dat[p]=x;\n    recalc(p);\n\
    \  }\n\n  X operator[](int p){\n    assert(0<=p and p<n);\n    thrust(p+=size);\n\
    \    return reflect(p);\n  }\n\n  X prod(int L,int R){\n    assert(0<=L and L<=R\
    \ and R<=n);\n    if(L==R)return MX::unit();\n    thrust(L+=size);\n    thrust((R+=size-1)++);\n\
    \    X vl=MX::unit(),vr=MX::unit();\n    while(L<R){\n      if(L&1)vl=MX::op(vl,reflect(L++));\n\
    \      if(R&1)vr=MX::op(reflect(--R),vr);\n      L>>=1,R>>=1;\n    }\n    return\
    \ MX::op(vl,vr);\n  }\n\n  void apply(int l,int r,F f){\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if(l==r)return;\n    thrust(l+=size);\n    thrust(r+=size-1);\n\
    \    for(int L=l,R=r+1;L<R;L>>=1,R>>=1){\n      if(L&1)point_apply(L++,f);\n \
    \     if(R&1)point_apply(--R,f);\n    }\n    recalc(l);\n    recalc(r);\n  }\n\
    };\n#line 7 \"test/AOJ/DSL_2_I.test.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n  LazySegmentTree< LazyRangeSetRangeSum<int>\
    \ > seg(cnt_init(n,0));\n  while(q--){\n    int t,l,r;cin>>t>>l>>r;r++;\n    if(t)cout<<seg.prod(l,r).first<<\"\
    \\n\";\n    else{\n      int x;cin>>x;\n      seg.apply(l,r,x);\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"algebra/lazy/RangeSetRangeSum.cpp\"\
    \n#include \"segtree/LazySegmentTree.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n  LazySegmentTree< LazyRangeSetRangeSum<int>\
    \ > seg(cnt_init(n,0));\n  while(q--){\n    int t,l,r;cin>>t>>l>>r;r++;\n    if(t)cout<<seg.prod(l,r).first<<\"\
    \\n\";\n    else{\n      int x;cin>>x;\n      seg.apply(l,r,x);\n    }\n  }\n}"
  dependsOn:
  - algebra/lazy/RangeSetRangeSum.cpp
  - algebra/group/CntSum.cpp
  - algebra/monoid/Set.cpp
  - segtree/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '2022-11-29 20:44:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_I.test.cpp
- /verify/test/AOJ/DSL_2_I.test.cpp.html
title: test/AOJ/DSL_2_I.test.cpp
---

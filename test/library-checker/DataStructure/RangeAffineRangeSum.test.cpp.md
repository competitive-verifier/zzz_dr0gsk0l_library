---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group/Affine.cpp
    title: algebra/group/Affine.cpp
  - icon: ':question:'
    path: algebra/group/CntSum.cpp
    title: algebra/group/CntSum.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/AffineSum.cpp
    title: algebra/lazy/AffineSum.cpp
  - icon: ':heavy_check_mark:'
    path: mod/Modint.cpp
    title: mod/Modint.cpp
  - icon: ':question:'
    path: segtree/LazySegmentTree.cpp
    title: segtree/LazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"algebra/group/CntSum.cpp\"\
    \ntemplate<typename X>\nstruct GroupCntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n\
    \  static constexpr P op(const P &x, const P &y){\n    return {x.first + y.first,\
    \ x.second + y.second};\n  }\n  static constexpr P inverse(const P &x){ return\
    \ {-x.fi, -x.se}; }\n  static constexpr P unit() { return {0, 0}; }\n  static\
    \ constexpr bool commute = true;\n};\ntemplate<typename X>\nvector<pair<X,X>>\
    \ cnt_init(int n,const X&x){\n  return vector<pair<X,X>>(n,{x,1});\n}\ntemplate<typename\
    \ X>\nvector<pair<X,X>> cnt_init(const vector<X>&v){\n  int n=v.size();\n  vector<pair<X,X>>\
    \ res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n  return res;\n}\n#line 1 \"\
    algebra/group/Affine.cpp\"\n// op(f,g) = f(g(x))\ntemplate<typename K>\nstruct\
    \ GroupAffine{\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr\
    \ F op(const F &f, const F &g) noexcept {\n    return F({f.first * g.first, f.first\
    \ * g.second + f.second});\n  }\n  static constexpr F inverse(const F &x) {\n\
    \    auto [a, b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a, a * (-b)};\n\
    \  }\n  /*\n  static constexpr F power(const F& f,long long n) noexcept {\n  \
    \  if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n};\n#line 4 \"algebra/lazy/AffineSum.cpp\"\
    \ntemplate<typename X>\nstruct LazyAffineSum{\n  using MX=GroupCntSum<X>;\n  using\
    \ MF=GroupAffine<X>;\n  using P=typename MX::value_type;\n  using F=typename MF::value_type;\n\
    \  static constexpr P mapping(const F&f,const P&x){\n    return {f.first*x.first+f.second*x.second,\
    \ x.second};\n  }\n};\n#line 2 \"segtree/LazySegmentTree.cpp\"\n\ntemplate<typename\
    \ Lazy>\nclass LazySegmentTree{\n  using MX = typename Lazy::MX;\n  using MF =\
    \ typename Lazy::MF;\n  using X = typename MX::value_type;\n  using F = typename\
    \ MF::value_type;\n  int n,log,size;\n  vector<X> dat;\n  vector<F> laz;\n\n \
    \ X reflect(int k){\n    if(k<size)return Lazy::mapping(laz[k],dat[k]);\n    return\
    \ dat[k];\n  }\n  void point_apply(int k,const F&f){\n    if(k<size)laz[k]=MF::op(f,laz[k]);\n\
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
    };\n#line 1 \"mod/Modint.cpp\"\ntemplate<typename T,T MOD=998244353>\nstruct Mint{\n\
    \  inline static constexpr T mod = MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed\
    \ v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)v+=MOD;}\n  \n  static Mint raw(int\
    \ v){\n    Mint x;\n    x.v=v;\n    return x;\n  }\n\n  Mint pow(long long k){\n\
    \    Mint res(1),tmp(v);\n    while(k){\n      if(k&1)res*=tmp;\n      tmp*=tmp;\n\
    \      k>>=1;\n    }\n    return res;\n  }\n\n  static Mint add_identity(){return\
    \ Mint(0);}\n  static Mint mul_identity(){return Mint(1);}\n\n  Mint inv(){return\
    \ pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint&\
    \ operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint a){return\
    \ (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n \
    \ Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a) const{return\
    \ Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\n  Mint operator+()\
    \ const{return *this;}\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n\n  static Mint comb(long long n,int k){\n   \
    \ Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n    \
    \  dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ Mint &m){os<<m.v;return os;}\n  friend istream& operator>>(istream&is,Mint &m){is>>m.v;m.v%=MOD;if(m.v<0)m.v+=MOD;return\
    \ is;}\n};\n#line 8 \"test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp\"\
    \n\nusing mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  \n  int n,q;cin>>n>>q;\n\n  vector<mint> v(n);\n  for(int\
    \ i=0;i<n;i++)cin>>v[i];\n  LazySegmentTree< LazyAffineSum<mint> > seg(cnt_init(v));\n\
    \n  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.prod(l,r).first<<'\\\
    n';\n    else{\n      int b,c;cin>>b>>c;\n      seg.apply(l,r,{b,c});\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"algebra/lazy/AffineSum.cpp\"\
    \n#include \"segtree/LazySegmentTree.cpp\"\n#include \"mod/Modint.cpp\"\n\nusing\
    \ mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  \n  int n,q;cin>>n>>q;\n\n  vector<mint> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  LazySegmentTree< LazyAffineSum<mint> > seg(cnt_init(v));\n\n  while(q--){\n\
    \    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.prod(l,r).first<<'\\n';\n   \
    \ else{\n      int b,c;cin>>b>>c;\n      seg.apply(l,r,{b,c});\n    }\n  }\n}"
  dependsOn:
  - algebra/lazy/AffineSum.cpp
  - algebra/group/CntSum.cpp
  - algebra/group/Affine.cpp
  - segtree/LazySegmentTree.cpp
  - mod/Modint.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  requiredBy: []
  timestamp: '2022-11-29 21:38:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp.html
title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
---

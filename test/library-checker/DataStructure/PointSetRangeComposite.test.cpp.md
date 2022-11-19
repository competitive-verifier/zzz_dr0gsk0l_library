---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/algebra_reverse.cpp
    title: algebra/algebra_reverse.cpp
  - icon: ':question:'
    path: algebra/group_linear.cpp
    title: algebra/group_linear.cpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.cpp
    title: mod/modint.cpp
  - icon: ':question:'
    path: segtree/segtree.cpp
    title: segtree/segtree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library-checker/DataStructure/PointSetRangeComposite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"segtree/segtree.cpp\"\
    \ntemplate<class Monoid>\nstruct SegmentTree{\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vector<X> dat;\n  int n, log, size;\n\n  SegmentTree()\
    \ : SegmentTree(0) {}\n  SegmentTree(int n) : SegmentTree(vector<X>(n, Monoid::unit()))\
    \ {}\n  SegmentTree(vector<X> v) : n(v.size()) {\n    log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  X operator[](int i) { return dat[size\
    \ + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    set(i, Monoid::op(dat[i+size],x));\n  }\n\n  X prod(int L, int\
    \ R) {\n    assert(L <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(), vr\
    \ = Monoid::unit();\n    L += size, R += size;\n    while (L < R) {\n      if\
    \ (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R],\
    \ vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n\
    \  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int max_right(F&\
    \ check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n  \
    \  if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F& check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit()));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit();\n    do {\n      --R;\n      while (R > 1 && (R %\
    \ 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R\
    \ < size) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\
    \u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n  X Xor_prod(int\
    \ l, int r, int xor_val) {\n    assert(Monoid::commute);\n    X x = Monoid::unit();\n\
    \    for (int k = 0; k < log + 1; ++k) {\n      if (l >= r) break;\n      if (l\
    \ & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }\n      if\
    \ (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }\n     \
    \ l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n  }\n\n  ostream& operator<<(ostream&os)const{\n\
    \    os<<\"(\";\n    for(int L=1;L<=size;L<<=1){\n      os<<\"[\";\n      for(int\
    \ j=L;j<(L<<1);j++){\n        os<<dat[j];\n        if(j+1<(L<<1))os<<\",\";\n\
    \      }\n      os<<\"]\";\n    }\n    os<<\")\";\n    return os;\n  }\n};\n#line\
    \ 1 \"algebra/group_linear.cpp\"\n// op(f,g) = f(g(x))\ntemplate<typename K>\n\
    struct Group_Affine{\n  using F = pair<K, K>;\n  using value_type = F;\n  static\
    \ constexpr F op(const F &f, const F &g) noexcept {\n    return F({f.first * g.first,\
    \ f.first * g.second + f.second});\n  }\n  static constexpr F inverse(const F\
    \ &x) {\n    auto [a, b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a,\
    \ a * (-b)};\n  }\n  /*\n  static constexpr F power(const F& f,long long n) noexcept\
    \ {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n};\n#line 2 \"algebra/algebra_reverse.cpp\"\
    \ntemplate<typename Algebra>\nstruct Algebra_Reverse:Algebra{\n  using X=typename\
    \ Algebra::value_type;\n  static constexpr X op(const X& x, const X& y){ return\
    \ Algebra::op(y,x); }\n};\n#line 1 \"mod/modint.cpp\"\ntemplate<typename T,T MOD=998244353>\n\
    struct Mint{\n  inline static constexpr T mod = MOD;\n  T v;\n  Mint():v(0){}\n\
    \  Mint(signed v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)v+=MOD;}\n  \n  static\
    \ Mint raw(int v){\n    Mint x;\n    x.v=v;\n    return x;\n  }\n\n  Mint pow(long\
    \ long k){\n    Mint res(1),tmp(v);\n    while(k){\n      if(k&1)res*=tmp;\n \
    \     tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n  }\n\n  static Mint add_identity(){return\
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
    \ is;}\n};\n#line 9 \"test/library-checker/DataStructure/PointSetRangeComposite.test.cpp\"\
    \n\nusing ll=long long;\nusing mint=Mint<ll>;\nusing G_=Group_Affine<mint>;\n\
    using G=Algebra_Reverse<G_>;\nusing F=G::value_type;\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  vector<F> v(n);\n  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;\n  SegmentTree<G>\
    \ seg(v);\n  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n    if(t)cout<<G::eval(seg.prod(l,r),x)<<\"\
    \\n\";\n    else seg.set(l,F(r,x));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"segtree/segtree.cpp\"\
    \n#include \"algebra/group_linear.cpp\"\n#include \"algebra/algebra_reverse.cpp\"\
    \n#include \"mod/modint.cpp\"\n\nusing ll=long long;\nusing mint=Mint<ll>;\nusing\
    \ G_=Group_Affine<mint>;\nusing G=Algebra_Reverse<G_>;\nusing F=G::value_type;\n\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vector<F> v(n);\n  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;\n\
    \  SegmentTree<G> seg(v);\n  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n \
    \   if(t)cout<<G::eval(seg.prod(l,r),x)<<\"\\n\";\n    else seg.set(l,F(r,x));\n\
    \  }\n}"
  dependsOn:
  - segtree/segtree.cpp
  - algebra/group_linear.cpp
  - algebra/algebra_reverse.cpp
  - mod/modint.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2022-11-19 13:22:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp.html
title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
---

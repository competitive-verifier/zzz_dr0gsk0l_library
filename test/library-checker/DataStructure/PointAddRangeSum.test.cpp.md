---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group_add.cpp
    title: algebra/group_add.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library-checker/DataStructure/PointAddRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"segtree/segtree.cpp\"\ntemplate<class\
    \ Monoid>\nstruct SegmentTree{\n  using X = typename Monoid::value_type;\n  using\
    \ value_type = X;\n  vector<X> dat;\n  int n, log, size;\n\n  SegmentTree() :\
    \ SegmentTree(0) {}\n  SegmentTree(int n) : SegmentTree(vector<X>(n, Monoid::unit()))\
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
    \ 2 \"algebra/group_add.cpp\"\ntemplate<typename X>\nstruct Group_Add {\n  using\
    \ value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept {\
    \ return x + y; }\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\n  static constexpr X power(const X &x, long long n) noexcept { return\
    \ X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static constexpr\
    \ bool commute = true;\n};\n#line 7 \"test/library-checker/DataStructure/PointAddRangeSum.test.cpp\"\
    \n\nusing ll=long long;\nusing G=Group_Add<ll>;\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  vector<ll> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n  SegmentTree<G> seg(v);\n\
    \  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.prod(l,r)<<\"\\\
    n\";\n    else seg.multiply(l,r);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"segtree/segtree.cpp\"\
    \n#include \"algebra/group_add.cpp\"\n\nusing ll=long long;\nusing G=Group_Add<ll>;\n\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vector<ll> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  SegmentTree<G> seg(v);\n  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.prod(l,r)<<\"\
    \\n\";\n    else seg.multiply(l,r);\n  }\n}"
  dependsOn:
  - segtree/segtree.cpp
  - algebra/group_add.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2022-11-19 13:22:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointAddRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/PointAddRangeSum.test.cpp.html
title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
---

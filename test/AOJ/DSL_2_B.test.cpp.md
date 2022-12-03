---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group/Add.cpp
    title: algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/FenwickTree.cpp
    title: datastructure/FenwickTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/AOJ/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"algebra/group/Add.cpp\"\
    \ntemplate<typename X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr X unit()\
    \ { return X(0); }\n  static constexpr bool commute = true;\n};\n#line 2 \"datastructure/FenwickTree.cpp\"\
    \ntemplate<typename AbelGroup>\nclass FenwickTree{\n  using T=typename AbelGroup::value_type;\n\
    \  int n;\n  vector<T> dat,raw;\n  void chop(T&a,T b){ a=AbelGroup::op(a,b); }\n\
    public:\n  FenwickTree(){\n    assert(AbelGroup::commute);\n  }\n  FenwickTree(int\
    \ n):n(n){\n    assert(AbelGroup::commute);\n    dat=raw=vector<T>(n,AbelGroup::unit());\n\
    \  }\n  FenwickTree(const vector<T>&v):n(v.size()),raw(v),dat(v){\n    assert(AbelGroup::commute);\n\
    \    for(int i=1;i<=n;i++){\n      int j=i+(i&-i);\n      if(j<=n)chop(dat[j-1],dat[i-1]);\n\
    \    }\n  }\n\n  T operator[](int k)const{ return raw[k]; }\n\n  void set(int\
    \ k,const T&x){\n    T diff=AbelGroup::op(x,AbelGroup::inverse(raw[k]));\n   \
    \ raw[k]=x;\n    for(++k;k<=n;k+=k&-k)chop(dat[k-1],diff);\n  }\n  void multiply(int\
    \ k,const T&x){\n    chop(raw[k],x);\n    for(++k;k<=n;k+=k&-k)chop(dat[k-1],x);\n\
    \  }\n\n  T prod(int k){\n    T res=AbelGroup::unit();\n    while(k>0){\n    \
    \  chop(res, dat[k-1]);\n      k -= k&-k;\n    }\n    return res;\n  }\n  T prod(int\
    \ L,int R){\n    T pos=AbelGroup::unit();\n    while(L<R){\n      chop(pos,dat[R-1]);\n\
    \      R -= R&-R;\n    }\n    T neg=AbelGroup::unit();\n    while(R<L){\n    \
    \  chop(neg, dat[L - 1]);\n      L -= L&-L;\n    }\n    chop(pos,AbelGroup::inverse(neg));\n\
    \    return pos;\n  }\n};\n#line 7 \"test/AOJ/DSL_2_B.test.cpp\"\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n\
    \  FenwickTree<GroupAdd<int>> ft(n);\n  while(q--){\n    int c,s,t;cin>>c>>s>>t;s--;\n\
    \    if(c){\n      assert(s<=t);\n      cout<<ft.prod(s,t)<<\"\\n\";\n    }\n\
    \    else ft.multiply(s,t);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"algebra/group/Add.cpp\"\
    \n#include \"datastructure/FenwickTree.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n  FenwickTree<GroupAdd<int>> ft(n);\n\
    \  while(q--){\n    int c,s,t;cin>>c>>s>>t;s--;\n    if(c){\n      assert(s<=t);\n\
    \      cout<<ft.prod(s,t)<<\"\\n\";\n    }\n    else ft.multiply(s,t);\n  }\n}"
  dependsOn:
  - algebra/group/Add.cpp
  - datastructure/FenwickTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-03 13:09:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_B.test.cpp
- /verify/test/AOJ/DSL_2_B.test.cpp.html
title: test/AOJ/DSL_2_B.test.cpp
---

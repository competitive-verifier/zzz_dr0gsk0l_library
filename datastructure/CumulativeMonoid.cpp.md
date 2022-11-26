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
  bundledCode: "#line 1 \"datastructure/CumulativeMonoid.cpp\"\ntemplate<typename\
    \ Monoid>\nclass CumulativeMonoid{\n  using T=typename Monoid::value_type;\n \
    \ vector<T> pre,suf;\npublic:\n  CumulativeMonoid():pre(1,Monoid::unit()),sum(pre){}\n\
    \  CumulativeMonoid(const vector<T>&v):pre(v.size()+1,Monoid::unit()),sum(pre){\n\
    \    for(int i=0;i<v.size();i++)pre[i+1]=Monoid::op(pre[i],v[i]);\n    for(int\
    \ i=v.size()-1;i>=0;i--)suf[i]=Monoid::op(v[i],suf[i+1]);\n  }\n  //[0,r)\n  T\
    \ pre_sum(int r){ return pre[r]; }\n  // [l,n)\n  T suf_sum(int l){ return suf[l];\
    \ }\n\n  T sum(){ return pre.back(); }\n}\n"
  code: "template<typename Monoid>\nclass CumulativeMonoid{\n  using T=typename Monoid::value_type;\n\
    \  vector<T> pre,suf;\npublic:\n  CumulativeMonoid():pre(1,Monoid::unit()),sum(pre){}\n\
    \  CumulativeMonoid(const vector<T>&v):pre(v.size()+1,Monoid::unit()),sum(pre){\n\
    \    for(int i=0;i<v.size();i++)pre[i+1]=Monoid::op(pre[i],v[i]);\n    for(int\
    \ i=v.size()-1;i>=0;i--)suf[i]=Monoid::op(v[i],suf[i+1]);\n  }\n  //[0,r)\n  T\
    \ pre_sum(int r){ return pre[r]; }\n  // [l,n)\n  T suf_sum(int l){ return suf[l];\
    \ }\n\n  T sum(){ return pre.back(); }\n}"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/CumulativeMonoid.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/CumulativeMonoid.cpp
layout: document
redirect_from:
- /library/datastructure/CumulativeMonoid.cpp
- /library/datastructure/CumulativeMonoid.cpp.html
title: datastructure/CumulativeMonoid.cpp
---

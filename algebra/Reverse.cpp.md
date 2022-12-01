---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algebra/lazy/Reverse.cpp
    title: algebra/lazy/Reverse.cpp
  - icon: ':x:'
    path: tree/TreeLazy.cpp
    title: tree/TreeLazy.cpp
  - icon: ':x:'
    path: tree/TreeMonoid.cpp
    title: tree/TreeMonoid.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/Reverse.cpp\"\ntemplate<typename Algebra>\nstruct\
    \ AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static constexpr\
    \ X op(const X& x, const X& y){ return Algebra::op(y,x); }\n};\n"
  code: "#pragma once\ntemplate<typename Algebra>\nstruct AlgebraReverse:Algebra{\n\
    \  using X=typename Algebra::value_type;\n  static constexpr X op(const X& x,\
    \ const X& y){ return Algebra::op(y,x); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/Reverse.cpp
  requiredBy:
  - tree/TreeMonoid.cpp
  - tree/TreeLazy.cpp
  - algebra/lazy/Reverse.cpp
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/GRL_5_E.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
documentation_of: algebra/Reverse.cpp
layout: document
redirect_from:
- /library/algebra/Reverse.cpp
- /library/algebra/Reverse.cpp.html
title: algebra/Reverse.cpp
---

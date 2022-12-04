---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy/AddMin.cpp
    title: algebra/lazy/AddMin.cpp
  - icon: ':question:'
    path: algebra/lazy/AddSum.cpp
    title: algebra/lazy/AddSum.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_1_B.test.cpp
    title: test/AOJ/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/group/Add.cpp\"\ntemplate<typename X>\nstruct GroupAdd\
    \ {\n  using value_type = X;\n  static constexpr X op(const X &x, const X &y)\
    \ noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, long long n) noexcept\
    \ { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "#pragma once\ntemplate<typename X>\nstruct GroupAdd {\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, long long n) noexcept { return X(n) * x; }\n \
    \ static constexpr X unit() { return X(0); }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group/Add.cpp
  requiredBy:
  - algebra/lazy/AddSum.cpp
  - algebra/lazy/AddMin.cpp
  timestamp: '2022-11-26 09:11:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/DSL_1_B.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
documentation_of: algebra/group/Add.cpp
layout: document
redirect_from:
- /library/algebra/group/Add.cpp
- /library/algebra/group/Add.cpp.html
title: algebra/group/Add.cpp
---

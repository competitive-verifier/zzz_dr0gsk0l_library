---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1097.test.cpp
    title: test/yukicoder/1097.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_add.cpp\"\ntemplate<typename X>\nstruct Group_Add\
    \ {\n  using value_type = X;\n  static constexpr X op(const X &x, const X &y)\
    \ noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, long long n) noexcept\
    \ { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct Group_Add {\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x + y; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_add.cpp
  requiredBy: []
  timestamp: '2022-09-07 12:14:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/yukicoder/1097.test.cpp
documentation_of: algebra/group_add.cpp
layout: document
redirect_from:
- /library/algebra/group_add.cpp
- /library/algebra/group_add.cpp.html
title: algebra/group_add.cpp
---

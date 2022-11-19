---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: tree/TreeMonoid.cpp
    title: tree/TreeMonoid.cpp
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"algebra/algebra_reverse.cpp\"\ntemplate<typename Algebra>\n\
    struct Algebra_Reverse:Algebra{\n  using X=typename Algebra::value_type;\n  static\
    \ constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n};\n"
  code: "template<typename Algebra>\nstruct Algebra_Reverse:Algebra{\n  using X=typename\
    \ Algebra::value_type;\n  static constexpr X op(const X& x, const X& y){ return\
    \ Algebra::op(y,x); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/algebra_reverse.cpp
  requiredBy:
  - tree/TreeMonoid.cpp
  timestamp: '2022-09-07 14:33:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
documentation_of: algebra/algebra_reverse.cpp
layout: document
redirect_from:
- /library/algebra/algebra_reverse.cpp
- /library/algebra/algebra_reverse.cpp.html
title: algebra/algebra_reverse.cpp
---

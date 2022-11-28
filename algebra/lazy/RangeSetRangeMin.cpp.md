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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid/Set.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"algebra/monoid/Min.cpp\"\n#include \"algebra/monoid/Set.cpp\"\
    \ntemplate<typename X>\nstruct LazyRangeSetRangeMin{\n  using MX=MonoidMin<X>;\n\
    \  using MF=MonoidSet<X>;\n  using F=typename MF::value_type;\n  static constexpr\
    \ X mapping(const F&f,const X&x){\n    return f.value_or(x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy/RangeSetRangeMin.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy/RangeSetRangeMin.cpp
layout: document
redirect_from:
- /library/algebra/lazy/RangeSetRangeMin.cpp
- /library/algebra/lazy/RangeSetRangeMin.cpp.html
title: algebra/lazy/RangeSetRangeMin.cpp
---

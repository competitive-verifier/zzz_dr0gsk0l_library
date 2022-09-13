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
  bundledCode: "#line 1 \"superstd/map.cpp\"\ntemplate<typename Key,typename Val>\n\
    struct Map:map<Key,Val>{\n  using map<Key,Val>::erase;\n\n  void operator()(Key\
    \ key,Val val){\n    if(!((*this)[key]+=val))erase(key);\n  }\n};\n"
  code: "template<typename Key,typename Val>\nstruct Map:map<Key,Val>{\n  using map<Key,Val>::erase;\n\
    \n  void operator()(Key key,Val val){\n    if(!((*this)[key]+=val))erase(key);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: superstd/map.cpp
  requiredBy: []
  timestamp: '2022-09-13 16:00:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: superstd/map.cpp
layout: document
redirect_from:
- /library/superstd/map.cpp
- /library/superstd/map.cpp.html
title: superstd/map.cpp
---

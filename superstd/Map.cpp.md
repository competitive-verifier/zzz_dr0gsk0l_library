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
  bundledCode: "#line 1 \"superstd/Map.cpp\"\ntemplate<typename Key,typename Val>\n\
    struct Map:map<Key,Val>{\n  using map<Key,Val>::erase;\n\n  void operator()(Key\
    \ key,Val val){\n    if(!((*this)[key]+=val))erase(key);\n  }\n};\n"
  code: "template<typename Key,typename Val>\nstruct Map:map<Key,Val>{\n  using map<Key,Val>::erase;\n\
    \n  void operator()(Key key,Val val){\n    if(!((*this)[key]+=val))erase(key);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: superstd/Map.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:34:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: superstd/Map.cpp
layout: document
redirect_from:
- /library/superstd/Map.cpp
- /library/superstd/Map.cpp.html
title: superstd/Map.cpp
---

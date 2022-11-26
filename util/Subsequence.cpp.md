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
  bundledCode: "#line 1 \"util/Subsequence.cpp\"\ntemplate<typename T,typename U>\n\
    T sparse_subsequence(const vector<U>&v){\n  map<U,T> mp;\n  T res=1;\n  for(U\
    \ p:v){\n    T tmp=res;\n    res=res*2-mp[p];\n    mp[p]=tmp;\n  }\n  return res;\n\
    }\n\ntemplate<typename T,typename SIZE>\nT subsequence(const vector<int>&v){\n\
    \  vector<T> memo(SIZE,0);\n  T res=1;\n  for(int p:v){\n    T tmp=res;\n    res=res*2-memo[p];\n\
    \    memo[p]=tmp;\n  }\n  return res;\n}\n\ntemplate<typename T>\nT subsequence_alphabet(const\
    \ string&s){\n  vector<int> v;v.reserve(s.size());\n  for(char c:s)v.push_back(c-(c<='Z'?'A':'a'));\n\
    \  return subsequence<T,26>(v);\n}\n"
  code: "template<typename T,typename U>\nT sparse_subsequence(const vector<U>&v){\n\
    \  map<U,T> mp;\n  T res=1;\n  for(U p:v){\n    T tmp=res;\n    res=res*2-mp[p];\n\
    \    mp[p]=tmp;\n  }\n  return res;\n}\n\ntemplate<typename T,typename SIZE>\n\
    T subsequence(const vector<int>&v){\n  vector<T> memo(SIZE,0);\n  T res=1;\n \
    \ for(int p:v){\n    T tmp=res;\n    res=res*2-memo[p];\n    memo[p]=tmp;\n  }\n\
    \  return res;\n}\n\ntemplate<typename T>\nT subsequence_alphabet(const string&s){\n\
    \  vector<int> v;v.reserve(s.size());\n  for(char c:s)v.push_back(c-(c<='Z'?'A':'a'));\n\
    \  return subsequence<T,26>(v);\n}"
  dependsOn: []
  isVerificationFile: false
  path: util/Subsequence.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:34:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/Subsequence.cpp
layout: document
redirect_from:
- /library/util/Subsequence.cpp
- /library/util/Subsequence.cpp.html
title: util/Subsequence.cpp
---

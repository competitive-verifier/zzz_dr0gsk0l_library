---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/Modint61.cpp
    title: mod/Modint61.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/RollingHash.cpp: line 2: #pragma once found in a non-first line\n"
  code: "// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n#pragma\
    \ once\n#include \"mod/Modint61.cpp\"\nrandom_device rollonghash_rnd;\nmt19937\
    \ rollonghash_mt(rollonghash_rnd());\nclass RollingHash{\n  using ll=long long;\n\
    \  inline static const Modint61 base=Modint61::raw(rollonghash_mt()%10000000+2);\n\
    \n  static Modint61 nxt_hash(Modint61 x,char c){ return (x*base)+Modint61::raw(c);\
    \ }\n\n  vector<Modint61> hash,power;\n  int n;\npublic:\n  RollingHash(const\
    \ string&s):n(s.size()),hash(s.size()+1,0),power(s.size()+1,1){\n    for(int i=0;i<n;i++){\n\
    \      hash[i+1]=nxt_hash(hash[i],s[i]);\n      power[i+1]=power[i]*base;\n  \
    \  }\n  }\n  \n  ll get_hash(int l=0,int r=-1){\n    if(r<0)r=n;\n    return (hash[r]-hash[l]*power[r-l]).v;\n\
    \  }\n  \n  static ll full_hash(const string&s){\n    Modint61 res=0;\n    for(const\
    \ char&c:s)res=nxt_hash(res,c);\n    return res.v;\n  }\n};"
  dependsOn:
  - mod/Modint61.cpp
  isVerificationFile: false
  path: string/RollingHash.cpp
  requiredBy: []
  timestamp: '2022-12-02 18:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: string/RollingHash.cpp
layout: document
redirect_from:
- /library/string/RollingHash.cpp
- /library/string/RollingHash.cpp.html
title: string/RollingHash.cpp
---

---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"string/rollinghash.cpp\"\n// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    random_device rollonghash_rnd;\nmt19937 rollonghash_mt(rollonghash_rnd());\nclass\
    \ RollingHash{\n  using ull=unsigned long long;\n  static const ull MASK30=(1ull<<30)-1;\n\
    \  static const ull MASK31=(1ull<<31)-1;\n  static const ull MOD=(1ull<<61)-1;\n\
    \  static const ull BIGM=MOD*4;\n  \n  inline static const ull base = rollonghash_mt()%10000000+2;\n\
    \n  static ull mul(ull a,ull b){\n    ull au=a>>31, ad=a&MASK31, bu=b>>31, bd=b&MASK31;\n\
    \    ull mid= ad*bu + au*bd;\n    ull midu=mid>>30,midd=mid&MASK30;\n    return\
    \ au*bu*2 + midu + (midd<<31) + ad*bd;\n  }\n  static ull calc_mod(ull x){\n \
    \   ull xu=x>>61, xd=x&MOD;\n    ull res=xu+xd;\n    return (res<MOD?res:res-MOD);\n\
    \  }\n  static ull nxt_hash(ull x,char c){ return calc_mod(mul(x,base)+(int)c);\
    \ }\n\n  vector<ull> hash,power;\n  int n;\npublic:\n  RollingHash(const string&s):n(s.size()),hash(s.size()+1,0),power(s.size()+1,1){\n\
    \    for(int i=0;i<n;i++){\n      hash[i+1]=nxt_hash(hash[i],s[i]);\n      power[i+1]=calc_mod(mul(power[i],base));\n\
    \    }\n  }\n  \n  ull get_hash(int l=0,int r=-1){\n    if(r<0)r=n;\n    return\
    \ calc_mod(hash[r]+BIGM-mul(hash[l],power[r-l]));\n  }\n  \n  static ull full_hash(const\
    \ string&s){\n    ull res=0;\n    for(const char&c:s)res=nxt_hash(res,c);\n  \
    \  return res;\n  }\n};\n"
  code: "// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\nrandom_device\
    \ rollonghash_rnd;\nmt19937 rollonghash_mt(rollonghash_rnd());\nclass RollingHash{\n\
    \  using ull=unsigned long long;\n  static const ull MASK30=(1ull<<30)-1;\n  static\
    \ const ull MASK31=(1ull<<31)-1;\n  static const ull MOD=(1ull<<61)-1;\n  static\
    \ const ull BIGM=MOD*4;\n  \n  inline static const ull base = rollonghash_mt()%10000000+2;\n\
    \n  static ull mul(ull a,ull b){\n    ull au=a>>31, ad=a&MASK31, bu=b>>31, bd=b&MASK31;\n\
    \    ull mid= ad*bu + au*bd;\n    ull midu=mid>>30,midd=mid&MASK30;\n    return\
    \ au*bu*2 + midu + (midd<<31) + ad*bd;\n  }\n  static ull calc_mod(ull x){\n \
    \   ull xu=x>>61, xd=x&MOD;\n    ull res=xu+xd;\n    return (res<MOD?res:res-MOD);\n\
    \  }\n  static ull nxt_hash(ull x,char c){ return calc_mod(mul(x,base)+(int)c);\
    \ }\n\n  vector<ull> hash,power;\n  int n;\npublic:\n  RollingHash(const string&s):n(s.size()),hash(s.size()+1,0),power(s.size()+1,1){\n\
    \    for(int i=0;i<n;i++){\n      hash[i+1]=nxt_hash(hash[i],s[i]);\n      power[i+1]=calc_mod(mul(power[i],base));\n\
    \    }\n  }\n  \n  ull get_hash(int l=0,int r=-1){\n    if(r<0)r=n;\n    return\
    \ calc_mod(hash[r]+BIGM-mul(hash[l],power[r-l]));\n  }\n  \n  static ull full_hash(const\
    \ string&s){\n    ull res=0;\n    for(const char&c:s)res=nxt_hash(res,c);\n  \
    \  return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.cpp
  requiredBy: []
  timestamp: '2022-09-21 11:15:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: string/rollinghash.cpp
layout: document
redirect_from:
- /library/string/rollinghash.cpp
- /library/string/rollinghash.cpp.html
title: string/rollinghash.cpp
---

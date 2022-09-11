---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/ahocorasick.cpp
    title: AhoCorasick
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/trie.cpp\"\ntemplate<int char_size,int margin>\n\
    struct Trie{\n  struct Node{\n    array<int,char_size> nxt;\n    int pre,//\u624B\
    \u524D\n        count,//\u81EA\u5206\u306E\u500B\u6570\n        ancestor_count;//\uFF08\
    \u81EA\u5206\u3092\u542B\u307E\u306A\u3044\uFF09\u5B50\u5B6B\u306E\u500B\u6570\
    \n    Node(int pre):pre(pre),count(0),ancestor_count(0){\n      fill(nxt.begin(),nxt.end(),-1);\n\
    \    }\n  };\n \n  vector<Node> nodes;\n  Trie():nodes(1,Node(-1)){}\n  \n  inline\
    \ int& nxt(int now,int c){\n    return nodes[now].nxt[c-margin];\n  }\n \n  int\
    \ add(const string&s,int num=1){\n    int now=0;\n    for(const char&c:s){\n \
    \     if(!~nxt(now,c)){\n        nxt(now,c)=nodes.size();\n        nodes.emplace_back(Node(now));\n\
    \      }\n      nodes[now].ancestor_count+=num;\n      now=nxt(now,c);\n    }\n\
    \    nodes[now].count+=num;\n    return now;\n  }\n \n  int node_idx(const string&s){\n\
    \    // s \u306E Node \u3092\u8FD4\u3059\u3000\u8FFD\u52A0\u3055\u308C\u3066\u7121\
    \u3051\u308C\u3070 -1\n    int now=0;\n    for(const char&c:s){\n      if(!~nxt(now,c))return\
    \ -1;\n      now=nxt(now,c);\n    }\n    return now;\n  }\n \n  int count(const\
    \ string&s){\n    int a=node_idx(s);\n    return (~a?nodes[a].count:0);\n  }\n\
    \ \n  //s\u306F\u542B\u307E\u306A\u3044\n  int preifx_count(const string&s){\n\
    \    int now=0,sum=0;\n    for(const char&c:s){\n      if(!~nxt(now,c))break;\n\
    \      sum+=nodes[now].count;\n      now=nxt(now,c);\n    }\n    return sum;\n\
    \  }\n \n  //s\u306F\u542B\u307E\u306A\u3044\n  int ancestor_count(const string&s){\n\
    \    int a=node_idx(s);\n    return (~a?nodes[a].ancestor_count:0);\n  }\n};\n"
  code: "template<int char_size,int margin>\nstruct Trie{\n  struct Node{\n    array<int,char_size>\
    \ nxt;\n    int pre,//\u624B\u524D\n        count,//\u81EA\u5206\u306E\u500B\u6570\
    \n        ancestor_count;//\uFF08\u81EA\u5206\u3092\u542B\u307E\u306A\u3044\uFF09\
    \u5B50\u5B6B\u306E\u500B\u6570\n    Node(int pre):pre(pre),count(0),ancestor_count(0){\n\
    \      fill(nxt.begin(),nxt.end(),-1);\n    }\n  };\n \n  vector<Node> nodes;\n\
    \  Trie():nodes(1,Node(-1)){}\n  \n  inline int& nxt(int now,int c){\n    return\
    \ nodes[now].nxt[c-margin];\n  }\n \n  int add(const string&s,int num=1){\n  \
    \  int now=0;\n    for(const char&c:s){\n      if(!~nxt(now,c)){\n        nxt(now,c)=nodes.size();\n\
    \        nodes.emplace_back(Node(now));\n      }\n      nodes[now].ancestor_count+=num;\n\
    \      now=nxt(now,c);\n    }\n    nodes[now].count+=num;\n    return now;\n \
    \ }\n \n  int node_idx(const string&s){\n    // s \u306E Node \u3092\u8FD4\u3059\
    \u3000\u8FFD\u52A0\u3055\u308C\u3066\u7121\u3051\u308C\u3070 -1\n    int now=0;\n\
    \    for(const char&c:s){\n      if(!~nxt(now,c))return -1;\n      now=nxt(now,c);\n\
    \    }\n    return now;\n  }\n \n  int count(const string&s){\n    int a=node_idx(s);\n\
    \    return (~a?nodes[a].count:0);\n  }\n \n  //s\u306F\u542B\u307E\u306A\u3044\
    \n  int preifx_count(const string&s){\n    int now=0,sum=0;\n    for(const char&c:s){\n\
    \      if(!~nxt(now,c))break;\n      sum+=nodes[now].count;\n      now=nxt(now,c);\n\
    \    }\n    return sum;\n  }\n \n  //s\u306F\u542B\u307E\u306A\u3044\n  int ancestor_count(const\
    \ string&s){\n    int a=node_idx(s);\n    return (~a?nodes[a].ancestor_count:0);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy:
  - string/ahocorasick.cpp
  timestamp: '2022-09-11 17:55:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.cpp
layout: document
redirect_from:
- /library/string/trie.cpp
- /library/string/trie.cpp.html
title: string/trie.cpp
---

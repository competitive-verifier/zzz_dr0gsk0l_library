---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/Trie.cpp
    title: string/Trie.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/Trie.cpp\"\ntemplate<int char_size,int margin>\n\
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
    \    int a=node_idx(s);\n    return (~a?nodes[a].ancestor_count:0);\n  }\n};\n\
    #line 2 \"string/AhoCorasick.cpp\"\n\ntemplate<int char_size,int margin>\nstruct\
    \ AhoCorasick:Trie<char_size,margin>{\n  using super=Trie<char_size,margin>;\n\
    \  using super::nodes,super::nxt;\n  \n  vector<int> suffix;\n \n  void build(){\n\
    \    suffix.resize(nodes.size());\n    queue<int> que;\n    que.emplace(0);\n\
    \    while(que.size()){\n      int now=que.front();que.pop();\n      for(int i=0;i<char_size;i++){\n\
    \        int&nxt_id=nodes[now].nxt[i];\n        if(~nxt_id){\n          suffix[nxt_id]=(now?nodes[suffix[now]].nxt[i]:0);\n\
    \          que.push(nxt_id);\n        }\n        else nxt_id=(now?nodes[suffix[now]].nxt[i]:0);\n\
    \      }\n    }\n  }\n \n  int match_count(const string&s){\n    int res=0,now=0;\n\
    \    for(const char&c:s){\n      now=nxt(now,c);\n      res+=nodes[now].count;\n\
    \    }\n    return res;\n  }\n};\n"
  code: "#include \"string/Trie.cpp\"\n\ntemplate<int char_size,int margin>\nstruct\
    \ AhoCorasick:Trie<char_size,margin>{\n  using super=Trie<char_size,margin>;\n\
    \  using super::nodes,super::nxt;\n  \n  vector<int> suffix;\n \n  void build(){\n\
    \    suffix.resize(nodes.size());\n    queue<int> que;\n    que.emplace(0);\n\
    \    while(que.size()){\n      int now=que.front();que.pop();\n      for(int i=0;i<char_size;i++){\n\
    \        int&nxt_id=nodes[now].nxt[i];\n        if(~nxt_id){\n          suffix[nxt_id]=(now?nodes[suffix[now]].nxt[i]:0);\n\
    \          que.push(nxt_id);\n        }\n        else nxt_id=(now?nodes[suffix[now]].nxt[i]:0);\n\
    \      }\n    }\n  }\n \n  int match_count(const string&s){\n    int res=0,now=0;\n\
    \    for(const char&c:s){\n      now=nxt(now,c);\n      res+=nodes[now].count;\n\
    \    }\n    return res;\n  }\n};"
  dependsOn:
  - string/Trie.cpp
  isVerificationFile: false
  path: string/AhoCorasick.cpp
  requiredBy: []
  timestamp: '2022-11-26 09:34:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/AhoCorasick.cpp
layout: document
redirect_from:
- /library/string/AhoCorasick.cpp
- /library/string/AhoCorasick.cpp.html
title: string/AhoCorasick.cpp
---

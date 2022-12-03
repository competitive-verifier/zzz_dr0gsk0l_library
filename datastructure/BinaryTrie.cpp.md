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
  bundledCode: "#line 1 \"datastructure/BinaryTrie.cpp\"\ntemplate<int LOG>\nstruct\
    \ BinaryTrie{\n  struct Node{\n    array<int,2> nxt;\n    int pre,//\u624B\u524D\
    \n        count,//\u81EA\u5206\u306E\u500B\u6570\n        ancestor_count;//\uFF08\
    \u81EA\u5206\u3092\u542B\u307E\u306A\u3044\uFF09\u5B50\u5B6B\u306E\u500B\u6570\
    \n    Node(int pre):pre(pre),count(0),ancestor_count(0){\n      fill(nxt.begin(),nxt.end(),-1);\n\
    \    }\n  };\n};\n"
  code: "template<int LOG>\nstruct BinaryTrie{\n  struct Node{\n    array<int,2> nxt;\n\
    \    int pre,//\u624B\u524D\n        count,//\u81EA\u5206\u306E\u500B\u6570\n\
    \        ancestor_count;//\uFF08\u81EA\u5206\u3092\u542B\u307E\u306A\u3044\uFF09\
    \u5B50\u5B6B\u306E\u500B\u6570\n    Node(int pre):pre(pre),count(0),ancestor_count(0){\n\
    \      fill(nxt.begin(),nxt.end(),-1);\n    }\n  };\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2022-12-03 17:21:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/BinaryTrie.cpp
layout: document
redirect_from:
- /library/datastructure/BinaryTrie.cpp
- /library/datastructure/BinaryTrie.cpp.html
title: datastructure/BinaryTrie.cpp
---

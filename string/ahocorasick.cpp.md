---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/trie.cpp
    title: string/trie.cpp
  _extendedRequiredBy: []
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
    \    int a=node_idx(s);\n    return (~a?nodes[a].ancestor_count:0);\n  }\n};\n\
    #line 2 \"string/ahocorasick.cpp\"\n\ntemplate<int char_size,int margin>\nstruct\
    \ AhoCorasick:Trie<char_size,margin>{\n  using super=Trie<char_size,margin>;\n\
    \  using super::nodes,super::nxt;\n  \n  vector<int> suffix;\n \n  void build(){\n\
    \    suffix.resize(nodes.size());\n    queue<int> que;\n    que.emplace(0);\n\
    \    while(que.size()){\n      int now=que.front();que.pop();\n      for(int i=0;i<char_size;i++){\n\
    \        int&nxt_id=nodes[now].nxt[i];\n        if(~nxt_id){\n          suffix[nxt_id]=(now?nodes[suffix[now]].nxt[i]:0);\n\
    \          que.push(nxt_id);\n        }\n        else nxt_id=(now?nodes[suffix[now]].nxt[i]:0);\n\
    \      }\n    }\n  }\n \n  int match_count(const string&s){\n    int res=0,now=0;\n\
    \    for(const char&c:s){\n      now=nxt(now,c);\n      res+=nodes[now].count;\n\
    \    }\n    return res;\n  }\n};\n"
  code: "#include \"string/trie.cpp\"\n\ntemplate<int char_size,int margin>\nstruct\
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
  - string/trie.cpp
  isVerificationFile: false
  path: string/ahocorasick.cpp
  requiredBy: []
  timestamp: '2022-09-11 17:55:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/ahocorasick.cpp
layout: document
title: AhoCorasick
---
* ```add(const string&s,int num=1)```  
文字列 $s$ を $num$ 個追加
$O(|s|)$

* ```void build()```  
文字列の追加後ちょうど一回だけ呼び出す  
計算量は Trie 木の Node の個数（char_size 程度の定数倍がかかる）

* ```vector<int> suffix```  
```suffix[v]:```Trie 木内に存在する文字列であって、 Node $v$ の表す文字列の suffix である最長のもの（の Node のインデックス）

* ```int match_count(const string&s)```  
$ \sum_{(l,r)} s[l,r)$ の個数 

## 概要
文字列集合 $S$ から、「 $t$ の部分文字列に $S$ の元はあるか」と言うクエリに答えられるデータ構造を作りたい  

### 例
>$S=\{abcdt,bcdfg,cdefg\}$  
>$t_1=abcdefgh$ (Yes)  
>$t_2=abcdefh$ (No)  


$S$ から自然に Trie 木を作ると、各 $t.substr(i)$ について Trie 木を辿ることでクエリを $O(|t|^2)$ で捌く事ができる  

例で $t_1$ を探索する場合 ```abcd``` まで行って ```e``` で諦めることになるが、ここで AhoCorasick は ```cde``` から探索を再開させる

より一般には、文字列 $t$ の Node が存在しなかった場合、**存在する Node のうち $t$ の最長 suffix から再開する**  

これを実現するようなオートマトンを作ればよく、Trie 木上で BFS 順に必要な情報を埋めていくことで簡単に達成できる
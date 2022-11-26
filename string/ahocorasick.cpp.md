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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/Trie.cpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: string/ahocorasick.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
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
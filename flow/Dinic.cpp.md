---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://misawa.github.io/others/flow/dinic_time_complexity.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/Dinic.cpp: line 2: #pragma once found in a non-first line\n"
  code: "// https://misawa.github.io/others/flow/dinic_time_complexity.html\n#pragma\
    \ once\n#include \"graph/WeightedGraph.cpp\"\ntemplate<typename T>\nclass Dinic{\n\
    \  struct EdgeInfo{\n    T cap;\n    int rev;\n  };\n  int n;\n  WeightedGraph<\
    \ EdgeInfo > G;\n  vector<int> level,current_edge,out_deg;\n  int s,t;\n  queue<int>\
    \ que;\n\n  void bfs(){\n    //level[v]\u3092\uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\
    \u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\u306B\u3059\
    \u308B \u5230\u9054\u51FA\u6765\u306A\u3051\u308C\u3070-1\n    fill(level.begin(),level.end(),-1);\n\
    \    level[s]=0;\n    que.emplace(s);\n    while(que.size()){\n      int v=que.front();que.pop();\n\
    \      for(const auto&e:G[v]){\n        const auto&[cap,rev]=e.weight;\n     \
    \   if(cap==0||~level[e.to])continue;\n        level[e.to]=level[v]+1;\n     \
    \   que.emplace(e.to);\n      }\n    }\n  }\n  T dfs(int v,T f){\n    //v\u304B\
    \u3089t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\u3092\u6D41\u3059 f\u304Cv\u307E\u3067\
    \u6301\u3063\u3066\u3053\u308C\u305F\u6C34\u91CF \u6D41\u305B\u305F\u91CF\u304C\
    \u8FD4\u308A\u5024\n    if(v==t)return f;\n    for(int &i=current_edge[v];i<G[v].size();i++){//\u3053\
    \u306Edfs\u3067\u4F7F\u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\
    \u3067\u4F7F\u308F\u308C\u308B\u3053\u3068\u306F\u306A\u3044\n      auto&e=G[v][i];\n\
    \      auto&[cap,rev]=e.weight;\n      if(cap>0&&level[v]<level[e.to]){//bfs\u3092\
    \u3057\u3066\u3044\u308B\u306E\u3067level[v]<level[e.to]\u306A\u3089level[v]+1==level[e.to]\n\
    \        T d=dfs(e.to,min(f,cap));\n        if(d==0)continue;\n        cap-=d;\n\
    \        G[e.to][rev].weight.cap+=d;\n        return d;//\u4E00\u672C\u6D41\u305B\
    \u305F\u3089return\n      }\n    }\n    return 0;\n  }\npublic:\n  Dinic()=default;\n\
    \  Dinic(int n,int s,int t):G(n),level(n),current_edge(n),out_deg(n,0),s(s),t(t){}\n\
    \n  void add_arc(int from,int to,T cap){\n    G.add_arc(from,to,{cap,out_deg[to]});\n\
    \    G.add_arc(to,from,{0,out_deg[from]});\n    out_deg[from]++;out_deg[to]++;\n\
    \  }\n  T flow(T lim){\n    if(!G.is_prepared())G.build();\n    T fl=0;\n    while(lim>0){\n\
    \      bfs();\n      if(level[t]<0)break;\n      fill(current_edge.begin(),current_edge.end(),0);\n\
    \      while(true){\n        T f=dfs(s,lim);\n        if(f==0)break;\n       \
    \ fl+=f;\n        lim-=f;\n      }\n    }\n    return fl;\n  }\n  T flow(){ return\
    \ flow(numeric_limits<T>::max()/2); }\n  \n  T st_flow(int s_,int t_,T lim){ s=s_;t=t_;\
    \ return flow(lim);}\n  T st_flow(int s_,int t_){ s=s_;t=t_; return flow(); }\n\
    };"
  dependsOn:
  - graph/WeightedGraph.cpp
  isVerificationFile: false
  path: flow/Dinic.cpp
  requiredBy: []
  timestamp: '2022-12-01 20:59:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_6_A.test.cpp
documentation_of: flow/Dinic.cpp
layout: document
redirect_from:
- /library/flow/Dinic.cpp
- /library/flow/Dinic.cpp.html
title: flow/Dinic.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://misawa.github.io/others/flow/dinic_time_complexity.html
  bundledCode: "#line 1 \"flow/dinic.cpp\"\n// https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    template<typename T>\nclass Dinic{\n  struct edge{\n    const int to,rev;\n  \
    \  T cap;\n    edge(){}\n    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}\
    \ \n  };\n  vector<vector<edge>> G;\n  vector<int> lavel,current_edge;\n  int\
    \ s,t;\n\n  void bfs(){\n    //lavel[v]\u3092\uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\
    \u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\u306B\u3059\
    \u308B \u5230\u9054\u51FA\u6765\u306A\u3051\u308C\u3070-1\n    fill(lavel.begin(),lavel.end(),-1);\n\
    \    queue<int> que;\n    lavel[s]=0;\n    que.emplace(s);\n    while(que.size()){\n\
    \      int v=que.front();que.pop();\n      for(const auto&e:G[v]){\n        if(e.cap==0||~lavel[e.to])continue;\n\
    \        lavel[e.to]=lavel[v]+1;\n        que.emplace(e.to);\n      }\n    }\n\
    \  }\n  T dfs(int v,T f){\n    //v\u304B\u3089t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\
    \u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\u3063\u3066\u3053\u308C\u305F\u6C34\
    \u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\u308A\u5024\n    if(v==t)return f;\n\
    \    for(int &i=current_edge[v];i<G[v].size();i++){//\u3053\u306Edfs\u3067\u4F7F\
    \u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\u308F\
    \u308C\u308B\u3053\u3068\u306F\u306A\u3044\n      edge &e=G[v][i];\n      if(e.cap>0&&lavel[v]<lavel[e.to]){//bfs\u3092\
    \u3057\u3066\u3044\u308B\u306E\u3067lavel[v]<lavel[e.to]\u306A\u3089lavel[v]+1==lavel[e.to]\n\
    \        T d=dfs(e.to,min(f,e.cap));\n        if(d==0)continue;\n        e.cap-=d;\n\
    \        G[e.to][e.rev].cap+=d;\n        return d;//\u4E00\u672C\u6D41\u305B\u305F\
    \u3089return\n      }\n    }\n    return 0;\n  }\npublic:\n  Dinic()=default;\n\
    \  Dinic(int n,int s,int t):G(n),lavel(n),current_edge(n),s(s),t(t){}\n\n  void\
    \ add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,0,G[from].size()-1);\n  }\n  T flow(T lim){\n   \
    \ T fl=0;\n    while(lim>0){\n      bfs();\n      if(lavel[t]<0)break;\n     \
    \ fill(current_edge.begin(),current_edge.end(),0);\n      while(true){\n     \
    \   T f=dfs(s,lim);\n        if(f==0)break;\n        fl+=f;\n        lim-=f;\n\
    \      }\n    }\n    return fl;\n  }\n  T flow(){ return flow(numeric_limits<T>::max()/2);\
    \ }\n  \n  T st_flow(int s_,int t_,T lim){ s=s_;t=t_; return flow(lim);}\n  T\
    \ st_flow(int s_,int t_){ s=s_;t=t_; return flow(); }\n};\n"
  code: "// https://misawa.github.io/others/flow/dinic_time_complexity.html\ntemplate<typename\
    \ T>\nclass Dinic{\n  struct edge{\n    const int to,rev;\n    T cap;\n    edge(){}\n\
    \    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){} \n  };\n  vector<vector<edge>>\
    \ G;\n  vector<int> lavel,current_edge;\n  int s,t;\n\n  void bfs(){\n    //lavel[v]\u3092\
    \uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\u306B\u3059\u308B \u5230\u9054\u51FA\u6765\u306A\u3051\
    \u308C\u3070-1\n    fill(lavel.begin(),lavel.end(),-1);\n    queue<int> que;\n\
    \    lavel[s]=0;\n    que.emplace(s);\n    while(que.size()){\n      int v=que.front();que.pop();\n\
    \      for(const auto&e:G[v]){\n        if(e.cap==0||~lavel[e.to])continue;\n\
    \        lavel[e.to]=lavel[v]+1;\n        que.emplace(e.to);\n      }\n    }\n\
    \  }\n  T dfs(int v,T f){\n    //v\u304B\u3089t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\
    \u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\u3063\u3066\u3053\u308C\u305F\u6C34\
    \u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\u308A\u5024\n    if(v==t)return f;\n\
    \    for(int &i=current_edge[v];i<G[v].size();i++){//\u3053\u306Edfs\u3067\u4F7F\
    \u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\u308F\
    \u308C\u308B\u3053\u3068\u306F\u306A\u3044\n      edge &e=G[v][i];\n      if(e.cap>0&&lavel[v]<lavel[e.to]){//bfs\u3092\
    \u3057\u3066\u3044\u308B\u306E\u3067lavel[v]<lavel[e.to]\u306A\u3089lavel[v]+1==lavel[e.to]\n\
    \        T d=dfs(e.to,min(f,e.cap));\n        if(d==0)continue;\n        e.cap-=d;\n\
    \        G[e.to][e.rev].cap+=d;\n        return d;//\u4E00\u672C\u6D41\u305B\u305F\
    \u3089return\n      }\n    }\n    return 0;\n  }\npublic:\n  Dinic()=default;\n\
    \  Dinic(int n,int s,int t):G(n),lavel(n),current_edge(n),s(s),t(t){}\n\n  void\
    \ add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,0,G[from].size()-1);\n  }\n  T flow(T lim){\n   \
    \ T fl=0;\n    while(lim>0){\n      bfs();\n      if(lavel[t]<0)break;\n     \
    \ fill(current_edge.begin(),current_edge.end(),0);\n      while(true){\n     \
    \   T f=dfs(s,lim);\n        if(f==0)break;\n        fl+=f;\n        lim-=f;\n\
    \      }\n    }\n    return fl;\n  }\n  T flow(){ return flow(numeric_limits<T>::max()/2);\
    \ }\n  \n  T st_flow(int s_,int t_,T lim){ s=s_;t=t_; return flow(lim);}\n  T\
    \ st_flow(int s_,int t_){ s=s_;t=t_; return flow(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/dinic.cpp
  requiredBy: []
  timestamp: '2022-09-09 16:16:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/dinic.cpp
layout: document
redirect_from:
- /library/flow/dinic.cpp
- /library/flow/dinic.cpp.html
title: flow/dinic.cpp
---

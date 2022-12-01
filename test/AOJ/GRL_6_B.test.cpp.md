---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/MCF.cpp
    title: flow/MCF.cpp
  - icon: ':heavy_check_mark:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/AOJ/GRL_6_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/WeightedGraph.cpp\"\
    \ntemplate<typename T>\nstruct WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int\
    \ from,int to,T weight):from(from),to(to),weight(weight){}\n  int from,to;\n \
    \ T weight;\n};\n\ntemplate<typename T>\nstruct WeightedGraph{\n  int n;\n  using\
    \ weight_type=T;\n  using edge_type=WeightedEdge<T>;\n  vector<edge_type> edges;\n\
    protected:\n  vector<int> in_deg;\n  bool prepared;\n  class OutgoingEdges{\n\
    \    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]);\
    \ }\n    edge_type* end(){ return &(g->edges[r]); }\n    edge_type& operator[](int\
    \ i){ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\npublic:\n\
    \  OutgoingEdges operator[](int v){\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1]\
    \ };\n  }\n\n  bool is_prepared()const{ return prepared; }\n\n  WeightedGraph():n(0),in_deg(1,0),prepared(false){}\n\
    \  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  WeightedGraph(int\
    \ n,int m,bool directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){\
    \ scan(m,directed,indexed); }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int\
    \ from,int to,T weight){\n    assert(!prepared);\n    assert(0<=from and from<n\
    \ and 0<=to and to<n);\n    edges.emplace_back(from,to,weight);\n    in_deg[from+1]++;\n\
    \  }\n  void add_edge(int u,int v,T weight){\n    add_arc(u,v,weight);\n    add_arc(v,u,weight);\n\
    \  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n    edges.reserve(directed?m:2*m);\n\
    \    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      T weight;cin>>weight;\n\
    \      if(directed)add_arc(u,v,weight);\n      else add_edge(u,v,weight);\n  \
    \  }\n    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<\"(\"<<edges[i].to<<\",\"<<edges[i].weight<<\")\";\n      cerr<<\"\
    \\n\";\n    }\n  }\n};\n#line 3 \"flow/MCF.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
    template<typename TF,typename TC>\nclass MCF{\n  struct EdgeInfo{\n    TF cap;\n\
    \    TC cost;\n    int rev;\n  };\n  int n;\n  WeightedGraph< EdgeInfo > G;\n\
    \  vector<TC> potential,dist;\n  static constexpr TC INF=numeric_limits<TC>::max()/2;\n\
    \  vector<pair<int,int>> pre; // pre[v]=[u,i] : G[u][i] \u3067 v \u306B\u6765\u305F\
    \n  vector<int> in_deg,out_deg;\n  priority_queue< pair<TC,int>,vector<pair<TC,int>>,greater<pair<TC,int>>>\
    \ que;\n  bool negative=false;//\u8CA0\u8FBA\u5B58\u5728\u3059\u308B\u304B\n\n\
    \  template<typename T>\n  bool chmin(T&a,const T&b){\n    return (a>b and (a=b,true));\n\
    \  }\n  bool SP_update(int from,int edge_id){\n    const auto&e=G[from][edge_id];\n\
    \    if((e.weight).cap==0)return false;\n    if(chmin(dist[e.to],dist[from]+(e.weight).cost+potential[from]-potential[e.to])){\n\
    \      pre[e.to]={from,edge_id};\n      return true;\n    }\n    return false;\n\
    \  }\n\n  void dijkstra(int s){//dist[i]:s\u304B\u3089\u6B8B\u4F59\u30B0\u30E9\
    \u30D5\u3067\u8FBA\u306E\u91CD\u307F\u306B\u3088\u308Bi\u3078\u306E\u6700\u77ED\
    \u8DEF \u3068\u306A\u308B\u3088\u3046\u306Bdist\u3092\u4F5C\u308B\n    fill(dist.begin(),dist.end(),INF);\n\
    \    dist[s]=0;\n    que.emplace(0,s);\n    while(que.size()){\n      const auto\
    \ [now,v]=que.top();que.pop();\n      if(dist[v]<now)continue;\n      REP_(i,G[v].size())\n\
    \        if(SP_update(v,i))\n          que.emplace(dist[G[v][i].to],G[v][i].to);\n\
    \    }\n  }\n\n  void DAG(int s){\n    negative=false;\n    fill(dist.begin(),dist.end(),INF);\n\
    \    dist[s]=0;\n    queue<int> que;\n    REP_(i,n)if(!in_deg[i])que.push(i);\n\
    \    while(que.size()){\n      int v=que.front();que.pop();\n      REP_(i,G[v].size()){\n\
    \        SP_update(v,i);\n        if(!--in_deg[G[v][i].to])que.push(G[v][i].to);\n\
    \      }\n    }\n  }\npublic:\n  MCF(){}\n  MCF(int n_):n(n_),G(n_),potential(n_,0),dist(n_),pre(n_),in_deg(n_,0),out_deg(n_,0),negative(false){}\n\
    \  \n  void add_arc(int u,int v,TF cap,TC cost){\n    G.add_arc(u,v,{cap,cost,out_deg[v]});\n\
    \    G.add_arc(v,u,{0,-cost,out_deg[u]});\n    out_deg[v]++;out_deg[u]++;\n  \
    \  if(cap>0){\n      in_deg[v]++;\n      negative|=cost<0;\n    }\n  }\n \n  pair<TC,bool>\
    \ flow(int s,int t,TF f){//second \u304C 0 \u3067\u8FD4\u3063\u3066\u304D\u305F\
    \u5834\u5408\u306F\u305D\u3082\u305D\u3082\u6700\u5927\u6D41\u304Cf\u306B\u9054\
    \u3057\u306A\u3044\n    if(!G.is_prepared())G.build();\n    TC res=0;\n    fill(potential.begin(),potential.end(),0);//\u4E00\
    \u756A\u6700\u521D\u306F\u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u7121\
    \u3044\u304B\u3089\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F0\u306B\u3057\u3066\
    \u3044\u3044\n    while(f>0){\n      if(negative)DAG(s);\n      else dijkstra(s);\n\
    \      if(dist[t]==INF)return pair<TC,bool>(res,false);\n      REP_(v,n)if(dist[v]<INF)potential[v]+=dist[v];\n\
    \      TF d=f;//d:\u4ECA\u56DE\u6D41\u3059\u91CF\n      for(int v=t;v!=s;v=pre[v].first)chmin(d,(G[pre[v].first][pre[v].second].weight).cap);\n\
    \      f-=d;\n      res+=potential[t]*d;\n      for(int v=t;v!=s;v=pre[v].first){\n\
    \        auto&[cap,cost,rev]=G[pre[v].first][pre[v].second].weight;\n        cap-=d;\n\
    \        (G[v][rev].weight).cap+=d;\n      }\n    }//\u3053\u306E\u30EB\u30FC\u30D7\
    \u3092\u629C\u3051\u3066\u308B\u306A\u3089f\u6D41\u308C\u3066\u308B\n    return\
    \ pair<TC,bool>(res,true);\n  }\n};\n#undef REP_\n#line 6 \"test/AOJ/GRL_6_B.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,m,f;cin>>n>>m>>f;\n  MCF<int,int> fl(n);\n  while(m--){\n    int u,v,c,d;cin>>u>>v>>c>>d;\n\
    \    fl.add_arc(u,v,c,d);\n  }\n  auto [ans,ok]=fl.flow(0,n-1,f);\n  cout<< (ok?ans:-1)\
    \ <<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"flow/MCF.cpp\"\n\
    \nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n,m,f;cin>>n>>m>>f;\n\
    \  MCF<int,int> fl(n);\n  while(m--){\n    int u,v,c,d;cin>>u>>v>>c>>d;\n    fl.add_arc(u,v,c,d);\n\
    \  }\n  auto [ans,ok]=fl.flow(0,n-1,f);\n  cout<< (ok?ans:-1) <<endl;\n}"
  dependsOn:
  - flow/MCF.cpp
  - graph/WeightedGraph.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 12:04:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_6_B.test.cpp
- /verify/test/AOJ/GRL_6_B.test.cpp.html
title: test/AOJ/GRL_6_B.test.cpp
---

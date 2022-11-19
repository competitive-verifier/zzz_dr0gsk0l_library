---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/algebra_reverse.cpp
    title: algebra/algebra_reverse.cpp
  - icon: ':question:'
    path: algebra/group_add.cpp
    title: algebra/group_add.cpp
  - icon: ':x:'
    path: graph/Graph.cpp
    title: graph/Graph.cpp
  - icon: ':question:'
    path: segtree/segtree.cpp
    title: segtree/segtree.cpp
  - icon: ':x:'
    path: tree/TreeMonoid.cpp
    title: tree/TreeMonoid.cpp
  - icon: ':x:'
    path: tree/hld.cpp
    title: tree/hld.cpp
  - icon: ':x:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/library-checker/Tree/vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"algebra/group_add.cpp\"\
    \ntemplate<typename X>\nstruct Group_Add {\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x + y; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 1 \"algebra/algebra_reverse.cpp\"\ntemplate<typename Algebra>\nstruct Algebra_Reverse:Algebra{\n\
    \  using X=typename Algebra::value_type;\n  static constexpr X op(const X& x,\
    \ const X& y){ return Algebra::op(y,x); }\n};\n#line 1 \"segtree/segtree.cpp\"\
    \ntemplate<class Monoid>\nstruct SegmentTree{\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vector<X> dat;\n  int n, log, size;\n\n  SegmentTree()\
    \ : SegmentTree(0) {}\n  SegmentTree(int n) : SegmentTree(vector<X>(n, Monoid::unit()))\
    \ {}\n  SegmentTree(vector<X> v) : n(v.size()) {\n    log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  X operator[](int i) { return dat[size\
    \ + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    set(i, Monoid::op(dat[i+size],x));\n  }\n\n  X prod(int L, int\
    \ R) {\n    assert(L <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(), vr\
    \ = Monoid::unit();\n    L += size, R += size;\n    while (L < R) {\n      if\
    \ (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R],\
    \ vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n\
    \  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int max_right(F&\
    \ check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n  \
    \  if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F& check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit()));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit();\n    do {\n      --R;\n      while (R > 1 && (R %\
    \ 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R\
    \ < size) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\
    \u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n  X Xor_prod(int\
    \ l, int r, int xor_val) {\n    assert(Monoid::commute);\n    X x = Monoid::unit();\n\
    \    for (int k = 0; k < log + 1; ++k) {\n      if (l >= r) break;\n      if (l\
    \ & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }\n      if\
    \ (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }\n     \
    \ l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n  }\n\n  ostream& operator<<(ostream&os)const{\n\
    \    os<<\"(\";\n    for(int L=1;L<=size;L<<=1){\n      os<<\"[\";\n      for(int\
    \ j=L;j<(L<<1);j++){\n        os<<dat[j];\n        if(j+1<(L<<1))os<<\",\";\n\
    \      }\n      os<<\"]\";\n    }\n    os<<\")\";\n    return os;\n  }\n};\n#line\
    \ 1 \"graph/Graph.cpp\"\nstruct Edge{\n  int from,to;\n  Edge()=default;\n  Edge(int\
    \ from,int to):from(from),to(to){}\n};\n\nstruct Graph{\n  int n;\n  using edge_type=Edge;\n\
    private:\n  vector<edge_type> edges;\n  vector<int> in_deg;\n  bool prepared;\n\
    \  class OutgoingEdges{\n    const Graph* g;\n    int l,r;\n  public:\n    OutgoingEdges(const\
    \ Graph* g,int l,int r):g(g),l(l),r(r){}\n    const edge_type* begin()const{ return\
    \ &(g->edges[l]); }\n    const edge_type* end()const{ return &(g->edges[r]); }\n\
    \    const edge_type* operator[](int i)const{ return &(g->edges[l+i]); }\n   \
    \ int size()const{ return r-l; }\n  };\npublic:\n  OutgoingEdges operator[](int\
    \ v)const{\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1] };\n\
    \  }\n\n  bool is_prepared() { return prepared; }\n\n  Graph():n(0),in_deg(1,0),prepared(false){}\n\
    \  Graph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  Graph(int n,int m,bool\
    \ directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){ scan(m,directed,indexed);\
    \ }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int from,int to){\n    assert(!prepared);\n\
    \    assert(0<=from and from<n and 0<=to and to<n);\n    edges.emplace_back(from,to);\n\
    \    in_deg[from+1]++;\n  }\n  void add_edge(int u,int v){\n    add_arc(u,v);\n\
    \    add_arc(v,u);\n  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n\
    \    edges.reserve(directed?m:2*m);\n    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n\
    \      if(directed)add_arc(u,v);\n      else add_edge(u,v);\n    }\n    build();\n\
    \  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n\
    \    vector<edge_type> new_edges(in_deg.back());\n    auto counter=in_deg;\n \
    \   for(auto&&e:edges)new_edges[ counter[e.from]++ ]=e;\n    edges=new_edges;\n\
    \  }\n\n  void graph_debug(){\n  #ifndef __LOCAL\n    return;\n  #endif\n    assert(prepared);\n\
    \    for(int from=0;from<n;from++){\n      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<edges[i].to<<\" \";\n      cerr<<\"\\n\";\n    }\n  }\n};\n#line\
    \ 2 \"tree/tree.cpp\"\nstruct Tree:Graph{\n  using Graph::Graph;\n  int root=-1;\n\
    \  vector<vector<int>> son;\n  vector<int> DFS,BFS,parent,depth;\n\n  void scan_root(int\
    \ indexed=1){\n    for(int i=1;i<n;i++){\n      int p;cin>>p;\n      add_edge(p-indexed,i);\n\
    \    }\n    build();\n  }\n  void scan(int indexed=1){\n    Graph::scan(n-1,false,indexed);\n\
    \    build();\n  }\n\nprivate:\n  void dfs(int idx,int pre=-1){\n    parent[idx]=pre;\n\
    \    for(const auto&e:(*this)[idx])if(e.to!=pre){\n      depth[e.to]=depth[idx]+1;\n\
    \      dfs(e.to,idx);\n      son[idx].push_back(e.to);\n    }\n    DFS.push_back(idx);\n\
    \  }\npublic:\n  void build(int r=0){\n    if(!is_prepared())Graph::build();\n\
    \    if(~root){\n      assert(r==root);\n      return;\n    }\n    root=r;\n \
    \   son.resize(n);parent.resize(n);depth.resize(n);\n    DFS.reserve(n);BFS.reserve(n);\n\
    \    depth[root]=0;\n    dfs(root);\n    queue<int> que;\n    que.push(root);\n\
    \    while(que.size()){\n      int p=que.front();que.pop();\n      BFS.push_back(p);\n\
    \      for(int c:son[p])que.push(c);\n    }\n  }\n};\n#line 1 \"tree/hld.cpp\"\
    \ntemplate<typename TREE>\nstruct HLD{\n  int n;\n  TREE T;\n  vector<int> sz,head,id,id2;\n\
    \  bool prepared;\n  HLD(TREE T_):T(T_),n(T_.n),sz(n),head(n),id(n),id2(n),prepared(false){}\n\
    private:\n  void dfs_sz(int v){\n    sz[v]=1;\n    for(int c:T.son[v]){\n    \
    \  sz[v]+=sz[c];\n      if(sz[c]>sz[T.son[v][0]])swap(c,T.son[v][0]);\n    }\n\
    \  }\n  void dfs_hld(int v,int& k){\n    id[v]=k++;\n    for(int c:T.son[v]){\n\
    \      head[c]=(c==T.son[v][0]?head[v]:c);\n      dfs_hld(c,k);\n    }\n    id2[v]=k;\n\
    \  }\npublic:\n  vector<int> build(int r=0){\n    assert(!prepared);prepared=true;\n\
    \    if(~T.root)assert(T.root==r);\n    else T.build(r);\n    head[r]=r;\n   \
    \ dfs_sz(r);\n    int k=0;\n    dfs_hld(r,k);\n    return id;\n  }\n\n  int lca(int\
    \ u,int v){\n    assert(prepared);\n    while(head[u]!=head[v]){\n      if(T.depth[head[u]]>T.depth[head[v]])u=T.parent[head[u]];\n\
    \      else v=T.parent[head[v]];\n    }\n    return (T.depth[u]<T.depth[v]?u:v);\n\
    \  }\n\n  // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068\
    \ [v,l] \u30D1\u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\
    \n  using path_t=vector<pair<int,int>>;\n  pair<path_t,path_t> path(int u,int\
    \ v){\n    assert(prepared);\n    path_t path_u,path_v;\n    while(u!=v){\n  \
    \    if(head[u]==head[v]){\n        if(T.depth[u]<T.depth[v])\n          path_v.emplace_back(id[v],id[u]);\n\
    \        else\n          path_u.emplace_back(id[u],id[v]);\n        break;\n \
    \     }\n      if(T.depth[head[u]]<T.depth[head[v]]){\n        path_v.emplace_back(id[v],id[head[v]]);\n\
    \        v=T.parent[head[v]];\n      }\n      else{\n        path_u.emplace_back(id[u],id[head[u]]);\n\
    \        u=T.parent[head[u]];\n      }\n    }\n    if(u==v)path_u.emplace_back(id[u],id[u]);\n\
    \    return {path_u,path_v};\n  }\n\n  // [l,r) \u304C v \u306E\u90E8\u5206\u6728\
    \n  pair<int,int> subtree(int v){\n    assert(prepared);\n    return {id[v],id2[v]};\
    \ \n  }\n};\n#line 1 \"segtree/segtree.cpp\"\ntemplate<class Monoid>\nstruct SegmentTree{\n\
    \  using X = typename Monoid::value_type;\n  using value_type = X;\n  vector<X>\
    \ dat;\n  int n, log, size;\n\n  SegmentTree() : SegmentTree(0) {}\n  SegmentTree(int\
    \ n) : SegmentTree(vector<X>(n, Monoid::unit())) {}\n  SegmentTree(vector<X> v)\
    \ : n(v.size()) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size =\
    \ 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n    for (int i = 0; i\
    \ < n; ++i) dat[size + i] = v[i];\n    for (int i = size - 1; i >= 1; --i) update(i);\n\
    \  }\n\n  X operator[](int i) { return dat[size + i]; }\n\n  void update(int i)\
    \ { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n  void set(int i, const\
    \ X& x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    set(i, Monoid::op(dat[i+size],x));\n\
    \  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n    assert(R <= n);\n \
    \   X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n \
    \   while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if\
    \ (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n   \
    \ return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  template\
    \ <class F>\n  int max_right(F& check, int L) {\n    assert(0 <= L && L <= n &&\
    \ check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n    X sm\
    \ = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm,\
    \ dat[L]))) {\n        while (L < size) {\n          L = 2 * L;\n          if\
    \ (check(Monoid::op(sm, dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n\
    \            L++;\n          }\n        }\n        return L - size;\n      }\n\
    \      sm = Monoid::op(sm, dat[L]);\n      L++;\n    } while ((L & -L) != L);\n\
    \    return n;\n  }\n\n  template <class F>\n  int min_left(F& check, int R) {\n\
    \    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R == 0) return\
    \ 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n      --R;\n     \
    \ while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R], sm)))\
    \ {\n        while (R < size) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\
    \u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n  X Xor_prod(int\
    \ l, int r, int xor_val) {\n    assert(Monoid::commute);\n    X x = Monoid::unit();\n\
    \    for (int k = 0; k < log + 1; ++k) {\n      if (l >= r) break;\n      if (l\
    \ & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }\n      if\
    \ (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }\n     \
    \ l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n  }\n\n  ostream& operator<<(ostream&os)const{\n\
    \    os<<\"(\";\n    for(int L=1;L<=size;L<<=1){\n      os<<\"[\";\n      for(int\
    \ j=L;j<(L<<1);j++){\n        os<<dat[j];\n        if(j+1<(L<<1))os<<\",\";\n\
    \      }\n      os<<\"]\";\n    }\n    os<<\")\";\n    return os;\n  }\n};\n#line\
    \ 1 \"algebra/algebra_reverse.cpp\"\ntemplate<typename Algebra>\nstruct Algebra_Reverse:Algebra{\n\
    \  using X=typename Algebra::value_type;\n  static constexpr X op(const X& x,\
    \ const X& y){ return Algebra::op(y,x); }\n};\n#line 1 \"tree/hld.cpp\"\ntemplate<typename\
    \ TREE>\nstruct HLD{\n  int n;\n  TREE T;\n  vector<int> sz,head,id,id2;\n  bool\
    \ prepared;\n  HLD(TREE T_):T(T_),n(T_.n),sz(n),head(n),id(n),id2(n),prepared(false){}\n\
    private:\n  void dfs_sz(int v){\n    sz[v]=1;\n    for(int c:T.son[v]){\n    \
    \  sz[v]+=sz[c];\n      if(sz[c]>sz[T.son[v][0]])swap(c,T.son[v][0]);\n    }\n\
    \  }\n  void dfs_hld(int v,int& k){\n    id[v]=k++;\n    for(int c:T.son[v]){\n\
    \      head[c]=(c==T.son[v][0]?head[v]:c);\n      dfs_hld(c,k);\n    }\n    id2[v]=k;\n\
    \  }\npublic:\n  vector<int> build(int r=0){\n    assert(!prepared);prepared=true;\n\
    \    if(~T.root)assert(T.root==r);\n    else T.build(r);\n    head[r]=r;\n   \
    \ dfs_sz(r);\n    int k=0;\n    dfs_hld(r,k);\n    return id;\n  }\n\n  int lca(int\
    \ u,int v){\n    assert(prepared);\n    while(head[u]!=head[v]){\n      if(T.depth[head[u]]>T.depth[head[v]])u=T.parent[head[u]];\n\
    \      else v=T.parent[head[v]];\n    }\n    return (T.depth[u]<T.depth[v]?u:v);\n\
    \  }\n\n  // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068\
    \ [v,l] \u30D1\u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\
    \n  using path_t=vector<pair<int,int>>;\n  pair<path_t,path_t> path(int u,int\
    \ v){\n    assert(prepared);\n    path_t path_u,path_v;\n    while(u!=v){\n  \
    \    if(head[u]==head[v]){\n        if(T.depth[u]<T.depth[v])\n          path_v.emplace_back(id[v],id[u]);\n\
    \        else\n          path_u.emplace_back(id[u],id[v]);\n        break;\n \
    \     }\n      if(T.depth[head[u]]<T.depth[head[v]]){\n        path_v.emplace_back(id[v],id[head[v]]);\n\
    \        v=T.parent[head[v]];\n      }\n      else{\n        path_u.emplace_back(id[u],id[head[u]]);\n\
    \        u=T.parent[head[u]];\n      }\n    }\n    if(u==v)path_u.emplace_back(id[u],id[u]);\n\
    \    return {path_u,path_v};\n  }\n\n  // [l,r) \u304C v \u306E\u90E8\u5206\u6728\
    \n  pair<int,int> subtree(int v){\n    assert(prepared);\n    return {id[v],id2[v]};\
    \ \n  }\n};\n#line 4 \"tree/TreeMonoid.cpp\"\ntemplate<typename TREE,typename\
    \ Monoid>\nstruct TreeMonoid{\n  using X=typename Monoid::value_type;\n  using\
    \ Monoid_r=Algebra_Reverse<Monoid>;\n  int n;\n  TREE T;\n  HLD<Tree> hld;\n \
    \ vector<int> hld_id,euler_in,euler_out;\n  SegmentTree<Monoid> seg;\n  SegmentTree<Monoid_r>\
    \ seg_r; \n  \n  TreeMonoid(TREE T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){\n\
    \    T.build(r);\n    hld_id=hld.build(r);\n  }\n  TreeMonoid(TREE T,vector<X>\
    \ a,int r=0):T(T),hld(T),n(T.n){\n    T.build(r);\n    hld_id=hld.build(r);\n\
    \    vector<X> hld_a(n);\n    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];\n   \
    \ seg=SegmentTree<Monoid>(hld_a);\n    seg_r=SegmentTree<Monoid_r>(hld_a);\n \
    \ }\n\n  void set(int v,X x){\n    seg.set(hld_id[v],x);\n    seg_r.set(hld_id[v],x);\n\
    \  }\n  void multiply(int v,X x){\n    seg.multiply(hld_id[v],x);\n    seg_r.multiply(hld_id[v],x);\n\
    \  }\n  X get(int v){ return seg.get(hld_id[v]); }\n  \n  // [u,v]\u30D1\u30B9\
    \u306E monoid \u7A4D\n  X path_prod(int u,int v){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    X prod_u=Monoid::unit(),prod_v=Monoid::unit();\n    for(const auto&[l,r]:path_u){\n\
    \      X val=seg_r.prod(r,l+1);\n      prod_u=Monoid::op(prod_u,val);\n    }\n\
    \    for(const auto&[l,r]:path_v){\n      X val=seg.prod(r,l+1);\n      prod_v=Monoid::op(val,prod_v);\n\
    \    }\n    return Monoid::op(prod_u,prod_v);\n  }\n  // root -> path\n  X path_root(int\
    \ v){ return path(T.root,v); }\n\n  X subtree_prod(int v){\n    assert(Monoid::commute);\n\
    \    auto [l,r]=hld.subtree(v);\n    return seg.prod(l,r);\n  }\n};\n#line 11\
    \ \"test/library-checker/Tree/vertex_add_subtree_sum.test.cpp\"\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  using G=Group_Add<long\
    \ long>;\n\n  int n,q;cin>>n>>q; \n  vector<long long> a(n);\n  for(int i=0;i<n;i++)cin>>a[i];\n\
    \n  Tree t(n);\n  t.scan_root(0);\n\n  TreeMonoid<Tree,G> TM(t,a);\n\n  while(q--){\n\
    \    int c;cin>>c;\n    if(c){\n      int u;cin>>u;\n      cout<< TM.subtree_prod(u)\
    \ <<\"\\n\";\n    }\n    else{\n      int u,x;cin>>u>>x;\n      TM.multiply(u,x);\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"algebra/group_add.cpp\"\
    \n#include \"algebra/algebra_reverse.cpp\"\n#include \"segtree/segtree.cpp\"\n\
    #include \"tree/tree.cpp\"\n#include \"tree/hld.cpp\"\n#include \"tree/TreeMonoid.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  using\
    \ G=Group_Add<long long>;\n\n  int n,q;cin>>n>>q; \n  vector<long long> a(n);\n\
    \  for(int i=0;i<n;i++)cin>>a[i];\n\n  Tree t(n);\n  t.scan_root(0);\n\n  TreeMonoid<Tree,G>\
    \ TM(t,a);\n\n  while(q--){\n    int c;cin>>c;\n    if(c){\n      int u;cin>>u;\n\
    \      cout<< TM.subtree_prod(u) <<\"\\n\";\n    }\n    else{\n      int u,x;cin>>u>>x;\n\
    \      TM.multiply(u,x);\n    }\n  }\n}"
  dependsOn:
  - algebra/group_add.cpp
  - algebra/algebra_reverse.cpp
  - segtree/segtree.cpp
  - tree/tree.cpp
  - graph/Graph.cpp
  - tree/hld.cpp
  - tree/TreeMonoid.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2022-11-19 10:38:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
- /verify/test/library-checker/Tree/vertex_add_subtree_sum.test.cpp.html
title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
---

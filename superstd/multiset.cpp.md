---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/double_ended_priority_queue.test.cpp
    title: test/library-checker/DataStructure/double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"superstd/multiset.cpp\"\ntemplate<typename T>\nstruct Multiset:map<T,int>{\n\
    \  using map<T,int>::size;\n  using map<T,int>::begin;\n  using map<T,int>::rbegin;\n\
    \  using map<T,int>::erase;\n  using map<T,int>::lower_bound;\n  using map<T,int>::upper_bound;\n\
    \n  void insert(const T&a){ (*this)[a]++; }\n  void erase1(const T&a){ if((*this)[a]\
    \ and !--(*this)[a])erase(a); }\n \n  T mn()const{ assert(size()); return begin()->first;\
    \ }\n  T mx()const{ assert(size()); return rbegin()->first; }\n  T pick_mn(){\
    \ // \u30D4\u30AF\u30DF\u30F3\n    T res=mn();\n    erase1(res);\n    return res;\n\
    \  }\n  T pick_mx(){\n    T res=mx();\n    erase1(res);\n    return res;\n  }\n\
    \n  T lt(const T&a)const{\n    assert(mn()<a);\n    if(mx()<a)return mx();\n \
    \   return (--lower_bound(a))->first;\n  }\n  T leq(const T&a)const{\n    assert(mn()<=a);\n\
    \    if(mx()<=a)return mx();\n    return (--upper_bound(a))->first;\n  }\n  T\
    \ gt(const T&a)const{\n    assert(mx()>a);\n    return upper_bound(a)->first;\n\
    \  }\n  T geq(const T&a){\n    assert(mx()>=a);\n    return lower_bound(a)->first;\n\
    \  }\n\n  Multiset()=default;\n  Multiset(const vector<T>&v){ for(const auto&p:v)insert(p);\
    \ }\n  \n  void scan(int n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n\
    \    }\n  }\n  \n  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n \
    \   insert(numeric_limits<T>::min()/2);\n  }\n};\n"
  code: "template<typename T>\nstruct Multiset:map<T,int>{\n  using map<T,int>::size;\n\
    \  using map<T,int>::begin;\n  using map<T,int>::rbegin;\n  using map<T,int>::erase;\n\
    \  using map<T,int>::lower_bound;\n  using map<T,int>::upper_bound;\n\n  void\
    \ insert(const T&a){ (*this)[a]++; }\n  void erase1(const T&a){ if((*this)[a]\
    \ and !--(*this)[a])erase(a); }\n \n  T mn()const{ assert(size()); return begin()->first;\
    \ }\n  T mx()const{ assert(size()); return rbegin()->first; }\n  T pick_mn(){\
    \ // \u30D4\u30AF\u30DF\u30F3\n    T res=mn();\n    erase1(res);\n    return res;\n\
    \  }\n  T pick_mx(){\n    T res=mx();\n    erase1(res);\n    return res;\n  }\n\
    \n  T lt(const T&a)const{\n    assert(mn()<a);\n    if(mx()<a)return mx();\n \
    \   return (--lower_bound(a))->first;\n  }\n  T leq(const T&a)const{\n    assert(mn()<=a);\n\
    \    if(mx()<=a)return mx();\n    return (--upper_bound(a))->first;\n  }\n  T\
    \ gt(const T&a)const{\n    assert(mx()>a);\n    return upper_bound(a)->first;\n\
    \  }\n  T geq(const T&a){\n    assert(mx()>=a);\n    return lower_bound(a)->first;\n\
    \  }\n\n  Multiset()=default;\n  Multiset(const vector<T>&v){ for(const auto&p:v)insert(p);\
    \ }\n  \n  void scan(int n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n\
    \    }\n  }\n  \n  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n \
    \   insert(numeric_limits<T>::min()/2);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: superstd/multiset.cpp
  requiredBy: []
  timestamp: '2022-10-27 21:47:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/double_ended_priority_queue.test.cpp
documentation_of: superstd/multiset.cpp
layout: document
redirect_from:
- /library/superstd/multiset.cpp
- /library/superstd/multiset.cpp.html
title: superstd/multiset.cpp
---

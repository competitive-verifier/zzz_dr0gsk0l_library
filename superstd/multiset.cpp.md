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
  bundledCode: "#line 1 \"superstd/multiset.cpp\"\ntemplate<typename T>\nstruct Multiset:multiset<T>{\n\
    \  using multiset<T>::size;\n  using multiset<T>::begin;\n  using multiset<T>::end;\n\
    \  using multiset<T>::rbegin;\n  using multiset<T>::insert;\n  using multiset<T>::erase;\n\
    \  using multiset<T>::find;\n  using multiset<T>::lower_bound;\n  using multiset<T>::upper_bound;\n\
    \  \n  T mn()const{ assert(size());return *begin(); }\n  T mx()const{ assert(size());return\
    \ *rbegin(); }\n  \n  T pop_front(){\n    assert(size());\n    T mn=*begin();\n\
    \    erase1(mn);\n    return mn;\n  }\n  T pop_back(){\n    assert(size());\n\
    \    T mx=*rbegin();\n    erase1(mx);\n    return mx;\n  }\n\n  T lt(const T&a)const{\n\
    \    assert(mn()<a);\n    if(mx()<a)return mx();\n    return *--lower_bound(a);\n\
    \  }\n  T leq(const T&a)const{\n    assert(mn()<=a);\n    if(mx()<=a)return mx();\n\
    \    return *--upper_bound(a);\n  }\n  T gt(const T&a)const{\n    assert(mx()>a);\n\
    \    return *upper_bound(a);\n  }\n  T geq(const T&a){\n    assert(mx()>=a);\n\
    \    return *lower_bound(a);\n  }\n\n  void erase1(const T&a){ if(find(a)!=end())erase(find(a));\
    \ }\n  \n  Multiset()=default;\n  Multiset(const vector<T>&v){ for(const auto&p:v)insert(p);\
    \ }\n  \n  void scan(int n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n\
    \    }\n  }\n  \n  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n \
    \   insert(numeric_limits<T>::min()/2);\n  }\n};\n"
  code: "template<typename T>\nstruct Multiset:multiset<T>{\n  using multiset<T>::size;\n\
    \  using multiset<T>::begin;\n  using multiset<T>::end;\n  using multiset<T>::rbegin;\n\
    \  using multiset<T>::insert;\n  using multiset<T>::erase;\n  using multiset<T>::find;\n\
    \  using multiset<T>::lower_bound;\n  using multiset<T>::upper_bound;\n  \n  T\
    \ mn()const{ assert(size());return *begin(); }\n  T mx()const{ assert(size());return\
    \ *rbegin(); }\n  \n  T pop_front(){\n    assert(size());\n    T mn=*begin();\n\
    \    erase1(mn);\n    return mn;\n  }\n  T pop_back(){\n    assert(size());\n\
    \    T mx=*rbegin();\n    erase1(mx);\n    return mx;\n  }\n\n  T lt(const T&a)const{\n\
    \    assert(mn()<a);\n    if(mx()<a)return mx();\n    return *--lower_bound(a);\n\
    \  }\n  T leq(const T&a)const{\n    assert(mn()<=a);\n    if(mx()<=a)return mx();\n\
    \    return *--upper_bound(a);\n  }\n  T gt(const T&a)const{\n    assert(mx()>a);\n\
    \    return *upper_bound(a);\n  }\n  T geq(const T&a){\n    assert(mx()>=a);\n\
    \    return *lower_bound(a);\n  }\n\n  void erase1(const T&a){ if(find(a)!=end())erase(find(a));\
    \ }\n  \n  Multiset()=default;\n  Multiset(const vector<T>&v){ for(const auto&p:v)insert(p);\
    \ }\n  \n  void scan(int n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n\
    \    }\n  }\n  \n  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n \
    \   insert(numeric_limits<T>::min()/2);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: superstd/multiset.cpp
  requiredBy: []
  timestamp: '2022-09-13 16:00:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: superstd/multiset.cpp
layout: document
redirect_from:
- /library/superstd/multiset.cpp
- /library/superstd/multiset.cpp.html
title: superstd/multiset.cpp
---

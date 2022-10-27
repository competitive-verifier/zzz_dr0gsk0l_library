---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Exp.test.cpp
    title: test/library-checker/Polynomial/Exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Inv.test.cpp
    title: test/library-checker/Polynomial/Inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Log.test.cpp
    title: test/library-checker/Polynomial/Log.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"formalpowerseries/base.cpp\"\n#define REP_(i,n) for(int\
    \ i=0;i<(n);i++)\ntemplate<typename T,int MX>\nstruct FormalPowerSeries:vector<T>{\n\
    \  using FPS=FormalPowerSeries<T,MX>;\n  using vector<T>::resize;\n  using vector<T>::size;\n\
    \  using vector<T>::at;\n\n  FormalPowerSeries()=default;\n  FormalPowerSeries(int\
    \ n,T a={}){\n    resize(min(MX,n),a);\n  }\n  FormalPowerSeries(const vector<T>&f){\n\
    \    int n=min(MX,int(f.size()));\n    resize(n);\n    REP_(i,n)at(i)=f[i];\n\
    \  }\n  FormalPowerSeries(const vector<pair<T,int>>&sparse){\n    int n=0;\n \
    \   for(const auto&[co,deg]:sparse)n=max(n,deg+1);\n    n=min(MX,n);\n    assign(n,T(0));\n\
    \    for(const auto&[co,deg]:sparse)if(deg<n)at(deg)=co;\n  }\n\n  FPS operator-()const{\n\
    \    FPS g=*this;\n    for(T&a:g)a=-a;\n    return g;\n  }\n  \n  FPS &operator+=(const\
    \ FPS &g){\n    if(size()<g.size())resize(g.size());\n    REP_(i,g.size())at(i)+=g[i];\n\
    \    return *this;\n  }\n  FPS operator+(const FPS &g)const{return FPS(*this)+=g;}\n\
    \n  FPS &operator+=(const T &a){\n    if(!size())resize(1);\n    at(0)+=a;\n \
    \   return *this;\n  }\n  FPS operator+(const T& a)const{return FPS(*this)+=a;}\n\
    \  friend FPS operator+(const T&a,const FPS&f){return f+a;}\n\n  FPS &operator-=(const\
    \ FPS &g){\n    if(size()<g.size())resize(g.size());\n    REP_(i,g.size())at(i)-=g[i];\n\
    \    return *this;\n  }\n  FPS operator-(const FPS &g)const{return FPS(*this)-=g;}\n\
    \n  FPS &operator-=(const T &a){\n    if(!size())resize(1);\n    at(0)-=a;\n \
    \   return *this;\n  }\n  FPS operator-(const T& a){return FPS(*this)-=a;}\n \
    \ friend FPS operator-(const T&a,const FPS&f){return a+(-f);}\n  \n  FPS operator*(const\
    \ FPS&g)const{\n    return FPS(convolution(*this,g));\n  }\n\n  FPS &operator*=(const\
    \ FPS&g){\n    return (*this)=(*this)*g;\n  }\n\n  FPS &operator*=(const T &a){\n\
    \    REP_(i,size())at(i)*=a;\n    return *this;\n  }\n\n  FPS operator*(const\
    \ T &a)const{\n    FPS res(*this);\n    for(T&p:res)p*=a;\n    return res;\n \
    \ }\n  friend FPS operator*(const T&a,const FPS&f){return f*a;}\n\n  FPS operator/(const\
    \ FPS g)const{\n    return convolution(*this,g.inv());\n  }\n\n  FPS &operator/=(const\
    \ FPS&g){\n    return (*this)=(*this)/g;\n  }\n\n  FPS &operator/=(const T &a){\n\
    \    REP_(i,size())at(i)/=a;\n    return *this;\n  }\n\n  FPS inv()const{\n  \
    \  assert(size() and at(0)!=0);\n    FPS res(1,at(0).inv());\n    for(int i=0;(1<<i)<size();i++)res*=(2-res*(*this));\n\
    \    return res;\n  }\n\n  void strict(int n){\n    if(size()>n)resize(n);\n \
    \ }\n\n  FPS pow(int n)const{\n    assert(n>=0);\n    if(n==0)return FPS(1,1);\n\
    \    if(n==1)return *this;\n    if(at(0)==1)return exp(n*log(*this));\n    FPS\
    \ res(vector<T>{1}),now=*this;\n    while(n){\n      if(n&1)res*=now;\n      now*=now;\n\
    \      res>>=1;\n    }\n    return res;\n  }\n\n  FPS operator()(FPS f)const{\n\
    \    if(size()==1)return FPS(1,at(0));\n    if(size()==2)return FPS(at(0)+at(1)*f);\n\
    \    int n=size()/2;\n    FPS s=*this;\n    s.strict(n);\n    FPS t(size()-n);\n\
    \    for(int i=n;i<size();i++)t[i-n]=at(i);\n    return s(f)+f.pow(n)*t(f);\n\
    \  }\n\n  static FPS differential(const FPS f){\n    if(f.size()<=1)return FPS(0);\n\
    \    FPS res(f.size()-1);\n    REP_(i,f.size()-1)res[i]=(i+1)*f[i+1];\n    return\
    \ res;\n  }\n\n  static FPS integral(const FPS f){\n    FPS res(f.size()+1,0);\n\
    \    REP_(i,f.size())res[i+1]=f[i]/(i+1);\n    return res;\n  }\n\n  static FPS\
    \ log(const FPS f){\n    assert(f[0]==1);\n    return integral(differential(f)/f);\n\
    \  }\n\n  static FPS exp(const FPS f){\n    assert(f[0]==0);\n    FPS res(1,1);\n\
    \    for(int i=0;(1<<i)<MX;i++)res*=f+T(1)-log(res);\n    return res;\n  }\n};\n\
    #undef REP_\n"
  code: "#define REP_(i,n) for(int i=0;i<(n);i++)\ntemplate<typename T,int MX>\nstruct\
    \ FormalPowerSeries:vector<T>{\n  using FPS=FormalPowerSeries<T,MX>;\n  using\
    \ vector<T>::resize;\n  using vector<T>::size;\n  using vector<T>::at;\n\n  FormalPowerSeries()=default;\n\
    \  FormalPowerSeries(int n,T a={}){\n    resize(min(MX,n),a);\n  }\n  FormalPowerSeries(const\
    \ vector<T>&f){\n    int n=min(MX,int(f.size()));\n    resize(n);\n    REP_(i,n)at(i)=f[i];\n\
    \  }\n  FormalPowerSeries(const vector<pair<T,int>>&sparse){\n    int n=0;\n \
    \   for(const auto&[co,deg]:sparse)n=max(n,deg+1);\n    n=min(MX,n);\n    assign(n,T(0));\n\
    \    for(const auto&[co,deg]:sparse)if(deg<n)at(deg)=co;\n  }\n\n  FPS operator-()const{\n\
    \    FPS g=*this;\n    for(T&a:g)a=-a;\n    return g;\n  }\n  \n  FPS &operator+=(const\
    \ FPS &g){\n    if(size()<g.size())resize(g.size());\n    REP_(i,g.size())at(i)+=g[i];\n\
    \    return *this;\n  }\n  FPS operator+(const FPS &g)const{return FPS(*this)+=g;}\n\
    \n  FPS &operator+=(const T &a){\n    if(!size())resize(1);\n    at(0)+=a;\n \
    \   return *this;\n  }\n  FPS operator+(const T& a)const{return FPS(*this)+=a;}\n\
    \  friend FPS operator+(const T&a,const FPS&f){return f+a;}\n\n  FPS &operator-=(const\
    \ FPS &g){\n    if(size()<g.size())resize(g.size());\n    REP_(i,g.size())at(i)-=g[i];\n\
    \    return *this;\n  }\n  FPS operator-(const FPS &g)const{return FPS(*this)-=g;}\n\
    \n  FPS &operator-=(const T &a){\n    if(!size())resize(1);\n    at(0)-=a;\n \
    \   return *this;\n  }\n  FPS operator-(const T& a){return FPS(*this)-=a;}\n \
    \ friend FPS operator-(const T&a,const FPS&f){return a+(-f);}\n  \n  FPS operator*(const\
    \ FPS&g)const{\n    return FPS(convolution(*this,g));\n  }\n\n  FPS &operator*=(const\
    \ FPS&g){\n    return (*this)=(*this)*g;\n  }\n\n  FPS &operator*=(const T &a){\n\
    \    REP_(i,size())at(i)*=a;\n    return *this;\n  }\n\n  FPS operator*(const\
    \ T &a)const{\n    FPS res(*this);\n    for(T&p:res)p*=a;\n    return res;\n \
    \ }\n  friend FPS operator*(const T&a,const FPS&f){return f*a;}\n\n  FPS operator/(const\
    \ FPS g)const{\n    return convolution(*this,g.inv());\n  }\n\n  FPS &operator/=(const\
    \ FPS&g){\n    return (*this)=(*this)/g;\n  }\n\n  FPS &operator/=(const T &a){\n\
    \    REP_(i,size())at(i)/=a;\n    return *this;\n  }\n\n  FPS inv()const{\n  \
    \  assert(size() and at(0)!=0);\n    FPS res(1,at(0).inv());\n    for(int i=0;(1<<i)<size();i++)res*=(2-res*(*this));\n\
    \    return res;\n  }\n\n  void strict(int n){\n    if(size()>n)resize(n);\n \
    \ }\n\n  FPS pow(int n)const{\n    assert(n>=0);\n    if(n==0)return FPS(1,1);\n\
    \    if(n==1)return *this;\n    if(at(0)==1)return exp(n*log(*this));\n    FPS\
    \ res(vector<T>{1}),now=*this;\n    while(n){\n      if(n&1)res*=now;\n      now*=now;\n\
    \      res>>=1;\n    }\n    return res;\n  }\n\n  FPS operator()(FPS f)const{\n\
    \    if(size()==1)return FPS(1,at(0));\n    if(size()==2)return FPS(at(0)+at(1)*f);\n\
    \    int n=size()/2;\n    FPS s=*this;\n    s.strict(n);\n    FPS t(size()-n);\n\
    \    for(int i=n;i<size();i++)t[i-n]=at(i);\n    return s(f)+f.pow(n)*t(f);\n\
    \  }\n\n  static FPS differential(const FPS f){\n    if(f.size()<=1)return FPS(0);\n\
    \    FPS res(f.size()-1);\n    REP_(i,f.size()-1)res[i]=(i+1)*f[i+1];\n    return\
    \ res;\n  }\n\n  static FPS integral(const FPS f){\n    FPS res(f.size()+1,0);\n\
    \    REP_(i,f.size())res[i+1]=f[i]/(i+1);\n    return res;\n  }\n\n  static FPS\
    \ log(const FPS f){\n    assert(f[0]==1);\n    return integral(differential(f)/f);\n\
    \  }\n\n  static FPS exp(const FPS f){\n    assert(f[0]==0);\n    FPS res(1,1);\n\
    \    for(int i=0;(1<<i)<MX;i++)res*=f+T(1)-log(res);\n    return res;\n  }\n};\n\
    #undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: formalpowerseries/base.cpp
  requiredBy: []
  timestamp: '2022-09-08 17:20:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Polynomial/Log.test.cpp
  - test/library-checker/Polynomial/Inv.test.cpp
  - test/library-checker/Polynomial/Exp.test.cpp
documentation_of: formalpowerseries/base.cpp
layout: document
redirect_from:
- /library/formalpowerseries/base.cpp
- /library/formalpowerseries/base.cpp.html
title: formalpowerseries/base.cpp
---

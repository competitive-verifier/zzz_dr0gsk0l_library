---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/MatrixProduct.test.cpp
    title: test/library-checker/Matrix/MatrixProduct.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linearalgebra/matrix.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
    #define REP2_(i,s,n) for(int i=(s);i<(n);i++)\ntemplate<typename K>\nstruct Matrix{\n\
    \  using vec=vector<K>;\n  using mat=vector<vec>;\n  size_t r,c;\n  mat M;\n\n\
    \  Matrix(size_t r,size_t c):r(r),c(c),M(r,vec(c,K())){}\n  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}\n\
    \n  vec& operator[](size_t k){return M[k];}\n  const vec& operator[](size_t k)const{return\
    \ M[k];}\n\n  Matrix& operator+=(const Matrix &A){\n    assert(r==A.r&&c==A.c);\n\
    \    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];\n    return *this;\n  }\n  Matrix& operator-=(const\
    \ Matrix &A){\n    assert(r==A.r&&c==A.c);\n    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];\n\
    \    return *this;\n  }\n  Matrix operator+(const Matrix &A){ return Matrix(M)+=A;\
    \ }\n  Matrix operator-(const Matrix &A){ return Matrix(M)-=A; }\n\n  friend Matrix\
    \ operator*(const Matrix &A,const Matrix &B){\n    assert(A.c==B.r);\n    Matrix\
    \ res(A.r,B.c);\n    REP_(i,A.r)REP_(k,A.c)REP_(j,B.c)res[i][j]+=A[i][k]*B[k][j];\n\
    \    return res;\n  }\n  Matrix& operator*=(const Matrix &A){\n    M=((*this)*A).M;\n\
    \    return *this;\n  }\n\n  bool operator==(const Matrix &A){\n    if(r!=A.r||c!=A.c)return\
    \ false;\n    REP_(i,r)REP_(j,c)if(M[i][j]!=A[i][j])return false;\n    return\
    \ true;\n  }\n  bool operator!=(const Matrix &A){ return !((*this)==A); }\n\n\
    \  static Matrix I(size_t n){\n    Matrix res(n,n);\n    REP_(i,n)res[i][i]=K(1);\n\
    \    return res;\n  }\n\n  Matrix pow(long long n)const{\n    assert(n>=0&&r==c);\n\
    \    Matrix A(M),res=I(r);\n    while(n){\n      if(n&1)res*=A;\n      A*=A;\n\
    \      n>>=1;\n    }\n    return res;\n  }\n\n  int rank() const{\n    Matrix\
    \ A(M);\n    int res=0;\n    REP_(k,c){\n      for(int i=res+1;i<r&&A[res][k]==0;i++)\n\
    \        if(A[i][k]!=0)swap(A[i],A[res]);\n      if(A[res][k]==0)continue;\n \
    \     REP2_(l,k+1,c)A[res][l]/=A[res][k];\n      REP2_(j,res+1,r)REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[res][l];\n\
    \      res++;\n    }\n    return res;\n  }\n\n  K det() const{\n    assert(r==c);\n\
    \    Matrix A=M;\n    K res(1);\n    REP_(i,r){\n      for(int j=i+1;j<c&&A[i][i]==0;j++)\n\
    \        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;\n      if(A[i][i]==0)return 0;\n\
    \      res*=A[i][i];\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n\
    \    }\n    return res;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ Matrix &M){ os<<M.M; return os; }\n  friend istream& operator>>(istream&is,Matrix\
    \ &M){ REP_(i,M.r)REP_(j,M.c)is>>M.M[i][j]; return is; }\n};\n#undef REP_\n#undef\
    \ REP2_\n"
  code: "#define REP_(i,n) for(int i=0;i<(n);i++)\n#define REP2_(i,s,n) for(int i=(s);i<(n);i++)\n\
    template<typename K>\nstruct Matrix{\n  using vec=vector<K>;\n  using mat=vector<vec>;\n\
    \  size_t r,c;\n  mat M;\n\n  Matrix(size_t r,size_t c):r(r),c(c),M(r,vec(c,K())){}\n\
    \  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}\n\n  vec& operator[](size_t\
    \ k){return M[k];}\n  const vec& operator[](size_t k)const{return M[k];}\n\n \
    \ Matrix& operator+=(const Matrix &A){\n    assert(r==A.r&&c==A.c);\n    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];\n\
    \    return *this;\n  }\n  Matrix& operator-=(const Matrix &A){\n    assert(r==A.r&&c==A.c);\n\
    \    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];\n    return *this;\n  }\n  Matrix operator+(const\
    \ Matrix &A){ return Matrix(M)+=A; }\n  Matrix operator-(const Matrix &A){ return\
    \ Matrix(M)-=A; }\n\n  friend Matrix operator*(const Matrix &A,const Matrix &B){\n\
    \    assert(A.c==B.r);\n    Matrix res(A.r,B.c);\n    REP_(i,A.r)REP_(k,A.c)REP_(j,B.c)res[i][j]+=A[i][k]*B[k][j];\n\
    \    return res;\n  }\n  Matrix& operator*=(const Matrix &A){\n    M=((*this)*A).M;\n\
    \    return *this;\n  }\n\n  bool operator==(const Matrix &A){\n    if(r!=A.r||c!=A.c)return\
    \ false;\n    REP_(i,r)REP_(j,c)if(M[i][j]!=A[i][j])return false;\n    return\
    \ true;\n  }\n  bool operator!=(const Matrix &A){ return !((*this)==A); }\n\n\
    \  static Matrix I(size_t n){\n    Matrix res(n,n);\n    REP_(i,n)res[i][i]=K(1);\n\
    \    return res;\n  }\n\n  Matrix pow(long long n)const{\n    assert(n>=0&&r==c);\n\
    \    Matrix A(M),res=I(r);\n    while(n){\n      if(n&1)res*=A;\n      A*=A;\n\
    \      n>>=1;\n    }\n    return res;\n  }\n\n  int rank() const{\n    Matrix\
    \ A(M);\n    int res=0;\n    REP_(k,c){\n      for(int i=res+1;i<r&&A[res][k]==0;i++)\n\
    \        if(A[i][k]!=0)swap(A[i],A[res]);\n      if(A[res][k]==0)continue;\n \
    \     REP2_(l,k+1,c)A[res][l]/=A[res][k];\n      REP2_(j,res+1,r)REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[res][l];\n\
    \      res++;\n    }\n    return res;\n  }\n\n  K det() const{\n    assert(r==c);\n\
    \    Matrix A=M;\n    K res(1);\n    REP_(i,r){\n      for(int j=i+1;j<c&&A[i][i]==0;j++)\n\
    \        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;\n      if(A[i][i]==0)return 0;\n\
    \      res*=A[i][i];\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n\
    \    }\n    return res;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ Matrix &M){ os<<M.M; return os; }\n  friend istream& operator>>(istream&is,Matrix\
    \ &M){ REP_(i,M.r)REP_(j,M.c)is>>M.M[i][j]; return is; }\n};\n#undef REP_\n#undef\
    \ REP2_"
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/matrix.cpp
  requiredBy: []
  timestamp: '2022-10-02 16:45:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Matrix/MatrixProduct.test.cpp
documentation_of: linearalgebra/matrix.cpp
layout: document
redirect_from:
- /library/linearalgebra/matrix.cpp
- /library/linearalgebra/matrix.cpp.html
title: linearalgebra/matrix.cpp
---

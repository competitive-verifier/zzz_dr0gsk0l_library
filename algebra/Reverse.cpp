#pragma once
template<typename Algebra>
struct AlgebraReverse:Algebra{
  using X=typename Algebra::value_type;
  static constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }
  static constexpr void chop(X&x,const X&y){ x=op(y,x); }
};
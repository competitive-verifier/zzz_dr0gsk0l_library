```cpp
template<typename X>
struct MonoidHoge{
  using value_type=X
  static constexpr X op(const X& x, const X& y)
  static constexpr void Rchop(X&x, const X&y){ x=op(x,y); }
  static constexpr void Lchop(const X&x, X&y){ y=op(x,y); }
  static constexpr X power(const X& x, const long long n)
  static constexpr X unit()
  static constexpr bool commute
};
```

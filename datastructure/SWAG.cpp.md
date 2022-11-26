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
  bundledCode: "#line 2 \"datastructure/SWAG.cpp\"\ntemplate<typename Monoid>\nclass\
    \ SWAG{\n  using X=typename Monoid::value_type;\n\n  stack<X> back_stack,front_stack;\
    \ // back \u306F\u5F8C\u308D\u306E\u5404\u8981\u7D20 front \u306F\u524D\u306E\u7D2F\
    \u7A4D\u548C\n  X back_value;\n\n  inline X front_value()const{\n    return front_stack.size()?front_stack.top():Monoid::unit();\n\
    \  }\npublic:\n  SWAG():back_value(Monoid::unit()){}\n  void push_back(X x){\n\
    \    back_stack.push(x);\n    back_value=Monoid::op(back_value,a);\n  }\n  void\
    \ push_front(Monoid a){\n    front_stack.push(Monoid::op(a,front_value));\n  }\n\
    \  void pop_front(){\n    if(front_stack.empty()){\n      if(back_stack.empty())return;\n\
    \      while(back_stack.size()){\n        push_front(back_stack.top());\n    \
    \    back_stack.pop();\n      }\n      back_value=Monoid::unit();\n    }\n   \
    \ front_stack.pop();\n  }\n  X fold(){\n    return Monoid::op(front_value(),back_value);\n\
    \  }\n};\n"
  code: "#pragma once\ntemplate<typename Monoid>\nclass SWAG{\n  using X=typename\
    \ Monoid::value_type;\n\n  stack<X> back_stack,front_stack; // back \u306F\u5F8C\
    \u308D\u306E\u5404\u8981\u7D20 front \u306F\u524D\u306E\u7D2F\u7A4D\u548C\n  X\
    \ back_value;\n\n  inline X front_value()const{\n    return front_stack.size()?front_stack.top():Monoid::unit();\n\
    \  }\npublic:\n  SWAG():back_value(Monoid::unit()){}\n  void push_back(X x){\n\
    \    back_stack.push(x);\n    back_value=Monoid::op(back_value,a);\n  }\n  void\
    \ push_front(Monoid a){\n    front_stack.push(Monoid::op(a,front_value));\n  }\n\
    \  void pop_front(){\n    if(front_stack.empty()){\n      if(back_stack.empty())return;\n\
    \      while(back_stack.size()){\n        push_front(back_stack.top());\n    \
    \    back_stack.pop();\n      }\n      back_value=Monoid::unit();\n    }\n   \
    \ front_stack.pop();\n  }\n  X fold(){\n    return Monoid::op(front_value(),back_value);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/SWAG.cpp
  requiredBy: []
  timestamp: '2022-11-26 19:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/SWAG.cpp
layout: document
redirect_from:
- /library/datastructure/SWAG.cpp
- /library/datastructure/SWAG.cpp.html
title: datastructure/SWAG.cpp
---

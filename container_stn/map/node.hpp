#ifndef NODE_HPP
# define NODE_HPP

#include <stdlib.h>

namespace ft
{
  template <class T>
  struct node
  {
      T      _value;
      node * _parent;
      node * _left;
      node * _right;

      node() : _value(), _parent(NULL), _left(NULL), _right(NULL)
      {};
      node(const T & value) : _value(value), _parent(NULL), _left(NULL), _right(NULL)
      {};
      node(const T & value, node<T> * parent) : _value(value), _parent(parent), _left(NULL), _right(NULL)
      {};
  };

} // namespace

#endif

#pragma once

namespace ft
{
    template < class T >
    class node
    {
        public:
            node *      _parent;
            node *      _left;
            node *      _right;
            T           _value;
            char        _depth;

            // (1) default
            node()
            : _value(), _parent(NULL), _left(NULL), _right(NULL), _depth(0)
            {};
            // (2) fill
            node(const T & value)
            : _value(value), _parent(NULL), _left(NULL), _right(NULL), _depth(0)
            {};
            // (3) fill and link to parent
            node(const T & value, node<T> * parent)
            : _value(value), _parent(parent), _left(NULL), _right(NULL), _depth(0)
            {};
    };
}

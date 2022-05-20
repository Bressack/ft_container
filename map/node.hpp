#pragma once

namespace ft
{
    template < class T >
    class node
    {
        public:
            node *      parent;
            node *      left;
            node *      right;
            T           value;
            char        depth;

            // (1) default
            node()
            : value(), parent(NULL), left(NULL), right(NULL), depth(0)
            {};
            // (2) fill
            node(const T & _value)
            : value(_value), parent(NULL), left(NULL), right(NULL), depth(0)
            {};
            // (3) fill and link to parent
            node(const T & _value, node<T> * _parent)
            : value(_value), parent(_parent), left(NULL), right(NULL), depth(0)
            {};
    };
}

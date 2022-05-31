#pragma once

namespace ft
{
    enum e_child {
        RIGHT,
        LEFT
    };

    template < class T >
    class node
    {
        public:
            node *      parent;
            node *      left;
            node *      right;
            T           value;

            // +1 if child come from right
            // -1 if child come from left
            // int         _depth;

        public:

            // (1) default
            node()
            : parent(NULL), left(NULL), right(NULL), value(NULL)//, _depth(0)
            {};
            // (2) fill
            node(const T & _value)
            : parent(NULL), left(NULL), right(NULL), value(_value)//, _depth(0)
            {};
            // (3) fill and link to parent
            node(const T & _value, node<T> * _parent)
            : parent(_parent), left(NULL), right(NULL), value(_value)//, _depth(0)
            {};

            // int     get_depth(void) { return (_depth); }
            // void    set_depth(int depth) { _depth = depth; }

    };
}

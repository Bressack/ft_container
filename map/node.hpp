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

        public:

            // (1) default
            node()
            : parent(NULL), left(NULL), right(NULL)
            {printf(C_G_RED "node constructor (1) default\n" C_RES);};
            // (2) fill
            node(const T & _value)
            : parent(NULL), left(NULL), right(NULL), value(_value)
            {printf(C_G_RED "node constructor (2) fill\n" C_RES);};
            // (3) fill and link to parent
            node(const T & _value, node<T> * _parent)
            : parent(_parent), left(NULL), right(NULL), value(_value)
            {printf(C_G_RED "node constructor (3) fill and link to parent\n" C_RES);};
            node &operator=(const node* & other)
            {
                parent = other->parent;
                left = other->left;
                right = other->right;
                return (*this);
            };
    };
}

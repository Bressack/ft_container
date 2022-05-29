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

        private:
            int         _depth;

        public:

            // (1) default
            node()
            : parent(NULL), left(NULL), right(NULL), value(NULL), _depth(0)
            {};
            // (2) fill
            node(const T & _value)
            : parent(NULL), left(NULL), right(NULL), value(_value), _depth(0)
            {};
            // (3) fill and link to parent
            node(const T & _value, node<T> * _parent)
            : parent(_parent), left(NULL), right(NULL), value(_value), _depth(0)
            {};

            int    get_depth(void) { return (_depth); }
            void   update_depth() { update_depth(0); }
            void   update_depth(int depth_updated)
            {
                _depth += depth_updated;
                if (parent)
                {
                    if (parent->left == this)
                        parent->update_depth(_depth - 1);
                    else
                        parent->update_depth(_depth + 1);
                }
            }
    };
}

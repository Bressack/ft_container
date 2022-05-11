#pragma once

#include "../vector/vector.hpp"
#include "../others/pair.hpp"
#include "node.hpp"

namespace ft
{
    // template< class K, class V, class Container = ft::vector<ft::pair<K,ft::node<V> > > >
    template< class K, class V, class Container = ft::vector<ft::node<K,V> > >
    class tree
    {
        public:
            typedef K                                           key_type;
            typedef V                                           value_type;
            typedef Container                                   container_type;
            typedef size_t                                      size_type;

            typedef ft::node<key_type, value_type>              node_type;
            typedef ft::node<key_type, value_type>*             node_pointer;

        protected:
            container_type  _drawer;

        private:
            node_pointer    _root;

            node_pointer find_new_parent(node_pointer child)
            { // PAS FINI
                if (empty())
                    _root = child;
                else
                {
                    node_pointer tmp = _root;

                    while (1)
                    {
                        if (child->_key < tmp->_key)
                            if (tmp->_left)
                                tmp = tmp->_left;
                            else
                                return tmp;
                        else
                            if (tmp->right)
                                tmp = tmp->_right;
                            else
                                return tmp;
                    }
                }
            }

        public:
            tree() {};
            ~tree() {};

            bool                empty() { return (c.empty()); }
            size_type           size() const { return (c.size()); }
            size_type           max_size() const { return (c.max_size()); }
            size_type           capacity() const { return(c.capacity()); }

            // (1) push pair
            pair_type           push(const pair_type & pair)
            {
                
            }
            // (2) push key + value
            pair_type           push(const key_type & key, const value_type & value)
            { return (push(pair_type(key, value))); }
            void                pop();
    };
}

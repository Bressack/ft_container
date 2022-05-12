#pragma once

#include "../vector/vector.hpp"
#include "../others/pair.hpp"
#include "node.hpp"

namespace ft
{
    // template< class K, class V, class Container = ft::vector<ft::pair<K,ft::node<V> > > >
    template<   class K,
                class V,
                class Pair = ft::pair<K,V>,
                class Node = ft::node<Pair>,
                class Container = ft::vector<Node>
    > class tree
    {
        public:
            // tree type
            typedef K                 key_type;
            typedef V                 value_type;
            typedef Pair              node_value;
            typedef Container         container_type;
            typedef size_t            size_type;

            // node types
            typedef Node              node_type;
            typedef Node*             node_pointer;

            // drawer type
            typedef container_type::iterator    drawer_iterator;

        protected:
            container_type  _drawer; // node storage

        private:
            node_pointer    _root; // tree entrypoint (pointer to drawer nodes)

            node_pointer find_new_parent(node_pointer child)
            {
                if (empty())
                    _root = child;
                else
                {
                    node_pointer tmp = _root;

                    while (1) // si inf loop c'est qu'on a un ptit soucis :/
                    {
                        if (child->_value.first < tmp->_value.first)
                            if (tmp->_left) tmp = tmp->_left else tmp->_left = child, break;
                        else
                            if (tmp->right) tmp = tmp->_right else tmp->_right = child, break;
                    }
                }
            }

            // drawer tools
            drawer_iterator find_drawer_free_place();


        public:
            tree() {};
            ~tree() {};

            bool                empty() { return (c.empty()); }
            size_type           size() const { return (c.size()); }
            size_type           max_size() const { return (c.max_size()); }
            size_type           capacity() const { return(c.capacity()); }

            // (1) push pair
            node_type           push(const pair_type & pair)
            {
                Node            new_node(pair);
                node_pointer parent = find_new_parent(new_node);

                
            }
            // (2) push key + value
            pair_type           push(const key_type & key, const value_type & value)
            { return (push(pair_type(key, value))); }
            void                pop();
    };
}

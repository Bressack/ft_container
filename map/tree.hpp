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

            // iterator

            // node types
            typedef Node              node_type;
            typedef Node*             node_pointer;
            typedef Node&             node_reference;

            // drawer type
            typedef typename container_type::iterator    drawer_iterator;

        protected:
            container_type  _drawer; // node storage

        private:
            node_pointer    _root; // tree entrypoint (pointer to drawer nodes)

            void    find_new_parent(node_pointer child)
            {
                if (empty())
                    _root = child;
                else
                {
                    node_pointer tmp = _root;

                    while (1) // si inf loop c'est qu'on a un ptit soucis :/
                    {
                        if (child->_value.first < tmp->_value.first)
                            if (tmp->_left) tmp = tmp->_left; else { tmp->_left = child; break; }
                        else
                            if (tmp->_right) tmp = tmp->_right; else { tmp->_right = child; break; }
                    }
                }
            }

            /// drawer tools

            // function to find a free place in the drawer to the new node
            node_pointer    find_drawer_free_place(const node_value & value)
            {
                _drawer.push_back(Node(value));
                return (&_drawer.back());
            }

        public:
            tree() {};
            ~tree() {};

            bool                empty() { return (_drawer.empty()); }
            size_type           size() const { return (_drawer.size()); }
            size_type           max_size() const { return (_drawer.max_size()); }
            size_type           capacity() const { return(_drawer.capacity()); }

            // (1) push pair
            node_pointer           push(const node_value & value)
            {
                node_pointer    new_node = find_drawer_free_place(value);
                find_new_parent(new_node);
                return (new_node);
            }
            // (2) push key + value
            node_value           push(const key_type & key, const value_type & value)
            { return (push(node_value(key, value))); }
            void                pop();

            // print the drawer content
            void            print_drawer_content(void)
            {

            }

            void            print_tree(node_reference root) { print_tree(&root); }
            void            print_tree(node_pointer root = _root, int deep = 0, int pad = 2)
            {
                std::cout << std::setw(deep * pad) << "" << "[ " << root->_value.first << " ] ( " << root->_value.first << " )" << std::endl;
                if (root->_right) print_tree(root->_right, deep + 1);
                if (root->_left)  print_tree(root->_left, deep + 1);
            }
    };
}

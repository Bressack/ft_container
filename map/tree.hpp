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

            node_pointer    find_parent(const node_value & value)
            {
                
                node_pointer tmp = _root;

                if (tmp == NULL)
                    return NULL;
                while (1) // si inf loop c'est qu'on a un ptit soucis :/
                {
                    if (child->_value.first < tmp->_value.first)
                        if (tmp->_left) tmp = tmp->_left; else return tmp->_left;
                    else
                        if (tmp->_right) tmp = tmp->_right; else return tmp->_right;
                }
            }

            /// drawer tools

            void            assign_child_to_parent(node_pointer parent, const node_pointer child)
            {
                if (child->_value.first < parent->_value.first)
                {
                    parent->_left = child;
                    parent->depth -= 1;
                }
                else
                {
                    parent->_right = child;
                    parent->depth += 1;
                }
                child->parent = parent;
            }

            node_pointer    find_drawer_free_place(const node_value & value)
            {
                // find a parent
                node_pointer parent = find_parent(value)
                // create new node in drawer and brings together parent and child
                _drawer.push_back(Node(value));
                node_pointer child = &_drawer.back();
                if (parent != NULL)
                    assign_child_to_parent(parent, child);
                else
                    _root = child;
                return (child);
            }

        public:
            tree() : _root(NULL) {};
            ~tree() { clear(); };

            bool                empty() { return (_drawer.empty()); }
            size_type           size() const { return (_drawer.size()); }
            size_type           max_size() const { return (_drawer.max_size()); }
            size_type           capacity() const { return(_drawer.capacity()); }
            void                clear() { _drawer.clear(); }

            // (1) push pair
            node_pointer           push(const node_value & value)
            {
                return (find_drawer_free_place(value));
            }
            // (2) push key + value
            node_value           push(const key_type & key, const value_type & value)
            { return (push(node_value(key, value))); }
            void                pop();

            // print the drawer content
            void            print_drawer_content(void)
            {
                for ( drawer_iterator it = _drawer.begin(); it != _drawer.end() ; it++ )
                    std::cout << "[" << (*it)._value.first << " -> " << (*it)._value.second << "]" << std::endl;
            }

            void            print_tree(node_reference root) { print_tree(&root); }
            void            print_tree(node_pointer root = NULL, int deep = 0, int pad = 2)
            {
                if (root == NULL)
                    root = _root;
                std::cout << std::setw(deep * pad) << "" << "[ " << root->_value.first << " ] ( " << root->_value.second << " )" << std::endl;
                if (root->_left)  { std::cout << std::setw(deep * pad) << "" << "left  child:" << std::endl; print_tree(root->_left, deep + 1); }
                if (root->_right) { std::cout << std::setw(deep * pad) << "" << "right child:" << std::endl; print_tree(root->_right, deep + 1); }
            }
    };
}

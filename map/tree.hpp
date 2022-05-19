#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/pair.hpp"
# include "node.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class tree
    {
        public:

            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef Compare                                 key_compare;
            typedef Alloc                                   allocator_type;
            typedef ft::pair<key_type, mapped_type>         value_type;
            typedef ft::tree_iterator<value_type>           iterator;
            typedef ft::const_tree_iterator<value_type>     const_iterator;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

            typedef ft::node<value_type>                    node_type;
            typedef ft::node<value_type>*                   node_pointer;

            typedef size_t                                  size_type;
        
            typedef	typename allocator_type::template rebind<node_type>::other	node_alloc_type;

            tree() {}
            virtual ~tree() {}

            tree& operator=(const tree &x) {}

        private:

            node_pointer    _end;
            node_pointer    _root;
            int             _size;

            // destroy a node and all its childs
            void clear_node (node_pointer node) {}
            
            // destroy all the tree
            void clear_tree () {}

            // deep copy a node with all its child and add it to the tree
            void copy_node (node_pointer node) {}

            // calculate the depth of a node
            int depth (const node_pointer node) const

            // update the end node to point it to root and root parent point to it
            void update_end () {}

            // find the minimum node of the tree (with the smallest key)
            node_pointer maximum (node_pointer node) const {}
            
            // find the maximum node of the tree (with the higher key)
            node_pointer minimum (node_pointer node) const {}

            // find a parent for a node
            node_pointer find_future_parent (const value_type &value) const

            // add 
            int simple_add (const value_type &value)
    };

};
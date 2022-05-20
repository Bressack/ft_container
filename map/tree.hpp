#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/pair.hpp"
# include "node.hpp"
# include <iostream>

#define TTEST {std::cout << _TEST_ << std::endl;}

enum NODE_KEY_COMPARE_RES {
    SMALLER,
    HIGHER,
    NOTALLOCATED
};

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class tree
    {
        public: // TYPES DEFINITIONS

            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef Compare                                 key_compare;
            typedef Alloc                                   allocator_type;
            typedef ft::pair<key_type, mapped_type>         value_type;
            // typedef ft::tree_iterator<value_type>           iterator;
            // typedef ft::const_tree_iterator<value_type>     const_iterator;
            // typedef ft::reverse_iterator<iterator>          reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

            typedef ft::node<value_type>                    node_type;
            typedef ft::node<value_type>*                   node_pointer;

            typedef size_t                                  size_type;
        
            typedef	typename allocator_type::template rebind<node_type>::other	node_alloc_type;

        private: // ATTRIBUTS

            node_pointer    _end;
            node_pointer    _root;
            int             _size;
        
        public: // CONSTRUCTORS / DESTRUCTOR //
            tree() :  {}
            virtual ~tree() {}

            tree& operator=(const tree &x) {}

        public:
            /*
                function name: create_node
                returned value: node_pointer
                args:
                    - value_type & value
                    - node_pointer parent = NULL
            */
            node_pointer    create_node(const value_type & value, node_pointer parent = NULL)
            {
                return(new node_type(value, parent));
            }

            void    destroy_node(node_pointer & node)
            {
                if (node != NULL)
                    delete(node);
                node = NULL;
            }

            // destroy a node and all its childs
            void clear_node (node_pointer node)
            {
                if (node == NULL)
                    return ;
                clear_node(node->left);
                clear_node(node->right);
                destroy_node(node);
            }
            
            // destroy all the tree
            void clear_tree () { clear_node(_root); _root = NULL; }

            // deep copy a node with all its child and add it to the tree
            void copy_node (node_pointer node) {}

            // calculate the depth of a node
            int depth (const node_pointer node) const {}

            // update the end node to point it to root and root parent point to it
            void update_end () {}

            // compare two nodes with their keys
            enum NODE_KEY_COMPARE_RES node_key_compare(node_pointer ref, node_pointer node)
            {TTEST
                if (ref == NULL || node == NULL)
                    return (NOTALLOCATED);
                TTEST
                std::cout << node->value << " | " << ref->value << std::endl;
                if (node->value.first > ref->value.first)
                    return (HIGHER);
                else
                    return (SMALLER);
            }

            // find the minimum node of the tree (with the smallest key)
            node_pointer minimum (node_pointer node) const
            {
                if (node)
                {
                    while (node->left != NULL)
                        node = node->left;
                }
                return (node);
            }
            
            // find the maximum node of the tree (with the higher key)
            node_pointer maximum (node_pointer node) const
            {
                if (node)
                {
                    while (node->right != NULL)
                        node = node->right;
                }
                return (node);
            }

            // find a parent for a node
            node_pointer find_future_parent (const node_pointer & node, bool assign = false)
            {TTEST
                node_pointer tmp = _root;
                enum NODE_KEY_COMPARE_RES res = NOTALLOCATED;

                while (1)
                {TTEST
                    res = node_key_compare(tmp, node);  
                    TTEST  
                    if (res == SMALLER) {TTEST
                        if (!tmp->left) {TTEST
                            if (assign == true)
                                tmp->left = node;
                            return (tmp);
                        }
                        tmp = tmp->left;
                    }
                    else if (res == HIGHER) {TTEST
                        if (!tmp->right) {TTEST
                            if (assign == true)
                                tmp->right = node;
                            return (tmp);
                        }
                        tmp = tmp->right;
                    }
                    else return _root;
                }
            }

            // add 
            void add (const value_type & value)
            {TTEST
                node_pointer new_node = create_node(value);
                node_pointer parent = find_future_parent(new_node, true);
                // find_future_parent(create_node(value), true);
                // balance_tree()
            }

    };

};
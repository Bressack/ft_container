#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/pair.hpp"
# include "display_tree.hpp"
# include "node.hpp"
# include <iostream>
# include <vector>


#define TTEST {std::cout << _TEST_ << std::endl;}

namespace diff
{
    template< typename T >
    T   max(T a, T b) { return (a > b ? a : b); }
    template< typename T >
    T   min(T a, T b) { return (a < b ? a : b); }
}

enum NODE_KEY_COMPARE_RES {
    SMALLER,
    HIGHER,
    NOTALLOCATED,
    EQUAL
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

            typedef typename allocator_type::template rebind<node_type>::other	node_alloc_type;

        private: // ATTRIBUTS

            ft::displaytree<node_type>     _dt;

            node_pointer    _end;
            node_pointer    _root;
            int             _size;

        public: // CONSTRUCTORS / DESTRUCTOR //
            tree() : _end(NULL), _root(NULL), _size(0) {}
            virtual ~tree() { clear_tree(); }

            // tree& operator=(const tree &x) {}

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
            // void copy_node (node_pointer node) {}

            // calculate the depth of a node
            // int depth (const node_pointer node) const {}

            // update the end node to point it to root and root parent point to it
            // void update_end () {}

            // compare two nodes with their keys
            enum NODE_KEY_COMPARE_RES node_key_compare(node_pointer ref, node_pointer node)
            {
                if (ref == NULL || node == NULL)
                    return (NOTALLOCATED);
                if (node->value.first > ref->value.first)
                    return (HIGHER);
                if (node->value.first < ref->value.first)
                    return (SMALLER);
                if (node->value.first == ref->value.first)
                    return (EQUAL);
                return (NOTALLOCATED);
            }

            node_pointer    search(const value_type & value)
            {
                node_type node(value);
                node_pointer tmp = _root;

                while (1)
                {
                    enum NODE_KEY_COMPARE_RES diff = node_key_compare(tmp, &node);
                    if (diff == NOTALLOCATED)
                        break ;
                    else if (diff == HIGHER)
                        tmp = tmp->right;
                    else if (diff == SMALLER)
                        tmp = tmp->left;
                    else if (diff == EQUAL)
                        return (tmp);
                }
                return (NULL);
            }

            // find the minimum node of the tree (with the smallest key)
            node_pointer    minimum (node_pointer node) const
            {
                if (node)
                {
                    while (node->left != NULL)
                        node = node->left;
                }
                return (node);
            }

            // find the maximum node of the tree (with the higher key)
            node_pointer    maximum (node_pointer node) const
            {
                if (node)
                {
                    while (node->right != NULL)
                        node = node->right;
                }
                return (node);
            }

            node_pointer    prev_value(node_pointer node) const // find the prev close up value of a node
            {
                // first left then full right
                node = node->left;
                while (node)
                    if (node->right)
                        node = node->right;
                return (node);
            }

            node_pointer    next_value(node_pointer node) const // find the next close up value of a node
            {
                // first right then full left
                node = node->right;
                while (node)
                    if (node->left)
                        node = node->left;
                return (node);
            }

            // find a parent for a node
            node_pointer    find_future_parent (const node_pointer & node, bool assign = false)
            {
                node_pointer tmp = _root;
                enum NODE_KEY_COMPARE_RES res = NOTALLOCATED;

                while (1)
                {
                    res = node_key_compare(tmp, node);

                    if (res == SMALLER) {
                        if (!tmp->left) {
                            if (assign == true)
                            {
                                tmp->left = node;
                                node->parent = tmp;
                            }
                            return (tmp);
                        }
                        tmp = tmp->left;
                    }
                    else if (res == HIGHER) {
                        if (!tmp->right) {
                            if (assign == true)
                            {
                                tmp->right = node;
                                node->parent = tmp;
                            }
                            return (tmp);
                        }
                        tmp = tmp->right;
                    }
                    else return _root;
                }
            }

            void            update_tree_depth(node_pointer node)
            {
                while (1)
                {
                    node_pointer parent = node->parent;
                    if (!parent)
                        break ;
                    else if (parent->left == node)
                        parent->update_depth(LEFT);
                    else if (parent->right == node)
                        parent->update_depth(RIGHT);
                    node = parent;
                }
            }

            void            tree_to_vector(std::vector<node_pointer> & v, node_pointer node)
            {
                if (!node)
                    return ;
                v.push_back(node);
                tree_to_vector(v, node->left);
                tree_to_vector(v, node->right);
            }

            bool            is_tree_legal(void)
            {
                bool islegal = true;
                std::vector<node_pointer> v;
                typename std::vector<node_pointer>::iterator it;

                tree_to_vector(v, _root);
                it = v.begin();
                while (it != v.end())
                {
                    if (search((*it)->value) == NULL)
                    {
                        islegal = false;
                        std::cout << "unreachable node -> " << (*it)->value.first << std::endl;
                    }
                    it++;
                }
                return (islegal);
            }

            // add
            void            add (const value_type & value)
            {
                node_pointer new_node = create_node(value);
                if (_root == NULL)
                    _root = new_node;
                else
                    find_future_parent(new_node, true);
                update_tree_depth(new_node);
                // find_future_parent(create_node(value), true);
                // balance_tree()
            }

            void            print_tree(void) { print_tree(_root); }
            void            print_tree(node_pointer tmp, int deep = 0)
            {
                if (!tmp)
                    return ;

                for (size_t i = 0; i < deep; i++)
                    std::cout << "|   ";
                std::cout << tmp->value << " - " << tmp->get_depth() << std::endl;
                print_tree(tmp->left, deep + 1);
                print_tree(tmp->right, deep + 1);
            }

            void            display(void)
            {
                _dt.tree_draw(_root);
            }
    };

};

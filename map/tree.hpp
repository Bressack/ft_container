#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/pair.hpp"
# include "display_tree.hpp"
# include "node.hpp"
# include <iostream>
# include <vector>
# include <memory>
# include <functional>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

# define TTEST(...) {char *debugs;asprintf(&debugs, __VA_ARGS__);std::cout << _TEST_ << "  " << debugs << std::endl;free(debugs);}

namespace ft
{
    template <class T>
    struct less : std::binary_function <T,T,bool> {
        bool operator() (const T& x, const T& y) const {return x<y;}
    };

    ///////////////////////////////////////////////////////////////////////////

    template <  class K,
                class T,
                class Alloc = std::allocator<ft::node<ft::pair<K, T> > >,
                class Compare = ft::less<K>
             >
    class tree
    {
        /* ***************************************************************** *\
        |                       INNER TYPES DEFINITION                        |
        \* ***************************************************************** */

        public:
            typedef K                                           key_type;
            typedef T                                           mapped_type;
            typedef ft::pair<key_type, mapped_type>             value_type;
            typedef ft::node<value_type>                        node_type;
            typedef ft::node<value_type>*                       node_pointer;
            typedef ft::pair<node_pointer, node_pointer*>       future_parent;

            // ALLOCATOR
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;

            // COMPARE
            typedef Compare                                     key_compare;

        /* ***************************************************************** *\
        |                     INNER ATTRIBUTES DEFINITION                     |
        \* ***************************************************************** */
        private:
            // DEVTOOL - display_tree.hpp
            ft::displaytree<node_type>  _dt;

            node_pointer                _end;
            node_pointer                _root;
            size_type                   _size;
            Alloc                       _allocator;

        /* ***************************************************************** *\
        |                      CONSTRUCTOR / DESTRUCTOR                       |
        \* ***************************************************************** */

        public:
            tree(const allocator_type &alloc = allocator_type()) : _end(NULL), _root(NULL), _size(0), _allocator(alloc) {}
            virtual ~tree() { clear_tree(); }

        /* ***************************************************************** *\
        |                        METHODS DEFINITION                           |
        \* ***************************************************************** */

        private:
        // allocations
            node_pointer        __allocate_node(const value_type & value, node_pointer parent = NULL)
            {
                node_pointer node = _allocator.allocate(1);
                _allocator.construct(node, node_type(value, parent));
                return (node);
            }
            void                __deallocate_node(const node_pointer & node)
            {
                if (node != NULL)
                    _allocator.deallocate(node, sizeof(node_type));
            }


// cannot initialize a parameter of type
// 'ft::tree<int, int>::node_pointer (*)(const ft::tree<int, int>::node_pointer &)'
// (aka 'node<pair<int, int>> *(*)(node<pair<int, int>> *const &)')
// with an rvalue of type
// 'ft::tree<int, int>::node_pointer (ft::tree<int, int>::*)(const ft::tree<int, int>::node_pointer &)'

        public:
            // tools
            void                infix_apply(const node_pointer node, node_pointer(tree::*f)(const node_pointer &))
            {
                if (node == NULL)
                    return ;
                if (node->left)
                    infix_apply(node->left, f);
                (this->*f)(node);
                if (node->right)
                    infix_apply(node->right, f);
            }

            // capacity
            inline bool         empty(void)
            {
                return (_size == 0);
            }
            inline size_type    size(void)
            {
                return (_size);
            }
            inline size_type    max_size(void)
            {
                return (_allocator.max_size());
            }

            // modifiers
            node_pointer        insert(const node_pointer & node)
            {
                printf(C_G_ORANGE "insert (node=%p)\n" C_RES, node);
                if (empty() == true) // tree is empty
                {
                    _root = node;
                    printf("tree empty - %p - %p\n", _root, node);
                }
                else // tree is not empty
                {
                    printf("tree not empty\n");
                    future_parent parent = __find_future_parent(node);
                    node->parent = parent.first;
                    *parent.second = node;
                    __balance_tree(node);
                }
                _size += 1;
                return (node);
            }
            node_pointer        insert(const value_type & value)
            {
                printf(C_G_GREEN "insert (value)\n" C_RES);
                // check if the tree already contain a node with a key equivalent, if so, return an pointer to the node
                node_pointer tmp = search(value);
                if (tmp != NULL)
                {
                    std::cout << "node already insered" << std::endl;
                    return (tmp);
                }
                node_pointer n = __allocate_node(value);
                return (insert(n));
            }
            node_pointer        insert(const key_type & key, const mapped_type & value)
            {
                printf(C_G_GREEN "insert (key=%d, val=%d)\n" C_RES, key, value);
                return (insert(value_type(key, value)));
            }

            node_pointer        detach_node_from_parent(node_pointer node)
            {
                if (node->parent)
                {
                    if (node->parent->left == node)
                        node->parent->left = NULL;
                    else if (node->parent->right == node)
                        node->parent->right = NULL;
                    node->parent = NULL;
                    return (node);
                }
                else
                    return (NULL);
            }

            node_pointer        *get_parent_endpoint(node_pointer node)
            {
                if (node && node->parent)
                {
                    if (node->parent->left == node)
                        return (&node->parent->left);
                    else
                        return (&node->parent->right);
                }
                else
                    return (NULL);
            }

            node_pointer        remove(node_pointer & node)
            {
                if (node == NULL)
                    return (NULL);

                else if (node->left == NULL && node->right == NULL) {
                    TTEST("feuille")
                    /* feuille
                    |
                    |   if node is not root:
                    |       [ ]
                    |      /   \
                    |   [X]     [ ]
                    |
                    |   if node is root:
                    |   [X]
                    */
                    // detach the node of the tree
                    if (detach_node_from_parent(node) == NULL)
                        _root = NULL;
                }
                else if (node->left && !node->right) {
                    TTEST("only left child")
                    /* only left child
                    |
                    |   if node is not root:
                    |        [ ]
                    |       /   \
                    |    [ ]     [X]
                    |           /
                    |        [ ]
                    |       /   \
                    |    [ ]     [ ]
                    |
                    |   if node is root:
                    |           [X]
                    |          /
                    |       [ ]
                    |      /   \
                    |   [ ]     [ ]
                    */
                    node_pointer *tmp = get_parent_endpoint(node);
                    if (tmp == NULL)
                    {
                        _root = node->left;
                        _root->parent = NULL;
                    }
                    else
                    {
                        node->left->parent = node->parent;
                       *tmp = node->left;
                    }
                }

                else if (node->right && !node->left) {
                    TTEST("only right child")
                    /* only right child
                    |
                    |   if node is not root:
                    |        [ ]
                    |       /   \
                    |    [X]     [ ]
                    |       \
                    |        [ ]
                    |       /   \
                    |    [ ]     [ ]
                    |
                    |   if node is root:
                    |   [X]
                    |      \
                    |       [ ]
                    |      /   \
                    |   [ ]     [ ]
                    */
                    node_pointer *tmp = get_parent_endpoint(node);
                    if (tmp == NULL)
                    {
                        _root = node->right;
                        _root->parent = NULL;
                    }
                    else
                    {
                        node->right->parent = node->parent;
                       *tmp = node->right;
                    }
                }

                else if (node->right && node->left) {
                    TTEST("two child")
                    /* two child
                    |
                    |   if node is not root:
                    |        [ ]
                    |       /   \
                    |    [X]     [ ]
                    |   /   \
                    |[ ]     [ ]
                    |   if node is root:
                    |        [X]
                    |       /   \
                    |    [ ]     [ ]
                    */
                    int depth = __get_node_depth(node);
                    node_pointer *tmp = get_parent_endpoint(node);

                    if (depth < 0)
                    {
                        node_pointer prev = prev_value(node);
                        node_pointer *prevparent = get_parent_endpoint(prev);

                        // on met a NULL le lien entre le parent du prev et prev
                        *prevparent = NULL;
                        // on swap les liens entre prev et node (prev prend la place de node)
                        prev->left = node->left;
                        prev->right = node->right;
                        prev->parent = node->parent;
                        // si _root pointait sur node alors _root pointe mtn sur prev
                        // sinon le parent de node prend comme enfant prev au lieu de node
                        if (tmp == NULL)
                            _root = prev;
                        else
                            *tmp = prev;
                    }
                    else
                    {
                        node_pointer next = next_value(node);
                        node_pointer *nextparent = get_parent_endpoint(next);

                        // on met a NULL le lien entre le parent du next et next
                        *nextparent = NULL;
                        // on swap les liens entre next et node (next prend la place de node)
                        next->left = node->left;
                        next->right = node->right;
                        next->parent = node->parent;
                        // si _root pointait sur node alors _root pointe mtn sur next
                        // sinon le parent de node prend comme enfant next au lieu de node
                        if (tmp == NULL)
                            _root = next;
                        else
                            *tmp = next;
                    }
                }
                _size -= 1;
                std::cout << GREEN_TREE << "DELETE NODE " << C_G_PINK << node << LIGHT_BLUE << "(" << node->value.first << ")" << C_RES << std::endl;
                __deallocate_node(node);
                return (NULL);
            }
            node_pointer        remove(value_type & value)
            {
                node_pointer tmp = search(value);
                TTEST("remove value {k:%d, v:%d}", value.first, value.second);
                return (remove(tmp));
            }
            node_pointer        remove(key_type & key)
            {
                node_pointer tmp = search(key);
                TTEST("remove key %d", key);
                return (remove(tmp));
            }

            void                swap(node_pointer & a, node_pointer & b)
            {
                node_pointer   t_p = a->parent;
                node_pointer   t_l = a->left;
                node_pointer   t_r = a->right;

                a->parent = b->parent;
                a->left = b->left;
                a->right = b->right;

                b->parent = t_p;
                b->left = t_l;
                b->right = t_r;
            }
            void                clear_node(node_pointer & node)
            {
                if (node == NULL)
                    return ;
                if (node->left)
                    clear_node(node->left);
                __deallocate_node(node);
                if (node->right)
                    clear_node(node->right);
                node = NULL;
            }
            void                clear_tree(void)
            {
                clear_node(_root);
            }

            // accessors
            node_pointer        lower_bound(const key_type & key)
            {
                node_pointer    tmp = _root;
                node_pointer    kandida = NULL;

                while (1)
                {
                    if (tmp == NULL)
                        return (kandida);
                    if (tmp->value.first > key)
                        kandida = tmp;
                    if (__compare(key, tmp) == true)
                        tmp = tmp->left;
                    else
                        tmp = tmp->right;
                }
            }
            node_pointer        upper_bound(const key_type & key)
            {
                node_pointer    tmp = _root;
                node_pointer    kandida = NULL;

                while (1)
                {
                    if (tmp == NULL)
                        return (kandida);
                    if (tmp->value.first >= key)
                        kandida = tmp;
                    if (__compare(key, tmp) == true)
                        tmp = tmp->left;
                    else
                        tmp = tmp->right;
                }
            }

            node_pointer        search(const node_pointer & node) const
            {
                return (search(node->value.first));
            }
            node_pointer        search(const value_type & value) const
            {
                return (search(value.first));
            }
            node_pointer        search(const key_type & key) const
            {
                node_pointer tmp = _root;

                while (1)
                {
                    if (tmp == NULL)
                        return (NULL);
                    if (tmp->value.first == key)
                        return (tmp);
                    if (__compare(key, tmp) == true)
                        tmp = tmp->left;
                    else
                        tmp = tmp->right;
                }
            }

            node_pointer        prev_value (node_pointer node) const
            {
                if (node == NULL)
                    return (NULL);
                // first left then full right
                node = node->left;
                if (node)
                    while (node->right)
                        node = node->right;
                return (node);
            }
            node_pointer        next_value (node_pointer node) const
            {
                if (node == NULL)
                    return (NULL);
                // first right then full left
                node = node->right;
                if (node)
                    while (node->left)
                        node = node->left;
                return (node);
            }

        private:
            future_parent       __find_future_parent (const node_pointer & node) const
            {
                node_pointer tmp = _root;

                while (1)
                {
                    if (__compare(node, tmp) == true)
                    {
                        if (tmp->left)
                            tmp = tmp->left;
                        else
                            return (future_parent(tmp, &tmp->left));
                    }
                    else
                    {
                        if (tmp->right)
                            tmp = tmp->right;
                        else
                            return (future_parent(tmp, &tmp->right));
                    }
                }
            }
            void                __right_rotate (node_pointer node)
            {
                if (node == NULL)
                    return;

                node_pointer left_child = node->left;

                if (node->parent != NULL)
                {
                    if (node->parent->left == node)
                        node->parent->left = left_child;
                    else
                        node->parent->right = left_child;
                }
                if (left_child)
                {
                    left_child->parent = node->parent;

                    if (left_child->right != NULL)
                        left_child->right->parent = node;
                    node->left = left_child->right;

                    node->parent = left_child;
                    left_child->right = node;
                }
                    if (node == _root)
                        _root = left_child;
            }
            void                __left_rotate (node_pointer node)
            {
                if (node == NULL)
                    return;

                node_pointer right_child = node->right;

                if (node->parent != NULL)
                {
                    if (node->parent->right == node)
                        node->parent->right = right_child;
                    else
                        node->parent->left = right_child;
                }
                if (right_child)
                {
                    right_child->parent = node->parent;

                    if (right_child->left != NULL)
                        right_child->left->parent = node;
                    node->right = right_child->left;

                    node->parent = right_child;
                    right_child->left = node;
                }
                if (node == _root)
                    _root = right_child;
            }
            void                __balance_tree (const node_pointer node)
            {
                if (node == NULL)
                    return ;

                int depth_node = __get_node_depth_diff(node);
                if (depth_node >= 2)
                {
                    if (__get_node_depth_diff(node->right) == -1)
                        __right_rotate(node->right);
                    __left_rotate(node);
                }
                else if (depth_node <= -2)
                {
                    if (__get_node_depth_diff(node->left) == 1)
                        __left_rotate(node->left);
                    __right_rotate(node);
                }
                __balance_tree(node->parent);
            }
            int                 __get_node_depth (node_pointer node)
            {
                if (node == NULL)
                    return (0);

                int left_depth = __get_node_depth(node->left);
                int right_depth = __get_node_depth(node->right);
                return 1 + ((left_depth > right_depth) ? left_depth : right_depth);
            }
            int                 __get_node_depth_diff (node_pointer node)
            {
                if (node == NULL)
                    return (0);
                return (__get_node_depth(node->right) - __get_node_depth(node->left));
            }

            bool                __compare (const node_pointer & x, const node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            bool                __compare (const node_pointer & x,       node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            bool                __compare (      node_pointer & x, const node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            bool                __compare (      node_pointer & x,       node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            bool                __compare (const node_pointer & x, const value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            bool                __compare (const node_pointer & x,       value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            bool                __compare (      node_pointer & x, const value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            bool                __compare (      node_pointer & x,       value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            bool                __compare (const node_pointer & x, const key_type     & y) const { return (key_compare()(x->value.first, y)); }
            bool                __compare (const node_pointer & x,       key_type     & y) const { return (key_compare()(x->value.first, y)); }
            bool                __compare (      node_pointer & x, const key_type     & y) const { return (key_compare()(x->value.first, y)); }
            bool                __compare (      node_pointer & x,       key_type     & y) const { return (key_compare()(x->value.first, y)); }
            bool                __compare (const value_type   & x, const node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            bool                __compare (const value_type   & x,       node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            bool                __compare (      value_type   & x, const node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            bool                __compare (      value_type   & x,       node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            bool                __compare (const value_type   & x, const value_type   & y) const { return (key_compare()(x.first, y.first)); }
            bool                __compare (const value_type   & x,       value_type   & y) const { return (key_compare()(x.first, y.first)); }
            bool                __compare (      value_type   & x, const value_type   & y) const { return (key_compare()(x.first, y.first)); }
            bool                __compare (      value_type   & x,       value_type   & y) const { return (key_compare()(x.first, y.first)); }
            bool                __compare (const value_type   & x, const key_type     & y) const { return (key_compare()(x.first, y)); }
            bool                __compare (const value_type   & x,       key_type     & y) const { return (key_compare()(x.first, y)); }
            bool                __compare (      value_type   & x, const key_type     & y) const { return (key_compare()(x.first, y)); }
            bool                __compare (      value_type   & x,       key_type     & y) const { return (key_compare()(x.first, y)); }
            bool                __compare (const key_type     & x, const node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            bool                __compare (const key_type     & x,       node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            bool                __compare (      key_type     & x, const node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            bool                __compare (      key_type     & x,       node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            bool                __compare (const key_type     & x, const value_type   & y) const { return (key_compare()(x, y.first)); }
            bool                __compare (const key_type     & x,       value_type   & y) const { return (key_compare()(x, y.first)); }
            bool                __compare (      key_type     & x, const value_type   & y) const { return (key_compare()(x, y.first)); }
            bool                __compare (      key_type     & x,       value_type   & y) const { return (key_compare()(x, y.first)); }
            bool                __compare (const key_type     & x, const key_type     & y) const { return (key_compare()(x, y)); }
            bool                __compare (const key_type     & x,       key_type     & y) const { return (key_compare()(x, y)); }
            bool                __compare (      key_type     & x, const key_type     & y) const { return (key_compare()(x, y)); }
            bool                __compare (      key_type     & x,       key_type     & y) const { return (key_compare()(x, y)); }

        // DEVTOOLS
        private:
            node_pointer        __content_print(const node_pointer & node)
            {
                if (node)
                    std::cout << node->value.first << " ";
                return (NULL);
            }

        public:
            void                infix_content_print(void) // call
            {
                infix_apply(_root, &tree::__content_print);
            }
            void                display(void)
            {
                _dt.tree_draw(_root);
            }
            void                display(std::string fname)
            {
                ft::displaytree<node_type>  __dt(fname);
                __dt.tree_draw(_root);
            }
            void                tree_to_vector(std::vector<node_pointer> & v, node_pointer node)
            {
                if (!node)
                    return ;
                v.push_back(node);
                tree_to_vector(v, node->left);
                tree_to_vector(v, node->right);
            }
            bool                is_tree_legal(void)
            {
                bool islegal = true;
                std::vector<node_pointer> v;
                typename std::vector<node_pointer>::iterator it;
                int     depths[7] = { 0 };

                tree_to_vector(v, _root);
                it = v.begin();
                while (it != v.end())
                {
                    if (search((*it)->value) == NULL)
                    {
                        islegal = false;
                        std::cout << "unreachable node -> " << (*it)->value.first << std::endl;
                    }
                    int d = __get_node_depth_diff(*it);
                         if (d <  -2) depths[0] += 1;
                    else if (d == -2) depths[1] += 1;
                    else if (d == -1) depths[2] += 1;
                    else if (d ==  0) depths[3] += 1;
                    else if (d ==  1) depths[4] += 1;
                    else if (d ==  2) depths[5] += 1;
                    else if (d >   2) depths[6] += 1;
                    it++;
                }
                std::cout << std::string(islegal ? "True" : "False") << std::endl;
                std::cout << "                   ";
                std::cout << "[ <2 ][ -2 ][ -1 ][  0 ][ +1 ][ +2 ][ >2 ]" << std::endl;
                std::cout << "                   ";
                std::cout << "["  << std::setw(4) << depths[0]
                          << "][" << std::setw(4) << depths[1]
                          << "][" << std::setw(4) << depths[2]
                          << "][" << std::setw(4) << depths[3]
                          << "][" << std::setw(4) << depths[4]
                          << "][" << std::setw(4) << depths[5]
                          << "][" << std::setw(4) << depths[6]
                          << "]" << std::endl;
                return (islegal);
            }
    };
}
#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/pair.hpp"
# include "display_tree.hpp"
# include "node.hpp"
# include "tree_iterator.hpp"
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
                class Compare = std::less<K>,
                class ValueAllocator = std::allocator<ft::pair<const K, T> >,
                class NodeAllocator = std::allocator<ft::node<ft::pair<const K, T> > >
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
            typedef ValueAllocator                              allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;

            // COMPARE
            typedef Compare                                     key_compare;

            // ITERATORS
            typedef ft::tree_iterator<value_type>               iterator;
            typedef ft::const_tree_iterator<value_type>         const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                protected:
                    Compare comp;
                public:
                    value_compare (Compare c) : comp(c) {}
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    { return comp(x.first, y.first); }
            };

        /* ***************************************************************** *\
        |                     INNER ATTRIBUTES DEFINITION                     |
        \* ***************************************************************** */
        private:
            // DEVTOOL - display_tree.hpp
            ft::displaytree<node_type>  _dt;

            node_pointer                _end;
            node_pointer                _root;
            size_type                   _size;
            ValueAllocator              _value_allocator;
            NodeAllocator               _node_allocator;

        /* ***************************************************************** *\
        |                      CONSTRUCTOR / DESTRUCTOR                       |
        \* ***************************************************************** */

        public:
            tree(const allocator_type &alloc = allocator_type()) : _end(NULL), _root(NULL), _size(0), _allocator(alloc) {
                _end = __allocate_node(value_type(0,0));
            }
            virtual ~tree() { clear_tree(); }

        /* ***************************************************************** *\
        |                        METHODS DEFINITION                           |
        \* ***************************************************************** */

        /* **************************************** *\
        |                ALLOCATION                  |
        \* **************************************** */

        private:
            inline node_pointer            __allocate_node(const value_type & value, node_pointer parent = NULL)
            {
                node_pointer node = _allocator.allocate(1);
                _allocator.construct(node, node_type(value, parent));
                return (node);

                node_pointer node = _node_allocator.allocate(1);
                _allocator.construct(node, node_type(value, parent));
                return (node);
            }
            inline void                    __deallocate_node(const node_pointer & node)
            {
                if (node != NULL)
                    _allocator.deallocate(node, sizeof(node_type));
            }

        /* **************************************** *\
        |                 ITERATOR                   |
        \* **************************************** */
        public:
            inline iterator                begin ()
            {
                if (size() == 0)
                    return (end());
                return (iterator(minimum(_root)));
            };
            inline const_iterator          begin () const
            {
                if (size() == 0)
                    return (end());
                return (const_iterator(minimum(_root)));
            };
            inline iterator                end ()
            {
                return (iterator(_end));
            };
            inline const_iterator          end () const
            {
                return (const_iterator(_end));
            };
            inline reverse_iterator        rbegin ()
            {
                return (reverse_iterator(_end));
            };
            inline const_reverse_iterator  rbegin () const
            {
                return (const_reverse_iterator(_end));
            };
            inline reverse_iterator        rend ()
            {
                return (reverse_iterator(begin()));
            };
            inline const_reverse_iterator  rend () const
            {
                return (const_reverse_iterator(begin()));
            };

        /* **************************************** *\
        |                 CAPACITY                   |
        \* **************************************** */
        public:
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

        /* **************************************** *\
        |                 INSERTING                  |
        \* **************************************** */
        public:
            template <class InputIterator>
            void                insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    ++first;
                }
            };
            node_pointer        insert(const node_pointer & node)
            {
                // printf(C_G_ORANGE "insert (node=%p)\n" C_RES, node);
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
                update_end();
                return (node);
            }
            node_pointer        insert(const value_type & value)
            {
                // printf(C_G_GREEN "insert (value)\n" C_RES);
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
                // printf(C_G_GREEN "insert (key=%d, val=%d)\n" C_RES, key, value);
                return (insert(value_type(key, value)));
            }

        /* **************************************** *\
        |                 DELETING                   |
        \* **************************************** */
        public:
            void                remove(iterator first, iterator last)
            {
                while (first != last)
                {
                    remove(first++);
                }
            };
            node_pointer        remove(node_pointer & node)
            {
                // std::cout << __FUNCTION__ << "(root:" << _root << ")" << std::endl;
                if (node == NULL)
                    return (NULL);
                // display_node_links(node, "node");
                if (node->right && node->left)
                    detach_node_with_two_child(node);
                else
                    detach_node_with_one_or_no_child(node);

                _size -= 1;
                std::cout << GREEN_TREE << "DELETE NODE " << C_G_PINK << node << LIGHT_BLUE << "(" << node->value.first << ")" << C_RES << C_RES << std::endl;
                __deallocate_node(node);
                update_end();
                return (NULL);
            }
            node_pointer        remove(value_type & value)
            {
                node_pointer tmp = search(value);
                // TTEST("remove value {k:%d, v:%d}", value.first, value.second);
                return (remove(tmp));
            }
            node_pointer        remove(key_type & key)
            {
                node_pointer tmp = search(key);
                // TTEST("remove key %d", key);
                return (remove(tmp));
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

        /* **************************************** *\
        |                 ACCESSORS                  |
        \* **************************************** */
        public:
            mapped_type&        operator[] (const key_type& k)
            {
                node_pointer node = search(k);
                if (node != NULL)
                    return (node->value.second);
                ft::pair<iterator,bool> insert_ret = insert(ft::make_pair(k, mapped_type()));
                return ((*insert_ret.first).second);
            };

            size_type           count (const key_type& k) const
            {
                const_iterator it = search(k);
                return (it != _end);
            };
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

        /* **************************************** *\
        |                INNER TOOLS                 |
        \* **************************************** */
        private:
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
            node_pointer        detach_node_from_parent(node_pointer node)
            {
                if (node->parent)
                {
                    if (node->parent == _end)
                        return (NULL);
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
                    if (node->parent == _end)
                        return (NULL);
                    if (node->parent->left == node)
                        return (&node->parent->left);
                    else
                        return (&node->parent->right);
                }
                else
                    return (NULL);
            }
            node_pointer        find_kandida(node_pointer & node)
            {
                if (node == NULL)
                    return (NULL);

                node_pointer kandida;

                // on commence par calculer la depth de la node
                int depth = __get_node_depth(node);

                // deux cas: si la depth est negative on cherche le precedent le plus proche
                // sinon le suivant le plus proche
                if (depth < 0)
                    kandida = prev_value(node);
                else
                    kandida = next_value(node);
                return (kandida);
            }
            node_pointer        detach_node_with_two_child(node_pointer & node)
            {
                // std::cout << __FUNCTION__ << "()" << std::endl;
                if (node == NULL)
                    return (NULL);
                                                                                                // display_node_links(node, "node");
                // std::cout << "finding kandida" << std::endl;
                node_pointer kandida = find_kandida(node);
                                                                                                // display_node_links(kandida, "kandida");
                if (kandida->left && kandida->right) // kandida is not a leave
                    detach_node_with_two_child(kandida);
                else
                    detach_node_with_one_or_no_child(kandida); // detach and unlink kandida
                // std::cout << "swap node and kandida" << std::endl;
                swap(node, kandida);
                                                                                                // display_node_links(node, "node");
                                                                                                // display_node_links(kandida, "kandida");
                if (kandida->left && kandida->right) // kandida is not a leave

                // std::cout << "unlink node" << std::endl;
                unlink_node(node);
                                                                                                // display_node_links(node, "node");
                if (_root == node)
                    _root = kandida;
                                                                                                // display_node_links(_root, "_root");
                return (kandida);
            }
            node_pointer        detach_node_with_one_or_no_child(node_pointer & node)
            {
                // std::cout << __FUNCTION__ << "()" << std::endl;
                if (node == NULL)
                    return (NULL);
                // display_node_links(node, "node");

                if (node->left == NULL && node->right == NULL) {
                    // TTEST("feuille")
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
                    // TTEST("only left child")
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
                        // TTEST("root")
                        _root = node->left;
                        _root->parent = NULL;
                    }
                    else
                    {
                        // TTEST("no root")
                        node->left->parent = node->parent;
                       *tmp = node->left;
                    }
                }
                else if (node->right && !node->left) {
                    // TTEST("only right child")
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
                unlink_node(node);
                return (node);
            }

            void                _pswap(node_pointer *a, node_pointer *b)
            {
                node_pointer tmp = *a;
                *a = *b;
                *b = tmp;
            }
            void                swap(node_pointer a, node_pointer b)
            {
                // display_node_links(a, "a");
                // display_node_links(b, "b");
                // swap parents endpoint
                node_pointer *ap = get_parent_endpoint(a);
                node_pointer *bp = get_parent_endpoint(b);

                if (ap) *ap = b;
                if (bp) *bp = a;

                // _pswap(ap, bp);

                // swap children endpoint
                if (a->left)  a->left->parent = b;
                if (a->right) a->right->parent = b;
                if (b->left)  b->left->parent = a;
                if (b->right) b->right->parent = a;

                // swap inner links
                _pswap(&a->parent, &b->parent);
                _pswap(&a->left, &b->left);
                _pswap(&a->right, &b->right);
            }
            void                update_end(void)
            {
                std::cout << _root << std::endl;
                if (_root)
                {
                    if (_end)
                    {
                        _end->left = _root;
                        _end->right = _root;
                    }
                    _root->parent = _end;
                }
            }

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
                if (node == NULL || node == _end)
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
            inline void         unlink_node(node_pointer node)
            {
                node->left = NULL;
                node->right = NULL;
                node->parent = NULL;
            }

        /* **************************************** *\
        |               KEY COMPARE                  |
        \* **************************************** */
        private:
            inline bool __compare (const node_pointer & x, const node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            inline bool __compare (const node_pointer & x,       node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            inline bool __compare (      node_pointer & x, const node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            inline bool __compare (      node_pointer & x,       node_pointer & y) const { return (key_compare()(x->value.first, y->value.first)); }
            inline bool __compare (const node_pointer & x, const value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            inline bool __compare (const node_pointer & x,       value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            inline bool __compare (      node_pointer & x, const value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            inline bool __compare (      node_pointer & x,       value_type   & y) const { return (key_compare()(x->value.first, y.first)); }
            inline bool __compare (const node_pointer & x, const key_type     & y) const { return (key_compare()(x->value.first, y)); }
            inline bool __compare (const node_pointer & x,       key_type     & y) const { return (key_compare()(x->value.first, y)); }
            inline bool __compare (      node_pointer & x, const key_type     & y) const { return (key_compare()(x->value.first, y)); }
            inline bool __compare (      node_pointer & x,       key_type     & y) const { return (key_compare()(x->value.first, y)); }
            inline bool __compare (const value_type   & x, const node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            inline bool __compare (const value_type   & x,       node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            inline bool __compare (      value_type   & x, const node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            inline bool __compare (      value_type   & x,       node_pointer & y) const { return (key_compare()(x.first, y->value.first)); }
            inline bool __compare (const value_type   & x, const value_type   & y) const { return (key_compare()(x.first, y.first)); }
            inline bool __compare (const value_type   & x,       value_type   & y) const { return (key_compare()(x.first, y.first)); }
            inline bool __compare (      value_type   & x, const value_type   & y) const { return (key_compare()(x.first, y.first)); }
            inline bool __compare (      value_type   & x,       value_type   & y) const { return (key_compare()(x.first, y.first)); }
            inline bool __compare (const value_type   & x, const key_type     & y) const { return (key_compare()(x.first, y)); }
            inline bool __compare (const value_type   & x,       key_type     & y) const { return (key_compare()(x.first, y)); }
            inline bool __compare (      value_type   & x, const key_type     & y) const { return (key_compare()(x.first, y)); }
            inline bool __compare (      value_type   & x,       key_type     & y) const { return (key_compare()(x.first, y)); }
            inline bool __compare (const key_type     & x, const node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            inline bool __compare (const key_type     & x,       node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            inline bool __compare (      key_type     & x, const node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            inline bool __compare (      key_type     & x,       node_pointer & y) const { return (key_compare()(x, y->value.first)); }
            inline bool __compare (const key_type     & x, const value_type   & y) const { return (key_compare()(x, y.first)); }
            inline bool __compare (const key_type     & x,       value_type   & y) const { return (key_compare()(x, y.first)); }
            inline bool __compare (      key_type     & x, const value_type   & y) const { return (key_compare()(x, y.first)); }
            inline bool __compare (      key_type     & x,       value_type   & y) const { return (key_compare()(x, y.first)); }
            inline bool __compare (const key_type     & x, const key_type     & y) const { return (key_compare()(x, y)); }
            inline bool __compare (const key_type     & x,       key_type     & y) const { return (key_compare()(x, y)); }
            inline bool __compare (      key_type     & x, const key_type     & y) const { return (key_compare()(x, y)); }
            inline bool __compare (      key_type     & x,       key_type     & y) const { return (key_compare()(x, y)); }

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
            bool                is_tree_legal(bool verboze = true)
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
                if (this->size() != v.size())
                    islegal = false;
                if (verboze == true)
                {
                    std::cout << std::string(islegal ? "True" : "False") << " [ " << v.size() << " ]" << std::endl;
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
                }
                return (islegal);
            }
            void                display_node_links(node_pointer node, std::string nname)
            {
                std::cout << "> " << nname << "         : " << node << LIGHT_BLUE << "(" << node->value.first << ")" << C_RES << std::endl;
                std::cout << "> " << nname << " parent  : " << node->parent;  if (node->parent)  std::cout << LIGHT_BLUE << "(" << node->parent->value.first << ")" << C_RES; std::cout << std::endl;
                std::cout << "> " << nname << " left    : " << node->left;  if (node->left)  std::cout << LIGHT_BLUE << "(" << node->left->value.first << ")" << C_RES; std::cout << std::endl;
                std::cout << "> " << nname << " right   : " << node->right; if (node->right) std::cout << LIGHT_BLUE << "(" << node->right->value.first << ")" << C_RES; std::cout << std::endl;
            }
    };
}

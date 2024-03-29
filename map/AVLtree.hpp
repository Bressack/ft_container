#pragma once

# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/pair.hpp"
# include "../others/reverse_iterator.hpp"
# include "node.hpp"
# include "tree_iterator.hpp"
# include <iostream>
// # include <vector>
# include <memory>
# include <functional>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

// # define DEBUG printf("\033[37;01m%s:%d:0: \033[36;01mdebug: \033[37;01m  \033[0m\n", (char *)__FILE__, (int)__LINE__);
// # define TTEST(...) {char *debugs;asprintf(&debugs, __VA_ARGS__);std::cout << _TEST_ << "  " << debugs << std::endl;free(debugs);}

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
                class Allocator = std::allocator<ft::pair<const K, T> >
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
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;

            typedef typename allocator_type::template rebind<node_type>::other	node_alloc_type;

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
            node_pointer                _end;
            node_pointer                _root;
            size_type                   _size;
            node_alloc_type             _allocator;

        /* ***************************************************************** *\
        |                      CONSTRUCTOR / DESTRUCTOR                       |
        \* ***************************************************************** */

        public:
            tree(const allocator_type &alloc = allocator_type())
            : _end(NULL), _root(NULL), _size(0), _allocator(alloc)
            {
                _end = _allocator.allocate(1);
                _end->parent = NULL;
                update_end();
            }
            tree(const tree &x, const allocator_type &alloc = allocator_type())
            : _end(NULL), _root(NULL), _size(0), _allocator(alloc)
            {
                _end = _allocator.allocate(1);
                _end->parent = NULL;

                insert(x.begin(), x.end());
                update_end();
            }
            virtual ~tree()
            {
                clear_tree();
                __deallocate_node(_end);
            }
            tree& operator=(const tree &x)
            {
                if (this != &x)
                {
                    clear_tree();
                    _root = NULL;
                    if (x.empty() == false)
                        insert(x.begin(), x.end());
                    update_end();
                }
                return(*this);
            };

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
            node_pointer    minimum(node_pointer node) const
            {
                if (node == NULL)
                    return (node);
                while (node->left != NULL)
                    node = node->left;
                return (node);
            };
            node_pointer    maximum(node_pointer node) const
            {
                if (node == NULL)
                    return (node);
                while (node->right != NULL)
                    node = node->right;
                return (node);
            };
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
            inline bool         empty(void) const
            {
                return (_size == 0);
            }
            inline size_type    size(void) const
            {
                return (_size);
            }
            inline size_type    max_size(void) const
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
                    insert(*(first++));
            };

            ft::pair<iterator, bool> insert(const value_type &val) // single element
            {
                node_pointer tmp = search(val);
                if (tmp == NULL)
                    return (ft::make_pair(__insert(val), true));
                return (ft::make_pair(tmp, false));
            };

            iterator insert(iterator position, const value_type &val) // with hint
            {
                (void)position;
                return (iterator(__insert(val)));
            };

            node_pointer        __insert(const node_pointer & node)
            {
                if (empty() == true) // tree is empty
                    _root = node;
                else // tree is not empty
                {
                    if (_root)
                        _root->parent = NULL; // detach _end
                    future_parent parent = __find_future_parent(node);
                    node->parent = parent.first;
                    *parent.second = node;
                    __balance_tree(node);
                }
                _size += 1;
                update_end();
                return (node);
            }
            node_pointer        __insert(const value_type & value)
            {
                node_pointer tmp = search(value);
                if (tmp != NULL)
                    return (tmp);
                node_pointer n = __allocate_node(value);
                return (__insert(n));
            }

        /* **************************************** *\
        |                 DELETING                   |
        \* **************************************** */
        public:
            void                remove(iterator first, iterator last)
            {
                while (first != last)
                    remove(*(first++));
            };
            size_type        remove(node_pointer & node)
            {
                if (node == NULL || node == _end)
                    return (0);
                _root->parent = NULL; // detach _end
                if (node->right && node->left)
                    detach_node_with_two_child(node);
                else
                    detach_node_with_one_or_no_child(node);

                _size -= 1;
                __deallocate_node(node);
                update_end();
                return (1);
            }
            size_type        remove(const value_type & value)
            {
                node_pointer tmp = search(value);
                return (remove(tmp));
            }
            size_type        remove(const key_type & key)
            {
                node_pointer tmp = search(key);
                return (remove(tmp));
            }

            void                clear_node(node_pointer & node)
            {
                if (node == NULL || node == _end)
                    return ;
                if (node->left)
                    clear_node(node->left);
                if (node->right)
                    clear_node(node->right);
                __deallocate_node(node);
                _size -= 1;
                node = NULL;
            }
            void                clear_tree(void)
            {
                if (empty() == false)
                {
                    _root->parent = NULL;
                    clear_node(_root);
                    _root = NULL;
                    _size = 0;
                }
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
                const_iterator ite = end();

                if (it == NULL)
                    return (0);
                return (it != ite);
            };
            iterator lower_bound (const key_type& k) // 1st not to go before
            {
                iterator  it = begin();
                iterator  it_end = end();

                for (; it != it_end; it++)
                {
                    if (key_comp()(it->first, k) == false)
                        return (it);
                }
                return (it);
            };

            const_iterator lower_bound (const key_type& k) const
            {
                const_iterator  it = begin();
                const_iterator  it_end = end();

                for (; it != it_end; it++)
                {
                    if (key_comp()(it->first, k) == false)
                        return (it);
                }
                return (it);
            };

            iterator upper_bound (const key_type& k) // 1st to go after
            {
                iterator  it = begin();
                iterator  it_end = end();

                for (; it != it_end; it++)
                {
                    if (key_comp()(k, it->first) == true)
                        return (it);
                }
                return (it);
            };

            const_iterator upper_bound (const key_type& k) const
            {
                const_iterator  it = begin();
                const_iterator  it_end = end();

                for (; it != it_end; it++)
                {
                    if (key_comp()(k, it->first) == true)
                        return (it);
                }
                return (it);
            };

            key_compare key_comp() const
            {
                return (key_compare());
            };
            value_compare value_comp() const
            {
                return (value_compare(key_compare()));
            };
            ft::pair<iterator,iterator> equal_range (const key_type& k) // in between
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            };

            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            };

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
            void                swap (tree& x)
            {
                if (this == &x)
                    return;
                ft::ft_swap(_end, x._end);
                ft::ft_swap(_root, x._root);
                ft::ft_swap(_size, x._size);
            }
            void                swap(node_pointer a, node_pointer b)
            {
                node_pointer *ap = get_parent_endpoint(a);
                node_pointer *bp = get_parent_endpoint(b);

                if (ap) *ap = b;
                if (bp) *bp = a;

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
            void                swap(size_type s1, size_type s2)
            {
                size_type tmp = s1;
                s1 = s2;
                s2 = tmp;
            }

        /* **************************************** *\
        |                INNER TOOLS                 |
        \* **************************************** */
        private:
            void                infix_apply(const node_pointer node, node_pointer(tree::*f)(const node_pointer &))
            {
                if (node == NULL || node == _end)
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
                if (node == NULL)
                    return (NULL);
                node_pointer kandida = find_kandida(node);
                if (kandida->left && kandida->right) // kandida is not a leave
                    detach_node_with_two_child(kandida);
                else
                    detach_node_with_one_or_no_child(kandida); // detach and unlink kandida
                swap(node, kandida);
                if (kandida->left && kandida->right) // kandida is not a leave

                unlink_node(node);
                if (_root == node)
                    _root = kandida;
                return (kandida);
            }
            node_pointer        detach_node_with_one_or_no_child(node_pointer & node)
            {
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
            void                update_end(void)
            {
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
                if (node == NULL || node == _end)
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

    };
}

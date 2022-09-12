#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <iostream>
#include "node.hpp"
#include "../others/iterator_traits.hpp"
#include "../others/color.hpp"

namespace ft
{
        template <typename T>
        class const_tree_iterator;

        template <typename T>
        class tree_iterator : public std::bidirectional_iterator_tag
        {
            protected:
                typedef ft::node<T>*                                        node_pointer;
                typedef iterator_core<std::bidirectional_iterator_tag, T>   iterator_type;

                node_pointer _node;

            public:

                typedef    typename iterator_traits<iterator_type>::value_type      value_type;
                typedef    typename iterator_traits<iterator_type>::difference_type difference_type;
                typedef    typename iterator_traits<iterator_type>::pointer         pointer;
                typedef    typename iterator_traits<iterator_type>::reference       reference;
                typedef    std::bidirectional_iterator_tag                          iterator_category;

                tree_iterator() : _node(NULL) {};
                tree_iterator(const tree_iterator &it) : _node(it.base()) {};
                tree_iterator(node_pointer node) : _node(node) {};
                virtual ~tree_iterator() {};
                tree_iterator& operator=(const tree_iterator& it)
                {
                    if (this != &it)
                        _node = it._node;
                    return (*this);
                };

            protected:

                node_pointer    minimum(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    while (node->left != NULL)
                        node = node->left;
                    return (node);
                };

                node_pointer    maximum(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    while (node->right != NULL)
                        node = node->right;
                    return (node);
                };

                node_pointer    next(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    if (node->right)
                    {
                        node = minimum(node->right);
                        return (node);
                    }
                    while (node->parent && node->parent->left != node)
                        node = node->parent;
                    if (node->parent) // _end is _root->parent
                        node = node->parent;
                    return (node);
                }

                node_pointer    prev(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    if (node->left)
                    {
                        node = maximum(node->left);
                        return (node);
                    }
                    while (node->parent && node->parent->right != node)
                        node = node->parent;
                    if (node->parent) // _end is _root->parent
                        node = node->parent;
                    return (node);
                }

            public:

                node_pointer    base() const { return (_node); };

                tree_iterator&  operator++  ()           { _node = next(_node); return (*this); }
                tree_iterator   operator++  (int)        { tree_iterator    tmp = (*this); ++(*this); return (tmp); };
                tree_iterator&  operator--  ()           { _node = prev(_node); return (*this); }
                tree_iterator   operator--  (int)        { tree_iterator    tmp = (*this); --(*this); return (tmp); };
                reference       operator*   ()     const { return (_node->value); };
                pointer         operator->  ()     const { return (&(_node->value)); };

                bool            operator==  (const tree_iterator& lhs)          const { return (_node == lhs.base()); };
                bool            operator==  (const const_tree_iterator<T>& lhs) const { return (_node == lhs.base()); };
                bool            operator!=  (const tree_iterator& lhs)          const { return !(_node == lhs.base()); };
                bool            operator!=  (const const_tree_iterator<T>& lhs) const { return !(_node == lhs.base()); };

        }; //tree_iterator

        template <typename T>
        class const_tree_iterator : public std::bidirectional_iterator_tag
        {
            protected:
                typedef    ft::node<T>*                                                node_pointer;
                typedef iterator_core<std::bidirectional_iterator_tag, const T>    iterator_type;

                node_pointer                                                           _node;

            public:

                typedef    typename iterator_traits<iterator_type>::value_type         value_type;
                typedef    typename iterator_traits<iterator_type>::difference_type    difference_type;
                typedef    typename iterator_traits<iterator_type>::pointer            pointer;
                typedef    typename iterator_traits<iterator_type>::reference          reference;
                typedef    std::bidirectional_iterator_tag                             iterator_category;

                const_tree_iterator() : _node(NULL)
                {};
                const_tree_iterator(const const_tree_iterator<T> &it) : _node(it.base())
                {};
                const_tree_iterator(const tree_iterator<T> &it) : _node(it.base()) // const_iterator conversion fix
                {};
                const_tree_iterator(node_pointer node) : _node(node)
                {};
                virtual ~const_tree_iterator()
                {};
                const_tree_iterator& operator=(const const_tree_iterator& it)
                {
                    if (this != &it)
                        _node = it._node;
                    return (*this);
                };

            protected:

                node_pointer    minimum(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    while (node->left != NULL)
                        node = node->left;
                    return (node);
                };

                node_pointer    maximum(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    while (node->right != NULL)
                        node = node->right;
                    return (node);
                };

                node_pointer    next(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    if (node->right)
                    {
                        node = minimum(node->right);
                        return (node);
                    }
                    while (node->parent && node->parent->left != node)
                        node = node->parent;
                    if (node->parent) // _end is _root->parent
                        node = node->parent;
                    return (node);
                }

                node_pointer    prev(node_pointer node)
                {
                    if (node == NULL)
                        return (node);
                    if (node->left)
                    {
                        node = maximum(node->left);
                        return (node);
                    }
                    while (node->parent && node->parent->right != node)
                        node = node->parent;
                    if (node->parent)
                        node = node->parent;
                    return (node);
                }

            public:

                node_pointer        base() const { return (_node); };

                const_tree_iterator&        operator++()
                {
                    _node = next(_node);
                    return (*this);
                }

                const_tree_iterator&        operator--()
                {
                    _node = prev(_node);
                    return (*this);
                }

                const_tree_iterator     operator++  (int)       { const_tree_iterator    tmp = (*this); ++(*this); return (tmp); };
                const_tree_iterator     operator--  (int)       { const_tree_iterator    tmp = (*this); --(*this); return (tmp); };
                reference               operator*   ()    const { return (_node->value); };
                pointer                 operator->  ()    const { return (&(_node->value)); };

                bool                    operator==  (const_tree_iterator& lhs)    const  { return (_node == lhs.base()); };
                bool                    operator==  (const tree_iterator<T>& lhs) const  { return (_node == lhs.base()); };
                bool                    operator!=  (const_tree_iterator& lhs)    const  { return !(_node == lhs.base()); };
                bool                    operator!=  (const tree_iterator<T>& lhs) const  { return !(_node == lhs.base()); };

        }; //const_tree_iterator
}
#endif

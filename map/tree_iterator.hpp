#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iostream>
# include "node.hpp"
# include "../others/iterator_traits.hpp"
# include "../others/iterator.hpp"
# include "../others/reverse_iterator.hpp"

# include "../others/color.hpp"

namespace ft
{
    template <typename T>
    class const_tree_iterator;

    template <typename T>
    class tree_iterator : public std::bidirectional_iterator_tag
    {
        protected:
            typedef ft::node<T>  *node_pointer;
            typedef iterator_core<std::bidirectional_iterator_tag, T>  iterator_type;

            node_pointer _node;

        public:
            typedef typename iterator_traits<iterator_type>::value_type         value_type;
            typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
            typedef typename iterator_traits<iterator_type>::pointer            pointer;
            typedef typename iterator_traits<iterator_type>::reference          reference;
            typedef std::bidirectional_iterator_tag                             iterator_category;

            inline tree_iterator() : _node(NULL) {};
            inline tree_iterator(const tree_iterator &it) : _node(it.base()) {};
            inline tree_iterator(node_pointer node) : _node(node) {};
            inline virtual ~tree_iterator() {};
            tree_iterator &operator=(const tree_iterator &it)
            {
                if (this != &it)
                    _node = it._node;
                return (*this);
            };

        protected:
            node_pointer minimum(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                while (node->left != NULL)
                    node = node->left;
                return (node);
            };

            node_pointer maximum(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                while (node->right != NULL)
                    node = node->right;
                return (node);
            };

            node_pointer next(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                if (node->right)
                {
                    node = minimum(node->right);
                    return (node);
                }
                while (node->_parent && node->_parent->left != node)
                    node = node->_parent;
                if (node->_parent) // _end is _root->_parent
                    node = node->_parent;
                return (node);
            }

            node_pointer prev(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                if (node->left)
                {
                    node = maximum(node->left);
                    return (node);
                }
                while (node->_parent && node->_parent->right != node)
                    node = node->_parent;
                if (node->_parent)
                    node = node->_parent;
                return (node);
            }

        public:
            node_pointer base() const { return (_node); };

            tree_iterator &operator++()
            {
                _node = next(_node);
                return (*this);
            }
            tree_iterator operator++(int)
            {
                tree_iterator tmp = (*this);
                ++(*this);
                return (tmp);
            };
            tree_iterator &operator--()
            {
                _node = prev(_node);
                return (*this);
            }
            tree_iterator operator--(int)
            {
                tree_iterator tmp = (*this);
                --(*this);
                return (tmp);
            };
            reference operator*() const { return (_node->_value); };
            pointer operator->() const { return (&(_node->_value)); };
            bool operator==(const tree_iterator &lhs) { return (_node == lhs.base()); };
            bool operator==(const const_tree_iterator<T> &lhs) { return (_node == lhs.base()); };
            bool operator!=(const tree_iterator &lhs) { return (_node != lhs.base()); };
            bool operator!=(const const_tree_iterator<T> &lhs) { return (_node != lhs.base()); };

    }; // tree_iterator

    template <typename T>
    class const_tree_iterator : public std::bidirectional_iterator_tag
    {
        protected:
            typedef ft::node<T> *node_pointer;
            typedef iterator<const T> iterator_type;

            node_pointer _node;

        public:
            typedef typename iterator_traits<iterator_type>::value_type         value_type;
            typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
            typedef typename iterator_traits<iterator_type>::pointer            pointer;
            typedef typename iterator_traits<iterator_type>::reference          reference;
            typedef std::bidirectional_iterator_tag                             iterator_category;

            const_tree_iterator() : _node(NULL) {};
            const_tree_iterator(const const_tree_iterator<T> &it) : _node(it.base()) {};
            const_tree_iterator(const tree_iterator<T> &it) : _node(it.base()) {};
            const_tree_iterator(node_pointer node) : _node(node) {};
            virtual ~const_tree_iterator() {};
            const_tree_iterator &operator=(const const_tree_iterator &it)
            {
                if (this != &it)
                    _node = it._node;
                return (*this);
            };

        protected:
            node_pointer minimum(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                while (node->left != NULL)
                    node = node->left;
                return (node);
            };

            node_pointer maximum(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                while (node->right != NULL)
                    node = node->right;
                return (node);
            };

            node_pointer next(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                if (node->right)
                {
                    node = minimum(node->right);
                    return (node);
                }
                while (node->_parent && node->_parent->left != node)
                    node = node->_parent;
                if (node->_parent) // _end is _root->_parent
                    node = node->_parent;
                return (node);
            }

            node_pointer prev(node_pointer node)
            {
                if (node == NULL)
                    return (node);
                if (node->left)
                {
                    node = maximum(node->left);
                    return (node);
                }
                while (node->_parent && node->_parent->right != node)
                    node = node->_parent;
                if (node->_parent)
                    node = node->_parent;
                return (node);
            }

        public:
            node_pointer base() const { return (_node); };

            const_tree_iterator &operator++()
            {
                _node = next(_node);
                return (*this);
            }
            const_tree_iterator operator++(int)
            {
                const_tree_iterator tmp = (*this);
                ++(*this);
                return (tmp);
            };
            const_tree_iterator &operator--()
            {
                _node = prev(_node);
                return (*this);
            }
            const_tree_iterator operator--(int)
            {
                const_tree_iterator tmp = (*this);
                --(*this);
                return (tmp);
            };
            reference operator*() const { return (_node->_value); };
            pointer operator->() const { return (&(_node->_value)); };
            bool operator==(const_tree_iterator &lhs) { return (_node == lhs.base()); };
            bool operator!=(const_tree_iterator &lhs) { return (_node != lhs.base()); };
            bool operator==(const tree_iterator<T> &lhs) { return (_node == lhs.base()); };
            bool operator!=(const tree_iterator<T> &lhs) { return (_node != lhs.base()); };

    }; // const_tree_iterator

}
#endif

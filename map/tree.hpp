#pragma once

# include <deque>
# include <vector>
# include <cstddef>
# include <stdexcept>
# include <ostream>
# include <iostream>
# include "../others/pair.hpp"

namespace ft
{
    template < class K, class V, class Alloc = std::allocator<ft::pair<K,V> > >
    class tree
    {
        public:
        /// Member types
            typedef K                                               key_type;               // The type of keys
            typedef V                                               value_type;             // The type of values
            typedef Alloc                                           allocator_type;         // The second template parameter (Alloc)	defaults to: allocator<value_type>
            typedef typename Alloc::reference                       reference;              // allocator_type::reference	for the default allocator: value_type&
            typedef typename Alloc::const_reference                 const_reference;        // allocator_type::const_reference	for the default allocator: const value_type&
            typedef typename Alloc::pointer                         pointer;                // allocator_type::pointer	for the default allocator: value_type*
            typedef typename Alloc::const_pointer                   const_pointer;          // allocator_type::const_pointer	for the default allocator: const value_type*

            typedef typename ft::iterator<pointer>                  iterator;               // a random access iterator to value_type	convertible to const_iterator
            typedef typename ft::iterator<const_pointer>            const_iterator;         // a random access iterator to const value_type
            typedef typename ft::reverse_iterator<iterator>         reverse_iterator;       // reverse_iterator<iterator>
            typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator; // reverse_iterator<const_iterator>

            typedef ptrdiff_t                                       difference_type;        // a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
            typedef size_t                                          size_type;              // an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

        private:
            typedef struct  s_node
            {
                ft::pair<>
                pointer     parent;
                pointer     right;
                pointer     left;
            }               node;
            Alloc           _allocator;
            size_type       _size;
            pointer         _root;

        public:
    };
}

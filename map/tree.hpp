#pragma once

# include <deque>
# include <vector>
# include <cstddef>
# include <stdexcept>
# include <ostream>
# include <iostream>
# include "../others/pair.hpp"
# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/iterator_traits.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/enable_if.hpp"
# include "../others/iterator.hpp"
# include "../others/is_integral.hpp"


namespace ft
{
    struct node;

    template < class K, class V, class Alloc = std::allocator<struct node> >
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
            struct node
            {
                ft::pair<K,V>   pair;   // pair of key value
                pointer         parent; // pointer to a node
                pointer         right;  // pointer to a node
                pointer         left;   // pointer to a node
            };
            Alloc               _allocator;
            size_type           _size;
            pointer             _root;

        public:
            tree();
            ~tree();

            void    empty() { return (!_root); };
            void    size() { return (_size); };
            void    max_size() { return (_allocator.max_size()); };
            
            void    push(K key, V value)
            {
                ft::pair<K,V> pair(key, value);
                push(pair);
            }
            void    push(ft::pair<K,V> pair)
            {
                if (!_root)
                    _root = 
            }
            node    new_node(ft::pair<K,V> pair)
            {
                node n;

                n
            }
            void    find();
            void    remove();
            void    swap() {  };
            void    clear();



    };
}

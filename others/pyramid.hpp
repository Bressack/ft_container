#pragma once

# include <cstddef>
# include <stdexcept>
# include <ostream>
# include <iostream>
# include <vector>

# include "color.hpp"
# include "utils.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "iterator.hpp"
# include "is_integral.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class hard_static_vector
    {
        public:
            typedef T                                               value_type;             // The first template parameter (T)
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
            typedef size_t                                          size_type;

        private:
            const Alloc     _allocator;
            size_type       _size;
            const size_type _capacity;
            const pointer   _array_ptr;

        public:
            hard_static_vector(size_type capacity, const allocator_type &alloc = allocator_type())
            : _allocator(alloc), _capacity(capacity), _size(0) {
                _array_ptr = _allocator.allocate(_capacity);
            }
            ~hard_static_vector() {
                _allocator.deallocate(_array_ptr, _capacity);
            }

            // Iterators
            iterator begin() { return (iterator(&(front()))); };
            const_iterator begin() const { return (const_iterator(&(front()))); };
            iterator end() { return (iterator(&(back()) + 1)); };
            const_iterator end() const { return (const_iterator(&(back()) + 1)); };

            reverse_iterator rbegin() { return (reverse_iterator(end())); };
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };
            reverse_iterator rend() { return (reverse_iterator(begin())); };
            const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); };

            // Capacity
            size_type size() const { return(_size); };
            size_type max_size() const { return (_allocator.max_size()); };
            size_type capacity() const { return(_capacity); };
            size_type vacant() const { return (_capacity - _size); };
            bool empty() const { return(!_size ? true : false); };
            bool full() const { return (_size == _capacity); };

            // Element access
            reference front() { return (*_array_ptr); };
            const_reference front() const { return (*_array_ptr); };
            reference back() { return (_array_ptr[_size - 1]); };
            const_reference back() const { return (_array_ptr[_size - 1]); };
            reference operator[](size_type n) { return *(_array_ptr + n); };
            const_reference operator[](size_type n) const { return *(_array_ptr + n); };
            reference at(size_type n)
            {
                if (n >= size())
                    throw std::out_of_range("out_of_range - vector 'at'");
                return (_array_ptr[n]);
            };
            const_reference at(size_type n) const
            {
                if (n >= size())
                    throw std::out_of_range("out_of_range - vector 'at'");
                return (_array_ptr[n]);
            };
            
            // Modifiers
            bool push_back(const value_type& val) {
                if (_size >= _capacity)
                    return false;
                _size++;
                _allocator.construct(&(_array_ptr[_size - 1]), val);
                return true;
            };
            void pop_back() {
                erase(end() - 1);
            };
    }

     //////              //////      //////          //////              //////      //////  //////                  //////
    //..//      //////  //..//////  //..//  //////  //..//      //////  //..//  //////..//  //..//      //////      //..//
   //..//////  //..//////......//  //..//////..//////..//////  //..//////..//////......//////..//  //////..//////  //..//
  //......//////..............//////......................//////..............................//////..........//////..//
 //..................................................................................................................//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <  class T,
                typename hsv = hard_static_vector<T>,
                typename Container = std::vector<hsv>,
                typename Alloc = std::allocator<T>
    > class pyramid
    {
        public:
            typedef T                               value_type;
            typedef Alloc                           allocator_type;
            typedef typename Container              container_type;
            typedef typename Container::iterator    container_iterator;
            typedef ptrdiff_t                       difference_type;
            typedef size_t                          size_type;

            typedef typename Alloc::reference                       reference;              // allocator_type::reference	for the default allocator: value_type&
            typedef typename Alloc::const_reference                 const_reference;        // allocator_type::const_reference	for the default allocator: const value_type&
            typedef typename Alloc::pointer                         pointer;                // allocator_type::pointer	for the default allocator: value_type*
            typedef typename Alloc::const_pointer                   const_pointer;          // allocator_type::const_pointer	for the default allocator: const value_type*

            typedef typename ft::iterator<pointer>                  iterator;               // a random access iterator to value_type	convertible to const_iterator
            typedef typename ft::iterator<const_pointer>            const_iterator;         // a random access iterator to const value_type
            typedef typename ft::reverse_iterator<iterator>         reverse_iterator;       // reverse_iterator<iterator>
            typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator; // reverse_iterator<const_iterator>


        private:
            container_type    _array_ptr();

        public:
            pyramid() {}
            ~pyramid() {}

            // Iterators
            iterator begin() { return (iterator(&(front()))); };
            const_iterator begin() const { return (const_iterator(&(front()))); };
            iterator end() { return (iterator(&(back()) + 1)); };
            const_iterator end() const { return (const_iterator(&(back()) + 1)); };

            reverse_iterator rbegin() { return (reverse_iterator(end())); };
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };
            reverse_iterator rend() { return (reverse_iterator(begin())); };
            const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); };

            // Capacity
            size_type size() const { return(_size); };
            size_type max_size() const { return (_allocator.max_size()); };
            size_type capacity() const { return (_capacity); };
            size_type vacant() const { return (_capacity - _size); };
            bool empty() const { return(!_size ? true : false); };
            bool full() const { return (_size == _capacity); };
// 26
// 8
// 9

// [ 2] [][] 6
// [ 7] [][][][][][][*] 0
// [14] [][][][][][][][][][][][][][*]
// [23] [*][][][*][][][][][][][][][][][][][][][][][][][]

            // Element access
            reference front() { return (_array_ptr.front().front()); };
            const_reference front() const { return (_array_ptr.front().front()); };
            reference back() { return (_array_ptr.back().back()); };
            const_reference back() const { return (_array_ptr.back().back()); };
            reference at(size_type n)
            {
                size_type   rest = n;
                container_iterator it = _array_ptr.begin();

                for ( ; it != _array_ptr.end() ; it++)
                {
                    if (rest - (*it).size() < 0)
                        break ;
                    rest -= (*it).size();
                }
                if (it == _array_ptr.end())
                    throw std::out_of_range("out of range - pyramid 'operator[]'");
                return (*it)[rest];
            };
            const_reference at(size_type n) const {
                return (at(n));
            };
            reference operator[](size_type n) { 
                return (at(n));
            };
            const_reference operator[](size_type n) const {
                return (at(n));
            };

            // Modifiers
            iterator erase (iterator position)
            {
                return (erase(position, position + 1));
            };

            iterator erase (iterator first, iterator last)
            {
                pointer ret = &(*first);

                if (first != last)
                {
                    while (last != end())
                    {
                        *first = *last;
                        _allocator.destroy(&(*last));
                        first++;
                        last++;
                    }
                    _size = _size - (last - first);
                }
                return (iterator(ret));
            };

            bool push_back(const value_type & val) {
                if (_size >= _capacity)
                    return false;
                _size++;
                _allocator.construct(&(_array_ptr[_size - 1]), val);
                return true;
            };
            void pop_back() {
                erase(end() - 1);
            };
    }
}

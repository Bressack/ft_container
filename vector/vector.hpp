#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <stdexcept>
# include <ostream>
# include <iostream>
# include "../others/color.hpp"
# include "../others/utils.hpp"
# include "../others/iterator_traits.hpp"
# include "../others/reverse_iterator.hpp"
# include "../others/enable_if.hpp"
# include "../others/iterator.hpp"
# include "../others/is_integral.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        /// Member types
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
            typedef size_t                                          size_type;              // an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

        private:
            Alloc           _allocator;
            size_type       _size;
            size_type       _capacity;
            pointer         _array_ptr;

        public:
            /// Member functions
            // default (1)
            explicit vector(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array_ptr(NULL) {};

            // fill (2)
            explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array_ptr(NULL)
            {
                if (n)
                    assign(n, val);
            };

            // range (3)
            template <class InputIterator> // enable if "not integral" = simplification pour "enable_if iterator"
            vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                InputIterator>::type it_type = InputIterator(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array_ptr(NULL)
            {
                (void)it_type;
                assign(first, last);
            };

            // copy (4)
            vector(const vector &x) : _allocator(x._allocator), _size(0), _capacity(0), _array_ptr(NULL)
            {
                *this = x;
            };
            vector &operator=(const vector &x)
            {
                assign(x.begin(), x.end());
                return (*this);
            };
            ~vector()
            {
                if (_array_ptr)
                {
                    clear();
                    _allocator.deallocate(_array_ptr, _capacity);
                    _array_ptr = NULL;
                }
            };

        // Iterators
            // return an iterator on the first allocated element
            iterator begin() { return (iterator(&(front()))); };
            // return an const iterator on the first allocated element
            const_iterator begin() const { return (const_iterator(&(front()))); };
            // return an iterator on the last allocated element (after the last elem)
            iterator end() { return (iterator(&(back()) + 1)); };
            const_iterator end() const { return (const_iterator(&(back()) + 1)); };

            reverse_iterator rbegin() { return (reverse_iterator(end())); };
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };
            reverse_iterator rend() { return (reverse_iterator(begin())); };
            const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); };

        // Capacity
            size_type size() const { return(_size); };
            size_type max_size() const { return (_allocator.max_size()); };
            void resize (size_type n, value_type val = value_type()) {
                if (n > size())
                    insert(end(), n - size(), val);
                else if (n < _size)
                    erase(begin() + n, end());
            };
            size_type capacity() const { return(_capacity); };
            bool empty() const { return(!_size ? true : false); };
            void reserve (size_type n)
            {
                // old capacity
                size_type init_capacity = _capacity;
                // old ptr saved to deallocate it at the end
                pointer init_start = _array_ptr;

                // if ask memory over max_size() exception
                if (n > max_size())
                    throw std::length_error("vector::reserve");
                // if the current memory is large enough, just return else,
                // allocate more momory and recontructs old memory in the new one
                if (n > _capacity)
                {
                    // std::vector always alloc the double of the asked memory
                    if (n <= _size * 2)
                        n = _size * 2;
                    pointer curr_old = init_start;
                    // alloc new area of memory
                    _array_ptr = _allocator.allocate(n);
                    pointer curr_new = _array_ptr;
                    // write old area in the new one
                    for (size_t i = 0; i < _size; i++)
                    {
                        _allocator.construct(curr_new, *curr_old);
                        curr_old++;
                        curr_new++;
                    }
                    // free the old area
                    _allocator.deallocate(init_start, init_capacity);
                    // update new capacity
                    _capacity = n;
                }
            };
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
            // range (1)
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type it_type = InputIterator())
            {
                (void)it_type;
                size_type init_capacity = _capacity;

                clear();
                insert(begin(), first, last);
                if (_capacity < init_capacity)
                    _capacity = init_capacity;
            };
            // fill (2)
            void assign(size_type n, const value_type &val)
            {
                size_type init_capacity = _capacity;

                clear();
                insert(begin(), n, val);
                if (_capacity < init_capacity)
                    _capacity = init_capacity;
            };
            void push_back (const value_type& val) {
                 reserve(_size + 1);
                _size++;
                _allocator.construct(&(_array_ptr[_size - 1]), val);
            };
            void pop_back() {
                erase(end() - 1);
            };
            // single element (1)
            iterator insert(iterator position, const value_type &val)
            {
                difference_type pos = position - begin();

                insert(position, 1, val);
                return (iterator(begin() + pos));
            };

            // fill (2)
            void insert(iterator position, size_type n, const value_type &val)
            {
                vector v;
                size_type new_size = _size + n;
                size_type new_capacity = new_size;

                // trick
                if (_capacity < new_capacity)
                {
                    if (new_capacity <= _size * 2)
                        new_capacity = _size * 2;
                }
                else
                    new_capacity = _capacity;

                v.reserve(new_capacity);
                _capacity = new_capacity;

                iterator it = begin();
                for (; it != position; it++)
                    v.push_back(*it);
                while (n--)
                    v.push_back(val);
                for (; it != end(); it++)
                    v.push_back(*it);

                swap(v);
                _size = new_size;
            };

            // range (3)
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type it_type = InputIterator())
            {
                (void)it_type;
                vector v;
                InputIterator first_cpy = first;
                int n = 0;

                for (; first_cpy != last; first_cpy++)
                    n++; // == size of range to insert
                size_type new_size = _size + n;
                size_type new_capacity = new_size;
                // trick
                if (_capacity < new_capacity)
                {
                    if (new_capacity <= _size * 2)
                        new_capacity = _size * 2;
                }
                else
                    new_capacity = _capacity;
                v.reserve(new_capacity);
                _capacity = new_capacity;
                iterator it = begin();
                for (; it != position; it++)
                    v.push_back(*it);
                while (first != last)
                    v.push_back(*(first++));
                for (; it != end(); it++)
                    v.push_back(*it);
                swap(v);
                _size = new_size;
            };
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
            void swap(vector &x)
            {
                ft::ft_swap(_array_ptr, x._array_ptr);
                ft::ft_swap(_size, x._size);
                ft::ft_swap(_capacity, x._capacity);
                ft::ft_swap(_allocator, x._allocator);
            };
            void clear() { erase(begin(), end()); };
        // Allocator
            allocator_type get_allocator() const { return (_allocator); };
    };
    // Non-member function overloads
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (0);
        return (ft::ft_equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }

} // namespace ft
#endif
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <deque>
# include <vector>
# include <cstddef>
# include <stdexcept>
# include <ostream>
# include <iostream>
# include " color.hpp"
# include " utils.hpp"
# include " iterator_traits.hpp"
# include " reverse_iterator.hpp"
# include " enable_if.hpp"
# include "normal_iterator.hpp"


namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        /// Member types
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;
            typedef typename Alloc::reference                       reference;
            typedef typename Alloc::const_reference                 const_reference;
            typedef typename Alloc::pointer                         pointer;
            typedef typename Alloc::const_pointer                   const_pointer;

            typedef typename ft::normal_iterator<pointer>           iterator;
            typedef typename ft::normal_iterator<const_pointer>     const_iterator;
            typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;

        private:
            Alloc           _allocator;
            size_type       _size;
            size_type       _capacity;
            pointer         _array_ptr;

        public:
            // default (1)
            explicit vector(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array_ptr(NULL){};

            // fill (2)
            explicit vector(size_type n, const value_type &val = value_type(),
                            const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array_ptr(NULL)
            {
                if (n)
                    assign(n, val);
            };

            // range (3)
            template <class InputIterator> // enable if "not integral" = simplification pour "enable_if iterator"
            vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type it_type = InputIterator(),
                const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array_ptr(NULL)
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
                clear();
                if (_array_ptr)
                    _allocator.deallocate(_array_ptr, _capacity);
                _array_ptr = NULL;
            };

            // ITERATORS : 4 (2 + reverse) + leurs const
            iterator begin() { return (iterator(&(front()))); };
            const_iterator begin() const { return (const_iterator(&(front()))); };
            iterator end() { return (iterator(&(back()) + 1)); };
            const_iterator end() const { return (const_iterator(&(back()) + 1)); };

            reverse_iterator rbegin() { return (reverse_iterator(end())); };
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };
            reverse_iterator rend() { return (reverse_iterator(begin())); };
            const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); };

            // CAPACITY : 6 (size, max_size, resize, capacity, empty, reserve)

            size_type size() const { return (_size); };
            size_type max_size() const { return (_allocator.max_size()); }
            size_type capacity() const { return (_capacity); };
            bool empty() const { return (size() == 0); };

            void resize(size_type n, value_type val = value_type())
            {
                if (n > size())
                    insert(end(), n - size(), val);
                else if (n < _size)
                    erase(begin() + n, end());
            };

            void reserve(size_type n) // c'est ici que la reallocation arrive (<=> capacity() < n)
            {
                size_type init_capacity = _capacity;
                pointer init_start = _array_ptr;

                if (n > max_size())
                    throw std::length_error("vector::reserve");
                if (n > _capacity)
                {
                    if (n <= _size * 2)
                        n = _size * 2;

                    pointer curr_old = init_start;
                    _array_ptr = _allocator.allocate(n);
                    pointer curr_new = _array_ptr;
                    for (size_t i = 0; i < _size; i++)
                    {
                        _allocator.construct(curr_new, *curr_old);
                        curr_old++;
                        curr_new++;
                    }
                    _allocator.deallocate(init_start, init_capacity);
                    _capacity = n;
                }
            };

            // ELEMENT ACCESS : 4 + leurs const ([], at, front, back)
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

            // MODIFIERS : 2 assign, push_back, pop_back, 3 insert, 2 erase, swap, clear

            // range (1)
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type it_type = InputIterator())
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

            void push_back(const value_type &val)
            {
                reserve(_size + 1);
                _size += 1;
                _allocator.construct(&(_array_ptr[_size - 1]), val);
            };

            void pop_back()
            {
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

            iterator erase(iterator position)
            {
                return (erase(position, position + 1));
            };

            iterator erase(iterator first, iterator last)
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

            allocator_type get_allocator() const { return (_allocator); };

    }; // vector class

    // RELATIONAL OPERATORS

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



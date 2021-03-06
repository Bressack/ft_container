#ifndef MAP_HPP
#define MAP_HPP

#include "tree_iterator.hpp"
#include "pair.hpp"


namespace ft
{
    template <class Key,
              class T,
              class Compare = std::less<Key>,
              class Allocator = std::allocator<ft::pair<const Key, T> > >
    class Map
    {
        protected:
            typedef Key                                        key_type;
            typedef T                                          mapped_type;
            typedef pair<const key_type, mapped_type>          value_type;
            typedef Compare                                    key_compare;
            typedef Allocator                                  allocator_type;
            typedef typename allocator_type::reference         reference;
            typedef typename allocator_type::const_reference   const_reference;
            typedef typename allocator_type::pointer           pointer;
            typedef typename allocator_type::const_pointer     const_pointer;
            typedef typename allocator_type::size_type         size_type;
            typedef typename allocator_type::difference_type   difference_type;

            typedef std::reverse_iterator<iterator> reverse_iterator;
            typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        private:
            tree_type _tree;
            allocator_type _alloc;
            key_compare _comp;

        public:
            // empty (1)
            map(const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type());
            // range (2)
            template <class InputIterator>
            map(InputIterator first, InputIterator last,
                const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type());
            // copy (3)
            map(const map &x);
            ~map();
            map &operator=(const map &x);
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;

            bool empty() const;
            size_type size() const;
            size_type max_size() const;
            mapped_type& operator[] (const key_type& k);
            // single element (1)
            ft::pair<iterator,bool> insert (const value_type& val);
            // with hint (2)
            iterator insert (iterator position, const value_type& val);
            // range (3)
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last);
            // (1)
            void erase (iterator position);
            // (2)
            size_type erase (const key_type& k);
            // (3)
            void erase (iterator first, iterator last);
            void swap (::map& x);
            void clear();
            key_compare key_comp() const;
            value_compare value_comp() const;
            iterator find (const key_type& k);
            const_iterator find (const key_type& k) const;
            size_type count (const key_type& k) const;
            iterator lower_bound (const key_type& k);
            const_iterator lower_bound (const key_type& k) const;
            iterator upper_bound (const key_type& k);
            const_iterator upper_bound (const key_type& k) const;
            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            ft::pair<iterator,iterator>             equal_range (const key_type& k);
            allocator_type get_allocator() const;
    };
}
#endif

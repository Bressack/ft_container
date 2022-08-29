#ifndef MAP_HPP
#define MAP_HPP

#include "AVLtree.hpp"

namespace ft
{
    template <class Key,
              class T,
              class Compare = std::less<Key>,
              class Alloc = std::allocator<ft::pair<const Key, T> >
             >
    class map
    {
        public:
            typedef ft::tree<Key, T, Compare, Alloc>     tree_type;

            typedef Key                                  key_type;
            typedef T                                    mapped_type;
            typedef Compare                              key_compare;
            typedef Alloc                                allocator_type;

            typedef ft::pair<key_type, mapped_type>      value_type;
            typedef size_t                               size_type;
            typedef ptrdiff_t                            difference_type;
            typedef typename tree_type::value_compare    value_compare;

            typedef ft::node<value_type>                 node_type;
            typedef ft::node<value_type> *               node_pointer;

            typedef ft::tree_iterator<value_type>                          iterator;
            typedef ft::const_tree_iterator<value_type>                    const_iterator;
            typedef ft::reverse_iterator<tree_iterator<value_type> >       reverse_iterator;
            typedef ft::reverse_iterator<const_tree_iterator<value_type> > const_reverse_iterator;

        private:
            tree_type       _tree;
            allocator_type  _alloc;
            key_compare     _comp;

        public:
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(), _alloc(alloc), _comp(comp){};

            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(), _alloc(alloc), _comp(comp)
            { insert(first, last); };

            map(const map &x) : _tree(x._tree), _alloc(x._alloc), _comp(x._comp){};

            map &operator=(const map &x)
            {
                _tree = x._tree;
                _alloc = x._alloc;
                _comp = x._comp;
                return (*this);
            };

            ~map(){};

            // 4 ITERATORS : 4 (2 + reverse) + leurs const
            iterator begin() { return (_tree.begin()); };
            const_iterator begin() const { return (_tree.begin()); };
            iterator end() { return (_tree.end()); };
            const_iterator end() const { return (_tree.end()); };

            reverse_iterator rbegin() { return (_tree.rbegin()); };
            const_reverse_iterator rbegin() const { return (_tree.rbegin()); };
            reverse_iterator rend() { return (_tree.rend()); };
            const_reverse_iterator rend() const { return (_tree.rend()); };

            // 3 CAPACITY (size, max_size, empty)
            size_type size() const { return (_tree.size()); };
            size_type max_size() const { return (_tree.max_size()); }
            bool empty() const { return (_tree.empty()); };

            // 1 ELEMENT ACCESS
            mapped_type &operator[](const key_type &k)
            { return (_tree[k]); };

            // 4 MODIFIERS : 3 insert, 3 erase, swap, clear

            ft::pair<iterator, bool> insert(const value_type &val) // single element
            { return (_tree.insert(val)); };

            iterator insert(iterator position, const value_type &val) // with hint
            {
                (void)position;
                return (iterator(_tree.insert(val)));
            };

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last) // range
            { return (_tree.insert(first, last)); };

            void erase(iterator position) // "If an invalid position or range is specified, it causes undefined behavior."
            { return (_tree.remove(position)); };

            size_type erase(const key_type & k)
            { return (_tree.remove(k)); };

            void erase(iterator first, iterator last) // "If an invalid position or range is specified, it causes undefined behavior."
            { return (_tree.remove(first, last)); };

            void swap(map &x)
            { return (_tree.swap(x._tree)); };

            void clear()
            { return (_tree.clear()); };

            // 2 OBSERVERS (key_comp et value_comp)
            key_compare key_comp() const
            { return (_tree.key_comp()); };

            value_compare value_comp() const
            { return (_tree.value_comp()); };

            // 5 OPERATIONS (find, lower_bound, upper_bound, equal_range + leurs 4 const + count)

            iterator find(const key_type &k)
            { return (_tree.search(k)); };

            const_iterator find(const key_type &k) const
            { return (_tree.search(k)); };

            size_type count(const key_type &k) const
            { return (_tree.count(k)); };

            iterator lower_bound(const key_type &k) // 1st not to go before
            { return (_tree.lower_bound(k)); };

            const_iterator lower_bound(const key_type &k) const
            { return (_tree.lower_bound(k)); };

            iterator upper_bound(const key_type &k) // 1st to go after
            { return (_tree.upper_bound(k)); };

            const_iterator upper_bound(const key_type &k) const
            { return (_tree.upper_bound(k)); };

            ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
            { return (_tree.equal_range(k)); };

            ft::pair<iterator, iterator> equal_range(const key_type &k)
            { return (_tree.equal_range(k)); };

            // 1 ALLOCATOR
            allocator_type get_allocator() const { return (_tree.get_allocator()); };

    }; // map class

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (0);
        return (ft::ft_equal(lhs.begin(), lhs.end(), rhs.begin()));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs == rhs);
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(rhs < lhs);
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (rhs < lhs);
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs < rhs);
    };

    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs) { lhs.swap(rhs); }

} // namespace ft

#endif

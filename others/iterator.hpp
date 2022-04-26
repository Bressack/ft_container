#ifndef ITERATOR
#define ITERATOR

namespace ft
{
    template <typename T>
    class iterator
    {
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T &reference;

        private:
            value_type *_base;

        public:
            iterator() : _base(NULL) {}
            iterator(const iterator &rhs) : _base(rhs._base) {}
            explicit iterator(pointer base) : _base(base) {}
            iterator &operator=(const iterator &rhs) {
                if (this != &rhs)
                    _base = rhs._base;
                return *this;
            }
            virtual ~iterator() {}
            bool operator==(const iterator &rhs) const { return _base == rhs._base; }
            bool operator!=(const iterator &rhs) const { return _base != rhs._base; }
            reference operator*() const { return *_base; }
            pointer operator->() const { return _base; }
            iterator operator+(const difference_type &n) const { return iterator(_base + n); }
            difference_type operator+(const iterator &rhs) const { return _base + rhs._base; }
            iterator operator-(const difference_type &n) const { return iterator(_base - n); }
            difference_type operator-(const iterator &rhs) const { return _base - rhs._base; }
            bool operator<(const iterator &rhs) const { return _base < rhs._base; }
            bool operator>(const iterator &rhs) const { return _base > rhs._base; }
            bool operator<=(const iterator &rhs) const { return _base <= rhs._base; }
            bool operator>=(const iterator &rhs) const { return _base >= rhs._base; }
            iterator &operator++()
            {
                ++_base;
                return *this;
            }
            iterator operator++(int)
            {
                iterator tmp(*this);
                ++_base;
                return tmp;
            }
            iterator &operator--()
            {
                --_base;
                return *this;
            }
            iterator operator--(int)
            {
                iterator tmp(*this);
                --_base;
                return tmp;
            }
            iterator &operator+=(difference_type n)
            {
                _base += n;
                return *this;
            }
            iterator &operator-=(difference_type n)
            {
                _base -= n;
                return *this;
            }
            reference operator[](difference_type n) const { return _base[n]; }
    };
    template <class I>
    iterator<I> operator+(typename iterator<I>::difference_type n, const iterator<I> &rhs)
    { return n + rhs; }

    template <class I>
    iterator<I> operator-(typename iterator<I>::difference_type n, const iterator<I> &rhs)
    { return n - rhs; }

} // namespace ft

#endif
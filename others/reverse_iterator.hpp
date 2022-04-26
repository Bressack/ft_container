#ifndef FT_ITERATOR
#define FT_ITERATOR

namespace ft
{
    template <typename T>
    class reverse_iterator
    {
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T &reference;

        private:
            value_type *_base;

        public:
            reverse_iterator() : _base(NULL) {}
            reverse_iterator(const reverse_iterator &rhs) : _base(rhs._base) {}
            explicit reverse_iterator(pointer base) : _base(base) {}
            reverse_iterator &operator=(const reverse_iterator &rhs) {
                if (this != &rhs)
                    _base = rhs._base;
                return *this;
            }
            virtual ~reverse_iterator() {}

            // compare
            bool operator==(const reverse_iterator &rhs) const { return _base == rhs._base; }
            bool operator!=(const reverse_iterator &rhs) const { return _base != rhs._base; }
            reference operator*() const { return *_base; }
            pointer operator->() const { return _base; }
            bool operator<(const reverse_iterator &rhs) const { return _base < rhs._base; }
            bool operator>(const reverse_iterator &rhs) const { return _base > rhs._base; }
            bool operator<=(const reverse_iterator &rhs) const { return _base <= rhs._base; }
            bool operator>=(const reverse_iterator &rhs) const { return _base >= rhs._base; }

            // modifier
            reverse_iterator operator+(const difference_type &n) const { return reverse_iterator(_base - n); }
            difference_type operator+(const reverse_iterator &rhs) const { return _base - rhs._base; }
            reverse_iterator operator-(const difference_type &n) const { return reverse_iterator(_base + n); }
            difference_type operator-(const reverse_iterator &rhs) const { return _base + rhs._base; }
            reverse_iterator &operator++()
            {
                --_base;
                return *this;
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator temp(*this);
                --_base;
                return temp;
            }
            reverse_iterator &operator--()
            {
                ++_base;
                return *this;
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator temp(*this);
                ++_base;
                return temp;
            }
            reverse_iterator &operator+=(difference_type n)
            {
                _base -= n;
                return *this;
            }
            reverse_iterator &operator-=(difference_type n)
            {
                _base += n;
                return *this;
            }
            reference operator[](difference_type n) const { return _base[n]; }
    };
    template <class I>
    reverse_iterator<I> operator+(typename reverse_iterator<I>::difference_type n, const reverse_iterator<I> &rhs)
    { return n - rhs; }

    template <class I>
    reverse_iterator<I> operator-(typename reverse_iterator<I>::difference_type n, const reverse_iterator<I> &rhs)
    { return n + rhs; }

} // namespace ft

#endif
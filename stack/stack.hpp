#ifndef FT_STACK_HPP
# define FT_STACK_HPP

#include <deque>
#include "../vector/vector.hpp"
#include <cstddef>
#include <iostream>
# include "../others/color.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container                                container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;

        protected:
            container_type c;

        public:
            stack(const container_type& ctnr = container_type()) : c(ctnr){};
            ~stack() {};

            bool empty() const { return c.empty(); }
            size_type size() const { return c.size(); }
            value_type& top() { return c.back(); }
            const value_type& top() const { return c.back(); }
            void push (const value_type& val) { c.push_back(val); }
            void pop() { c.pop_back(); }

        // definition with firend keyword to allow operators to use c (like rhs.c)
        template <class U, class C>
        friend bool operator==(const stack<U, C> &lhs, const stack<U, C> &rhs);

        template <class U, class C>
        friend bool operator!=(const stack<U, C> &lhs, const stack<U, C> &rhs);

        template <class U, class C>
        friend bool operator<(const stack<U, C> &lhs, const stack<U, C> &rhs);

        template <class U, class C>
        friend bool operator<=(const stack<U, C> &lhs, const stack<U, C> &rhs);

        template <class U, class C>
        friend bool operator>(const stack<U, C> &lhs, const stack<U, C> &rhs);

        template <class U, class C>
        friend bool operator>=(const stack<U, C> &lhs, const stack<U, C> &rhs);

    };

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    { return (lhs.c == rhs.c); };

    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    { return (lhs.c != rhs.c); };

    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    { return (lhs.c <  rhs.c); };

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    { return (lhs.c <= rhs.c); };

    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    { return (lhs.c >  rhs.c); };

    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    { return (lhs.c >= rhs.c); };

}

#endif
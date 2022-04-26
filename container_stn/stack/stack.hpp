#ifndef STACK_HPP
# define STACK_HPP

# include <deque>
# include <cstddef>
# include <iostream>
# include "../shared/color.hpp"
# include "../vector/vector.hpp"


namespace ft {

  template <class T, class Container = ft::vector<T> >
  class stack
	{
		public :
			typedef T                    value_type;
			typedef Container            container_type;
			typedef size_t               size_type;

		protected :
      Container                    c;

    public:
      explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
      {};

			~stack()
			{} ;

      bool empty() const
      {
        return (c.empty());
      };

      size_type size() const
      {
        return (c.size());
      };

      value_type& top()
      {
        return (c.back());
      };

      const value_type& top() const
      {
        return (c.back());
      };

      void push (const value_type& val)
      {
        return (c.push_back(val));
      };

      void pop()
      {
        return (c.pop_back());
      };

      template <class U, class Cont>
      friend bool operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

      template <class U, class Cont>
      friend bool operator!= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

      template <class U, class Cont>
      friend bool operator< (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

      template <class U, class Cont>
      friend bool operator<= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

      template <class U, class Cont>
      friend bool operator> (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

      template <class U, class Cont>
      friend bool operator>= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

	}; // stack class

  template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return (lhs.c == rhs.c);
  };

  template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return (lhs.c != rhs.c);
  };

  template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return (lhs.c < rhs.c);
  };

  template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return (lhs.c <= rhs.c);
  };

  template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return (lhs.c > rhs.c);
  };

  template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return (lhs.c >= rhs.c);
  };

} // namespace ft

#endif

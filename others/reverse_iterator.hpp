#ifndef FT__REVERSE_ITERATOR
#define FT__REVERSE_ITERATOR

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft
{
	// reverse_iterator herite de la class ft::iterator de iterator_traits
	template < typename IT > // IT is a pointer
	class reverse_iterator : public ft::iterator<ft::random_access_iterator_tag, IT>
	{
		protected:
			// on utilise aussi ft::iterator_traits comme base pour les attributs public de reverse_iterator
			typedef typename ft::iterator_traits<IT>	iterator_traits;
			IT 											_ptr;

		public:
			typedef IT											iterator_type;
			// ici sont utilisés les attributs de iterator_traits
			typedef typename iterator_traits::value_type		value_type;
			typedef typename iterator_traits::difference_type	difference_type;
			typedef typename iterator_traits::reference			reference;
			typedef typename iterator_traits::pointer			pointer;
			typedef typename iterator_traits::iterator_category	iterator_category;

			// CONSTRUCTORS / DESTRUCTOR

			// basic constructor
			reverse_iterator(iterator_type ptr = NULL) : _ptr(ptr) {}
			// explicit constructor
			explicit reverse_iterator (iterator_type it) : _ptr(it) {}
			// templated  constructor
			template <class U>
			reverse_iterator(const reverse_iterator<U>& rev_it) : _ptr(rev_it.ptr()) {}
			// destructor
			~reverse_iterator() {}
			// assign
			reverse_iterator &	operator=(const reverse_iterator &rhs) { _ptr = rhs.ptr(); return (*this); }
			// ptr getter with correct return value type (iterator_type)
			const iterator_type &ptr() const { return (_ptr); }

			// value of
			reference			operator*	() 					const	{ iterator_type cpy = _ptr; --cpy; return (*cpy); }
			// address of
			pointer				operator->	() 					const	{ return &(operator*()); }
			// access at
			reference			operator[]	(difference_type n) const	{ return (ptr()[-n - 1]); }
			// +
			reverse_iterator	operator+	(difference_type n) const	{ return ( reverse_iterator(_ptr - n) ); }
			reverse_iterator&	operator++	()							{ _ptr--; return (*this); }
			reverse_iterator 	operator++	(int)						{ reverse_iterator temp = *this; --_ptr; return temp; }
			reverse_iterator&	operator+=	(difference_type n)			{ _ptr -= n; return (*this); }
			// -
			reverse_iterator	operator-	(difference_type n) const	{ return (reverse_iterator(_ptr + n)); } ;
			reverse_iterator&	operator--	()							{ _ptr++; return (*this); } ;
			reverse_iterator 	operator--	(int)						{ reverse_iterator temp = *this; ++_ptr; return temp; } ;
			reverse_iterator&	operator-=	(difference_type n)			{ _ptr += n; return (*this); }

			// difference in size between pointers
			difference_type operator-(const reverse_iterator &rhs) const	{ return (_ptr - rhs.ptr()); }

	}; // reverse_iterator class

    // NON-MEMBER OVERLOADS OPPERATOR FUNCTIONS

    template <typename T>
    inline bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) { return (lhs.ptr() == rhs.ptr()); }

    template <typename T, typename U> // important pour comparaison entre const et non const
    inline bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return (lhs.ptr() == rhs.ptr()); }

    template <typename T>
    inline bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) { return !(lhs == rhs); }

    template <typename T, typename U>
    inline bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return !(lhs == rhs); }

    template <typename T>
    inline bool operator< (const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) { return (rhs.ptr() < lhs.ptr()); }

    template <typename T, typename U>
    inline bool operator< (const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return (rhs.ptr() < lhs.ptr()); }

    template <typename T>
    inline bool operator> (const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) { return (rhs < lhs); }

    template <typename T, typename U>
    inline bool operator> (const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return (rhs < lhs); }

    template <typename T>
    inline bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) { return !(rhs < lhs); }

    template <typename T, typename U>
    inline bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return !(rhs < lhs); }

    template <typename T>
    inline bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) { return !(lhs < rhs); }

    template <typename T, typename U>
    inline bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return !(lhs < rhs); }

    template <typename T>
    inline reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> &rev_it) { return (reverse_iterator<T>(rev_it + n)); }

    template <typename T>
    inline typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T> &rhs) { return (rhs.ptr() - lhs.ptr()); }

    template <typename T, typename U>
    inline typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<U> &rhs) { return (rhs.ptr() - lhs.ptr()); }


} // FT__REVERSE_ITERATOR
#endif

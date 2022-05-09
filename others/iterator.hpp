#ifndef FT__ITERATOR
#define FT__ITERATOR

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft
{
	// iterator herite de la class ft::iterator de iterator_traits
	template < typename IT > // IT is a pointer
	class iterator : public ft::iterator_core<ft::random_access_iterator_tag, IT>
	{
		protected:
			// on utilise aussi ft::iterator_traits comme ptr pour les attributs public de iterator
			typedef typename ft::iterator_traits<IT>	iterator_traits;
			IT											_ptr;

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
			iterator(iterator_type ptr = NULL) : _ptr(ptr) {};
			// templated  constructor
			template <typename U>
			iterator(const iterator<U> &iterator) : _ptr(iterator.ptr()) {};
			// destructor
			~iterator(){};
			// assign
			iterator &		operator=(const iterator &rhs) { _ptr = rhs.ptr(); return (*this); }
			// ptr getter with correct return value type (iterator_type)
			const iterator_type &ptr() const { return (_ptr); };

			// value of
			reference		operator*	() 						const	{ return (*_ptr); }
			// address of
			pointer			operator->	() 						const	{ return (_ptr); }
			// access at
			reference		operator[]	(difference_type n) 	const	{ return (_ptr[n]); }
			// +
			iterator		operator+	(difference_type n) 	const	{ return (iterator(_ptr + n)); }
			iterator &		operator++	()								{ _ptr++; return (*this); }
			iterator		operator++	(int)							{ iterator cpy(*this); operator++(); return (cpy); }
			iterator &		operator+=	(difference_type n)				{ _ptr += n; return (*this); }
			// -
			iterator		operator-	(difference_type n) 	const	{ return (iterator(_ptr - n)); }
			iterator &		operator--	()								{ _ptr--; return (*this); }
			iterator		operator--	(int)							{ iterator cpy(*this); operator--(); return (cpy); }
			iterator &		operator-=	(difference_type n)				{ _ptr -= n; return (*this); }

			// difference in size between pointers
			difference_type operator-	(const iterator &rhs)	const	{ return (_ptr - rhs.ptr()); }

	}; // iterator class

	// ITERATOR FUNCTIONS

	template <typename Iterator, typename difference_type>
	inline void advance(Iterator &it, difference_type n) { it += n; }

	template <class Iterator>
	inline typename iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last) { return (last - first); }

	// OUT OF CLASS OPERATORS

	template <typename T>
	inline bool operator==(const iterator<T> &lhs, const iterator<T> &rhs) { return (lhs.ptr() == rhs.ptr()); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator==(const iterator<T> &lhs, const iterator<U> &rhs) { return (lhs.ptr() == rhs.ptr()); }

	template <typename T>
	inline bool operator!=(const iterator<T> &lhs, const iterator<T> &rhs) { return !operator==(lhs, rhs); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator!=(const iterator<T> &lhs, const iterator<U> &rhs) { return !operator==(lhs, rhs); }

	template <typename T>
	inline bool operator<(const iterator<T> &lhs, const iterator<T> &rhs) { return (lhs.ptr() < rhs.ptr()); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator<(const iterator<T> &lhs, const iterator<U> &rhs) { return (lhs.ptr() < rhs.ptr()); }

	template <typename T>
	inline bool operator>(const iterator<T> &lhs, const iterator<T> &rhs) { return (operator<(rhs, lhs) && operator!=(rhs, lhs)); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator>(const iterator<T> &lhs, const iterator<U> &rhs) { return (operator<(rhs, lhs) && operator!=(rhs, lhs)); }

	template <typename T>
	inline bool operator<=(const iterator<T> &lhs, const iterator<T> &rhs) { return !operator>(lhs, rhs); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator<=(const iterator<T> &lhs, const iterator<U> &rhs) { return !operator>(lhs, rhs); }

	template <typename T>
	inline bool operator>=(const iterator<T> &lhs, const iterator<T> &rhs) { return !operator<(lhs, rhs); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator>=(const iterator<T> &lhs, const iterator<U> &rhs) { return !operator<(lhs, rhs); }

	template <typename T>
	inline iterator<T> operator+(typename iterator<T>::difference_type n, const iterator<T> &it) { return (iterator<T>(it.ptr() + n)); }

	template <typename T, typename U>
	inline typename iterator<T>::difference_type operator-(const iterator<T> &lhs, const iterator<U> &rhs) { return (lhs.ptr() - rhs.ptr()); }

} // FT__ITERATOR
#endif

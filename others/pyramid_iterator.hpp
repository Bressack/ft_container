#ifndef FT__ITERATOR
#define FT__ITERATOR

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft
{
	// iterator herite de la class ft::iterator de iterator_traits
	template < typename IT, typename PIT > // IT is a pointer and PIT is a pointer of the parent
	class ripped_iterator : public ft::iterator_core<ft::random_access_iterator_tag, IT>
	{
		protected:
			// on utilise aussi ft::iterator_traits comme ptr pour les attributs public de ripped_iterator
			typedef typename ft::iterator_traits<IT>	iterator_traits;
			IT											_ptr;
			PIT											_pptr;

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
			ripped_iterator(iterator_type ptr = NULL) : _ptr(ptr) {};
			// templated  constructor
			template <typename U>
			ripped_iterator(const ripped_iterator<U> &ripped_iterator) : _ptr(ripped_iterator.ptr()) {};
			// destructor
			~ripped_iterator() {};
			// assign
			ripped_iterator &	operator=(const ripped_iterator &rhs) { _ptr = rhs.ptr(); return (*this); }
			// ptr getter with correct return value type (iterator_type)
			const iterator_type &ptr() const { return (_ptr); };

			// value of
			reference			operator*	() 						const	{ return (*_ptr); }
			// address of
			pointer				operator->	() 						const	{ return (_ptr); }
			// access at
			reference			operator[]	(difference_type n) 	const	{ return (_ptr[n]); }
			// +
			ripped_iterator		operator+	(difference_type n) 	const	{ return (ripped_iterator(_ptr + n)); }
			ripped_iterator &	operator++	()								{
				if (_ptr + 1 == _pptr.end())
					if ()
						_ptr = .begin()
					else
						_ptr = 
				else
					_ptr++;
				return (*this);
			}
			ripped_iterator		operator++	(int)							{ ripped_iterator cpy(*this); operator++(); return (cpy); }
			ripped_iterator &	operator+=	(difference_type n)				{ _ptr += n; return (*this); }
			// -
			ripped_iterator		operator-	(difference_type n) 	const	{ return (ripped_iterator(_ptr - n)); }
			ripped_iterator &	operator--	()								{ _ptr--; return (*this); }
			ripped_iterator		operator--	(int)							{ ripped_iterator cpy(*this); operator--(); return (cpy); }
			ripped_iterator &	operator-=	(difference_type n)				{ _ptr -= n; return (*this); }

			// difference in size between pointers
			difference_type 	operator-	(const ripped_iterator &rhs)	const	{ return (_ptr - rhs.ptr()); }

	}; // ripped_iterator class

	// ITERATOR FUNCTIONS

	template <typename Iterator, typename difference_type>
	inline void advance(Iterator &it, difference_type n) { it += n; }

	template <class Iterator>
	inline typename iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last) { return (last - first); }

	// OUT OF CLASS OPERATORS

	template <typename T>
	inline bool operator==(const ripped_iterator<T> &lhs, const ripped_iterator<T> &rhs) { return (lhs.ptr() == rhs.ptr()); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator==(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return (lhs.ptr() == rhs.ptr()); }

	template <typename T>
	inline bool operator!=(const ripped_iterator<T> &lhs, const ripped_iterator<T> &rhs) { return !operator==(lhs, rhs); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator!=(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return !operator==(lhs, rhs); }

	template <typename T>
	inline bool operator<(const ripped_iterator<T> &lhs, const ripped_iterator<T> &rhs) { return (lhs.ptr() < rhs.ptr()); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator<(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return (lhs.ptr() < rhs.ptr()); }

	template <typename T>
	inline bool operator>(const ripped_iterator<T> &lhs, const ripped_iterator<T> &rhs) { return (operator<(rhs, lhs) && operator!=(rhs, lhs)); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator>(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return (operator<(rhs, lhs) && operator!=(rhs, lhs)); }

	template <typename T>
	inline bool operator<=(const ripped_iterator<T> &lhs, const ripped_iterator<T> &rhs) { return !operator>(lhs, rhs); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator<=(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return !operator>(lhs, rhs); }

	template <typename T>
	inline bool operator>=(const ripped_iterator<T> &lhs, const ripped_iterator<T> &rhs) { return !operator<(lhs, rhs); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator>=(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return !operator<(lhs, rhs); }

	template <typename T>
	inline ripped_iterator<T> operator+(typename ripped_iterator<T>::difference_type n, const ripped_iterator<T> &it) { return (ripped_iterator<T>(it.ptr() + n)); }

	template <typename T, typename U>
	inline typename ripped_iterator<T>::difference_type operator-(const ripped_iterator<T> &lhs, const ripped_iterator<U> &rhs) { return (lhs.ptr() - rhs.ptr()); }

} // FT__ITERATOR
#endif

#ifndef NORMAL_ITERATOR_HPP
# define NORMAL_ITERATOR_HPP

# include <cstddef>
# include "../shared/iterator_traits.hpp"

namespace ft
{
	template < typename IT > // IT is a pointer
	class normal_iterator : public ft::iterator<ft::random_access_iterator_tag, IT>
	{
		protected:
			typedef typename ft::iterator_traits<IT>			iterator_traits;
			IT 													_ptr;

		public:

			typedef IT											iterator_type;
			typedef typename iterator_traits::value_type		value_type;
			typedef typename iterator_traits::difference_type	difference_type;
			typedef typename iterator_traits::reference			reference;
			typedef typename iterator_traits::pointer			pointer;
			typedef typename iterator_traits::iterator_category	iterator_category;


// CONSTRUCTORS / DESTRUCTOR
		normal_iterator(iterator_type ptr = NULL) : _ptr(ptr) {};
		template<typename U>
		normal_iterator(const normal_iterator<U> &iterator) : _ptr(iterator.base()) {};
		~normal_iterator() {};
		normal_iterator	&	operator=(const normal_iterator &rhs) { _ptr = rhs.base(); return (*this); }

// FORWARD INCLUDED

		reference			operator*() const { return (*_ptr); }
		pointer				operator->() const { return (_ptr); }
		normal_iterator	&	operator++() { _ptr++; return (*this); }
		normal_iterator		operator++(int) { normal_iterator cpy(*this); operator++(); return (cpy); }

// BIDIRECTIONAL INCLUDED

		normal_iterator	&	operator--() { _ptr--; return (*this); }
		normal_iterator		operator--(int) { normal_iterator cpy(*this); operator--(); return (cpy); }

// RANDOM ACCESS INCLUDED

		normal_iterator	&	operator+=(difference_type n) { _ptr += n; return (*this); }
		normal_iterator		operator+(difference_type n) const { return (normal_iterator(_ptr + n)); }
		normal_iterator	&	operator-=(difference_type n) { _ptr -= n; return (*this); }
		normal_iterator		operator-(difference_type n) const { return (normal_iterator(_ptr - n)); }
		difference_type		operator-(const normal_iterator &rhs) const { return (_ptr - rhs.base()); }
		reference			operator[](difference_type n) const { return (_ptr[n]); }

		const iterator_type & base() const { return (_ptr); }

	}; // normal_iterator class

	// ITERATOR FUNCTIONS

	template <typename Iterator, typename difference_type>
	inline void advance (Iterator & it, difference_type n) { it += n; }

	template<class Iterator>
	inline typename iterator_traits<Iterator>::difference_type distance (Iterator first, Iterator last) { return (last - first); }

	// OUT OF CLASS OPERATORS

	template <typename T>
	inline bool operator==(const normal_iterator<T> &lhs, const normal_iterator<T> &rhs) { return (lhs.base() == rhs.base()); }

	template <typename T, typename U> // important pour comparaison entre const et non const
	inline bool operator==(const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { return (lhs.base() == rhs.base()); }

	template <typename T>
	inline bool operator!=(const normal_iterator<T> &lhs, const normal_iterator<T> &rhs) { return !operator==(lhs, rhs); }

	template <typename T, typename U>
	inline bool operator!=(const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { return !operator==(lhs, rhs); }

	template <typename T>
	inline bool operator< (const normal_iterator<T> &lhs, const normal_iterator<T> &rhs) { return (lhs.base() < rhs.base()); }

	template <typename T, typename U>
	inline bool operator< (const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { return (lhs.base() < rhs.base()); }

	template <typename T>
	inline bool operator> (const normal_iterator<T> &lhs, const normal_iterator<T> &rhs) { return  (operator<(rhs, lhs) && operator!=(rhs, lhs)); }

	template <typename T, typename U>
	inline bool operator> (const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { return  (operator<(rhs, lhs) && operator!=(rhs, lhs)); }

	template <typename T>
	inline bool operator<=(const normal_iterator<T> &lhs, const normal_iterator<T> &rhs) { return !operator>(lhs, rhs); }

	template <typename T, typename U>
	inline bool operator<=(const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { return !operator>(lhs, rhs); }

	template <typename T>
	inline bool operator>=(const normal_iterator<T> &lhs, const normal_iterator<T> &rhs) { return !operator<(lhs,rhs); }

	template <typename T, typename U>
	inline bool operator>=(const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { return !operator<(lhs,rhs); }

	template<typename T>
	inline normal_iterator<T> operator+(typename normal_iterator<T>::difference_type n, const normal_iterator<T> &it) { 	return (normal_iterator<T>(it.base() + n)); }

	template<typename T, typename U>
	inline typename normal_iterator<T>::difference_type operator-(const normal_iterator<T> &lhs, const normal_iterator<U> &rhs) { 	return (lhs.base() - rhs.base()); }

} // namespace
#endif

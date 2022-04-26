#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"
# include "color.hpp"
# include "utils.hpp"

namespace ft
{
	template < class Iterator >
		class reverse_iterator
		{
			protected:
				typedef typename ft::iterator_traits<Iterator>	it_traits;
				Iterator 										_base;

			public:
				typedef Iterator															base_iterator_type;
				typedef typename it_traits::value_type				value_type;
				typedef typename it_traits::difference_type		difference_type;
				typedef typename it_traits::reference					reference;
				typedef typename it_traits::pointer						pointer;
				typedef typename it_traits::iterator_category	iterator_category;


				// CONSTRUCTORS / DESTRUCTOR

				reverse_iterator()
				{};
				explicit reverse_iterator (base_iterator_type it) : _base(it)
				{};
				template <class Iter>
				reverse_iterator (const reverse_iterator<Iter>& rev_it)
				{ _base = rev_it.base(); };

				~reverse_iterator() {};

				reverse_iterator & operator=(const reverse_iterator &rhs)
				{ _base = rhs.base(); return (*this); }

				// BASE
				/*
					A copy of the base iterator with the current state can be obtained at any time by calling member base.
				*/
				base_iterator_type base() const { return _base; };

				// OPERATIONS
				/*
					Returns a reference to the element pointed to by the iterator.
					Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it.
					The iterator shall point to some object in order to be dereferenceable.
				*/
				reference operator*() const
				{
					base_iterator_type cpy = _base; --cpy; return (*cpy);
				};
				// reference operator*() const { return (*_base);  };

				/*
					Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to.
					Internally, the function applies the binary operator- on the base iterator and returns a reverse iterator constructed with the resulting iterator value.
					Note that this function requires the base iterator to be a random-access iterator.
					This operator is also overloaded as a non-member function, with the left-hand and right-hand types inverted, but this the same behavior (see operator+).
				*/
				reverse_iterator operator+ (difference_type n) const { return ( reverse_iterator(_base - n) ); };

				/*
					Advances the reverse_iterator by one position.
					Internally, the pre-increment version (1) decrements the base iterator kept by the object (as if applying operator-- to it).
					The post-increment version (2) is implemented with a behavior equivalent to:

					reverse_iterator operator++(int) {
					  reverse_iterator temp = *this;
					  ++(*this);
					  return temp;
					}
				*/
				reverse_iterator& operator++() { _base--; return (*this); };
				reverse_iterator  operator++(int) { reverse_iterator temp = *this; --_base; return temp; };


				/*
					Advances the reverse_iterator by n element positions.
					Internally, the function decreases by n the base iterator kept by the object (as if applying operator-= to it).
					Note that this function requires the base iterator to be a random-access iterator.
				*/
				reverse_iterator& operator+= (difference_type n) { _base -= n; return (*this); };

				/*
					Returns a reverse iterator pointing to the element located n positions before the element the iterator currently points to.
					Internally, the function applies the binary operator+ on the base iterator and returns a reverse iterator constructed with the resulting iterator value.
					Note that this function requires the base iterator to be a random-access iterator.
					This operator is also overloaded as a non-member function to return the difference of subtracting iterators: see operator-).
				*/

				reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_base + n)); } ;

				/*
					Decreases the reverse_iterator by one position.
					Internally, the pre-decrement version (1) increments the base iterator kept by the object (as if applying operator++ to it).
					The post-decrement version (2) is implemented with a behavior equivalent to:
				*/
				reverse_iterator& operator--() { _base++; return (*this); } ;
				reverse_iterator  operator--(int) { reverse_iterator temp = *this; ++_base; return temp; } ;

				/*
					Descreases the reverse_iterator by n element positions.
					Internally, the function increases by n the base iterator kept by the object (as if applying operator+= to it).
					Note that this function requires the base iterator to be a random-access iterator.
				*/
				reverse_iterator& operator-= (difference_type n) { _base += n; return (*this); };

				/*
					Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
					Internally, the function calls operator* and returns its address, as if implemented as:
					pointer operator->() const {
					  return &(operator*());
					}
				*/
				pointer operator->() const { return &(operator*()); };

				/*
					Accesses the element located n positions away from the element currently pointed to by the iterator.
					If such an element does not exist, it causes undefined behavior.
					Internally, the function accesses the proper element of its base iterator, returning the same as: base()[-n-1].
				*/
				reference operator[] (difference_type n) const { return (base()[-n - 1]); };

		}; // reverse_iterator class

// NON-MEMBER FUNCTION OVERLOADS

template <typename T>
inline bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename T, typename U> // important pour comparaison entre const et non const
inline bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename T>
inline bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs)
{
	return !(lhs == rhs);
}

template <typename T, typename U>
inline bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
{
	return !(lhs == rhs);
}

template <typename T>
inline bool operator< (const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs)
{
	return (rhs.base() < lhs.base()); }

template <typename T, typename U>
inline bool operator< (const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
{
	return (rhs.base() < lhs.base()); }

template <typename T>
inline bool operator> (const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs)
{
	return (rhs < lhs);
}

template <typename T, typename U>
inline bool operator> (const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
{
	return (rhs < lhs);
}

template <typename T>
inline bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs)
{
	return !(rhs < lhs);
}

template <typename T, typename U>
inline bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
{
	return !(rhs < lhs);
}

template <typename T>
inline bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs)
{
	return !(lhs < rhs);
}

template <typename T, typename U>
inline bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
{
	return !(lhs < rhs);
}

/*
	Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it.
	The function returns the same as: rev_it+n (see reverse_iterator::operator+).
	This operator is also overloaded as a member function to return a reverse iterator offset by -n element positions (see reverse_iterator::operator-).
*/

template <typename T>
inline reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> &rev_it) { return (reverse_iterator<T>(rev_it + n)); }


/*
	Returns the distance between lhs and rhs.
	The function returns the same as subtracting lhs's base iterator from rhs's base iterator.
*/

template <typename T>
inline typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T> &rhs) { return (rhs.base() - lhs.base()); }

template <typename T, typename U>
inline typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<U> &rhs) { return (rhs.base() - lhs.base()); }


} // namespace
#endif

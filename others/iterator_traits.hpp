#ifndef ITERATOR_TRAITS_HPP_
#define ITERATOR_TRAITS_HPP_

#include <iterator>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator_core
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	struct random_access_iterator_tag {};

	template <class IT>
	class iterator_traits
	{
		typedef typename IT::difference_type	difference_type;
		typedef typename IT::value_type			value_type;
		typedef typename IT::pointer			pointer;
		typedef typename IT::reference			reference;
		typedef typename IT::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
}  // namespace ft

#endif  // ITERATOR_TRAITS_HPP_

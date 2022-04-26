#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>

namespace ft
{
	// tous les types d'iterators derivent de cette meme classe
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public :
			typedef T		  		value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};

	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

// it traits : table de correspondance que l'it soit un pointeur ou non
	template <typename Type>
	struct iterator_traits
	{
		typedef typename Type::value_type					value_type;
		typedef typename Type::difference_type		difference_type;
		typedef typename Type::pointer						pointer;
		typedef typename Type::reference					reference;
		typedef typename Type::iterator_category	iterator_category;
	};

// normal iterator
	template <typename T>
	struct iterator_traits<T *>
	{
		typedef T		 															value_type;
		typedef ptrdiff_t 												difference_type;
		typedef T *		 														pointer;
		typedef T &		 														reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

// const iterator
	template <typename T>
	struct iterator_traits<const T *>
	{
		typedef const T														value_type;
		typedef ptrdiff_t 												difference_type;
		typedef const T	*	 												pointer;
		typedef const T	&	 												reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

} // namespace
#endif

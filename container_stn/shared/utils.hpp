#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
  template<class T>
  inline void ft_swap(T &a, T &b)
  {
    T c = a;
    a = b;
    b = c;
  };

  template <class InputIterator1, class InputIterator2>
  bool ft_equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
  {
    while (first1 != last1)
    {
      if (!(*first1 == *first2))
        return (false);
      ++first1;
      ++first2;
    }
    return (true);
  };

  template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		  while (first1 != last1)
	    {
        if (first2 == last2 || *first2 < *first1)
			    return (false);
        else if (*first1 < *first2)
		       return (true);
        ++first1;
	      ++first2;
	    }
	    return (first2 != last2);
	};

  template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
	    if (first2 == last2 || comp()(*first2, *first1))
		     return (false);
	    else if (comp()(*first1, *first2))
		     return (true);
	    ++first1;
	    ++first2;
		}
		return (first2 != last2);
	};

}; // namespace ft

#endif

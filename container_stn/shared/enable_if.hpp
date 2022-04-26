#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

# include <cstddef>

namespace ft
{
  template <bool condition, typename T = void >
  struct enable_if {};

  template <typename T>
  struct enable_if<true, T> { typedef T type; };

  // si condition == true, "type" existe (valeur T)
  // sinon, pas de "type"
  // ainsi, quand j'appelle "enable_if<true, int>::type" => ca bloque si pas de "type" (pourquoi "type" ? convention)

  template <class T>
  struct is_integral { static const bool value = false; };

  template<>
  struct is_integral<bool> { static const bool value = true; };

  template<>
  struct is_integral<char> { static const bool value = true; };

  template<>
  struct is_integral<wchar_t> { static const bool value = true; };

  template<>
  struct is_integral<signed char> { static const bool value = true; };

  template<>
  struct is_integral<short int> { static const bool value = true; };

  template<>
  struct is_integral<int> { static const bool value = true; };

  template<>
  struct is_integral<long int> { static const bool value = true; };

  template<>
  struct is_integral<long long int> { static const bool value = true; };

  template<>
  struct is_integral<unsigned char> { static const bool value = true; };

  template<>
  struct is_integral<unsigned short int> { static const bool value = true; };

  template<>
  struct is_integral<unsigned int> { static const bool value = true; };

  template<>
  struct is_integral<unsigned long int> { static const bool value = true; };

  template<>
  struct is_integral<unsigned long long int> { static const bool value = true; };

  template<class T>
  struct is_integral<const T> : public is_integral<T> {};

  template<class T>
  struct is_integral<volatile T> : public is_integral<T> {};

  template<class T>
  struct is_integral<const volatile T> : public is_integral<T> {};

} // namespace ft



#endif

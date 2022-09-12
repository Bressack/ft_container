#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

# include <cstddef>

namespace ft
{
  template <bool condition, typename T = void >
  struct enable_if {};

  template <typename T>
  struct enable_if<true, T> { typedef T type; };
}
#endif

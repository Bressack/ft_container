#include <iostream>
#include <vector>
#include "vector.hpp"
#include <stdio.h>

template <typename T>
void print_vector(T *v)
{
	typename T::iterator it = (*v).begin();
	typename T::const_iterator itend = (*v).end();

	std::cout << "\033[35;01m";
	for (; it != itend; it++)
		std::cout << "[" << "\033[33;01m" << *it << "\033[35;01m" << "]";
	std::cout << "\033[0m" << std::endl;
}

template < typename T >
void print_add_area(T *ptr, size_t s)
{
    std::cout << "[" << ptr << "] --------------------------------" << std::endl;
    for (size_t i = 0; i < s; i++)
        std::cout << &ptr[i] << " - " << ptr[i] << std::endl;
    std::cout << "--------------- --------------------------------" << std::endl;
}


int main(void)
{
    int i = 0;
    ft::vector<int> toto(10, 10);

    return (0);
}


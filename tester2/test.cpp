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
    {
        ft::vector<int> toto;
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    {
        ft::vector<int> toto(10,10);
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    {
        ft::vector<int> toto(100,10);
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    {
        ft::vector<int> toto(10000,10);
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    {
        ft::vector<int> toto(63,10);
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    {
        ft::vector<int> toto(5,10);
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    {
        ft::vector<int> toto(13,10);
        std::cout << "capacity: " << toto.capacity() << std::endl;
        std::cout << "size    : " << toto.size() << std::endl;
    }
    return (0);
}


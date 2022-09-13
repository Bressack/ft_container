#ifdef TSTD
# include <vector>
namespace ft = std;
#else
# include "vector.hpp"
#endif

#include <limits.h>
#include <climits>
#include <cfloat>
#include <iostream>

int large_vector_test(int size)
{
    // positive
    {
        ft::vector<int> v;

        for (int i = 0; i < size; i++)
            v.push_back(i);
        for (int i = 0; i < size; i++)
            v.pop_back();
    }
    // negative
    {
        ft::vector<int> v;

        for (int i = 0; i < size; i++)
            v.push_back(-i);
        for (int i = 0; i < size; i++)
            v.pop_back();
    }
    return (0);
}

int main(void)
{
    std::cout << "large_vector_test - 1" << std::endl;
    large_vector_test(1);
    std::cout << "large_vector_test - 10" << std::endl;
    large_vector_test(10);
    std::cout << "large_vector_test - 100" << std::endl;
    large_vector_test(100);
    std::cout << "large_vector_test - 1000" << std::endl;
    large_vector_test(1000);
    std::cout << "large_vector_test - 10000" << std::endl;
    large_vector_test(10000);
    std::cout << "large_vector_test - 100000" << std::endl;
    large_vector_test(100000);
    std::cout << "large_vector_test - 1000000" << std::endl;
    large_vector_test(1000000);
    std::cout << "large_vector_test - 10000000" << std::endl;
    large_vector_test(10000000);
    std::cout << "large_vector_test - 100000000" << std::endl;
    large_vector_test(100000000);
    return (0);
}

#ifdef TSTD
# include <stack>
namespace ft = std;
#else
# include "stack.hpp"
#endif

#include <limits.h>
#include <climits>
#include <cfloat>
#include <iostream>

int large_stack_test(int size)
{
    // positive
    {
        ft::stack<int> v;

        for (int i = 0; i < size; i++)
            v.push(i);
        for (int i = 0; i < size; i++)
            v.pop();
    }
    // negative
    {
        ft::stack<int> v;

        for (int i = 0; i < size; i++)
            v.push(-i);
        for (int i = 0; i < size; i++)
            v.pop();
    }
    return (0);
}

int main(void)
{
    std::cout << "large_stack_test - 1" << std::endl;
    large_stack_test(1);
    std::cout << "large_stack_test - 10" << std::endl;
    large_stack_test(10);
    std::cout << "large_stack_test - 100" << std::endl;
    large_stack_test(100);
    std::cout << "large_stack_test - 1000" << std::endl;
    large_stack_test(1000);
    std::cout << "large_stack_test - 10000" << std::endl;
    large_stack_test(10000);
    std::cout << "large_stack_test - 100000" << std::endl;
    large_stack_test(100000);
    std::cout << "large_stack_test - 1000000" << std::endl;
    large_stack_test(1000000);
    std::cout << "large_stack_test - 10000000" << std::endl;
    large_stack_test(10000000);
    std::cout << "large_stack_test - 100000000" << std::endl;
    large_stack_test(100000000);

    return (0);
}

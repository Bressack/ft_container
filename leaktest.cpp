#include "vector.hpp"
#include <vector>

# define T1 int
# define T2 char
# define T3 std::string

// # define NS ft
# define NS std

# define CONT NS::vector
# define CONTT std::vector

# define VT0 CONT< T1 >
// # define VT1 CONT< VT0 >
// # define VT2 CONT< VT1 >
// # define VT3 CONT< VT2 >
// # define VT4 CONT< VT3 >
// # define VT5 CONT< VT4 >
// # define VT6 CONT< VT5 >

typedef size_t size_type;

VT0 simple_vector(size_type s)
{
    VT0 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(i);
    return v;
}

// VT1 vector_t1(size_type s)
// {
//     VT1 v;
//     for (size_type i = 0 ; i < s ; i++)
//         v.push_back(simple_vector(s));
//     return v;
// }
// VT2 vector_t2(size_type s)
// {
//     VT2 v;
//     for (size_type i = 0 ; i < s ; i++)
//         v.push_back(vector_t1(s));
//     return v;
// }
// VT3 vector_t3(size_type s)
// {
//     VT3 v;
//     for (size_type i = 0 ; i < s ; i++)
//         v.push_back(vector_t2(s));
//     return v;
// }
// VT4 vector_t4(size_type s)
// {
//     VT4 v;
//     for (size_type i = 0 ; i < s ; i++)
//         v.push_back(vector_t3(s));
//     return v;
// }
// VT5 vector_t5(size_type s)
// {
//     VT5 v;
//     for (size_type i = 0 ; i < s ; i++)
//         v.push_back(vector_t4(s));
//     return v;
// }
// VT6 vector_t6(size_type s)
// {
//     VT6 v;
//     for (size_type i = 0 ; i < s ; i++)
//     {
//         v.push_back(vector_t5(s));
//         std::cout << "VT6 " << i << std::endl;
//     }
//     return v;
// }

int main(void)
{
    // VT6   what = vector_t6(10);
    // VT1   what = vector_t1(10);
    std::vector<int> b = simple_vector(5);
    // std::vector<int> c = simple_vector(5);
    // std::vector<int> d = simple_vector(10);
    ft::vector<std::vector<int> > a;


    a.push_back(b);
    a.push_back(b);
    // a.push_back(d);

    // ft::vector<int> what = simple_vector(10);


    // what.push_back(a);
    // what.push_back(b);

    // std::cout << what.size() << std::endl;
    // std::cout << what.max_size() << std::endl;
    std::cout << "============================ END ============================" << std::endl;
    return (0);
}

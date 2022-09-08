#include "vector.hpp"

# define T1 int
# define T2 char
# define T3 std::string

# define VT0 ft::vector< T1 >
# define VT1 ft::vector< VT0 >
# define VT2 ft::vector< VT1 >
# define VT3 ft::vector< VT2 >
# define VT4 ft::vector< VT3 >
# define VT5 ft::vector< VT4 >
# define VT6 ft::vector< VT5 >

typedef size_t size_type;

# define CONTAINER ft::vector<T1>

VT0 simple_vector(size_type s)
{
    VT0 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(i);
    return v;
}

VT1 vector_t1(size_type s)
{
    VT1 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(simple_vector(s));
    return v;
}
VT2 vector_t2(size_type s)
{
    VT2 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(vector_t1(s));
    return v;
}
VT3 vector_t3(size_type s)
{
    VT3 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(vector_t2(s));
    return v;
}
VT4 vector_t4(size_type s)
{
    VT4 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(vector_t3(s));
    return v;
}
VT5 vector_t5(size_type s)
{
    VT5 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(vector_t4(s));
    return v;
}
VT6 vector_t6(size_type s)
{
    VT6 v;
    for (size_type i = 0 ; i < s ; i++)
        v.push_back(vector_t5(s));
    return v;
}

int main(void)
{
    VT6   what = vector_t6(10);

    std::cout << what.size() << std::endl;
    std::cout << what.max_size() << std::endl;
    return (0);
}

#include <iostream>
#include <vector>
// #include "vector.hpp"
#include "../container_stn/vector/vector.hpp"

#ifndef NS
#define NS std
#endif

typedef struct                s_all
{
    std::string                  a;
    long int                     h;
    long double                  p;
    wchar_t                      d;
    signed char                  e;
    char                         c;
    unsigned short int           k;
    int                          g;
    double                       o;
    unsigned long long int       n;
    long long int                i;
    unsigned char                j;
    short int                    f;
    unsigned int                 l;
    bool                         b;
    unsigned long int            m;
}                            t_all;

long int                     h;
long double                  p;
wchar_t                      d;
signed char                  e;
char                         c;
unsigned short int           k;
int                          g;
double                       o;
unsigned long long int       n;
long long int                i;
unsigned char                j;
short int                    f;
unsigned int                 l;
bool                         b;
unsigned long int            m;

int vint;
short vshort;
float vfloat;
std::string vstr;
long long vlong;
t_all vall;

#define __test__(X) \
X(h); \
X(p); \
X(d); \
X(e); \
X(c); \
X(k); \
X(g); \
X(o); \
X(n); \
X(i); \
X(j); \
X(f); \
X(l); \
X(b); \
X(m);

template < typename T >
void	print_vector(T *v)
{
	typename T::iterator it = (*v).begin();
	typename T::const_iterator itend = (*v).end();

    if (it == itend)
        return ;

	std::cout << "\033[32;01m";
	for (; it != itend; it++)
		std::cout << "[" << *it << "]";
	std::cout << "\033[0m" << std::endl;
}

// ################################################################################ //

template < typename T >
void test__contructor_default(T _) {
    NS::vector<T> toto; print_vector(&toto);
}


template < typename T >
void test__contructor_fill(T _) {
    for (int i = 0 ; i <= 10 ; i++)
        for (int j = -10 ; j <= 10 ; j++)
            { NS::vector<T> toto(i, j); print_vector(&toto); }
}


template < typename T >
void test__contructor_range(T _) {
    for (int j = 0 ; j <= 10 ; j++)
        { NS::vector<T> toto(j); print_vector(&toto); }
}

template < typename T >
void test__contructor_copy(T _) {
    for (int j = 0 ; j <= 10 ; j++)
        {
            NS::vector<T> toto(j); print_vector(&toto);
            NS::vector<T> tata(toto); print_vector(&tata);
        }
    for (int i = 0 ; i <= 10 ; i++)
        for (int j = -10 ; j <= 10 ; j++)
        {
            NS::vector<T> toto(i, j); print_vector(&toto);
            NS::vector<T> tata(toto); print_vector(&tata);
        }
}


template < typename T >
void test__begin(T _) {
    {NS::vector<T> toto(2); std::cout << *toto.begin() << std::endl; print_vector(&toto);
    toto.insert(toto.begin(), 42); std::cout << *toto.begin() << std::endl; print_vector(&toto);
    toto.push_back(21); std::cout << *toto.begin() << std::endl; print_vector(&toto);
    toto.clear(); std::cout << *toto.begin() << std::endl; print_vector(&toto);}

    // {NS::vector<const T> toto(2); std::cout << *toto.begin() << std::endl;
    // toto.insert(toto.begin(), 42); std::cout << *toto.begin() << std::endl;
    // toto.push_back(21); std::cout << *toto.begin() << std::endl;
    // toto.clear(); std::cout << *toto.begin() << std::endl;}
}

template < typename T >
void test__end(T _) {
    {NS::vector<T> toto(2); std::cout << *toto.end() << std::endl; print_vector(&toto);
    toto.insert(toto.begin(), 42); std::cout << *toto.end() << std::endl; print_vector(&toto);
    toto.push_back(21); std::cout << *toto.end() << std::endl; print_vector(&toto);
    toto.clear(); std::cout << *toto.end() << std::endl; print_vector(&toto);}

    // {NS::vector<const T> toto(2); std::cout << *toto.end() << std::endl;
    // toto.insert(toto.end(), 42); std::cout << *toto.end() << std::endl;
    // toto.push_back(21); std::cout << *toto.end() << std::endl;
    // toto.clear(); std::cout << *toto.end() << std::endl;}
}

template < typename T >
void test__rbegin(T _) {
    {NS::vector<T> toto(2); std::cout << *toto.end() << std::endl; print_vector(&toto);
    toto.insert(toto.begin(), 42); std::cout << *toto.end() << std::endl; print_vector(&toto);
    toto.push_back(21); std::cout << *toto.end() << std::endl; print_vector(&toto);
    toto.clear(); std::cout << *toto.end() << std::endl; print_vector(&toto);}
}

template < typename T >
void test__rend(T _) {
    {NS::vector<T> toto(2); std::cout << *toto.begin() << std::endl; print_vector(&toto);
    toto.insert(toto.begin(), 42); std::cout << *toto.begin() << std::endl; print_vector(&toto);
    toto.push_back(21); std::cout << *toto.begin() << std::endl; print_vector(&toto);
    toto.clear(); std::cout << *toto.begin() << std::endl; print_vector(&toto);}
}

template < typename T >
void test__size(T _) {
    {NS::vector<T> toto(2); print_vector(&toto);
    std::cout << toto.size() << std::endl;}
    {NS::vector<T> toto; print_vector(&toto);
    std::cout << toto.size() << std::endl;}
    {NS::vector<T> toto(10, 20); print_vector(&toto);
    std::cout << toto.size() << std::endl;}
}

template < typename T >
void test__max_size(T _) {
    {NS::vector<T> toto(10, 20); print_vector(&toto);
    std::cout << toto.max_size() << std::endl;}
    {NS::vector<T> toto; print_vector(&toto);
    std::cout << toto.max_size() << std::endl;}
    {NS::vector<T> toto(5); print_vector(&toto);
    std::cout << toto.max_size() << std::endl;}
}

template < typename T >
void test__resize(T _) {}

template < typename T >
void test__capacity(T _) {
    T a[20] = { 0,1,2,3,4,5,6,7,8,9,10,20,35,89,741,2587,258895,65156651,65165165165,6516516516516516 };
    for (int i = 0 ; i < 20 ; i++)
    {
        try
        {
            NS::vector<T> toto(a[i]);
            // print_vector(&toto);
            std::cout << toto.max_size() << "" << toto.capacity() << std::endl;
            toto.clear()
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // {NS::vector<T> toto(10, 20); print_vector(&toto);
    // std::cout << toto.capacity() << std::endl;}
    // {NS::vector<T> toto; print_vector(&toto);
    // std::cout << toto.capacity() << std::endl;}
    // {NS::vector<T> toto(5); print_vector(&toto);
    // std::cout << toto.capacity() << std::endl;}
}

template < typename T >
void test__empty(T _) {
    {NS::vector<T> toto(10, 20); print_vector(&toto);
    std::cout << toto.empty() << std::endl;}
    {NS::vector<T> toto; print_vector(&toto);
    std::cout << toto.empty() << std::endl;}
    {NS::vector<T> toto(5); print_vector(&toto);
    std::cout << toto.empty() << std::endl;}
}

template < typename T >
void test__reserve(T _) {}

template < typename T >
void test__at(T _) {}

template < typename T >
void test__front(T _) {
    {
        // std::cout << "line: " << __LINE__ << std::endl;
        NS::vector<T> toto(2); std::cout << toto.front() << std::endl; print_vector(&toto);
        toto.insert(toto.begin(), 42); std::cout << toto.front() << std::endl; print_vector(&toto);
        toto.push_back(21); std::cout << toto.front() << std::endl; print_vector(&toto);
        toto.clear(); std::cout << toto.front() << std::endl; print_vector(&toto);
    }
}

template < typename T >
void test__back(T _) {
    {
        NS::vector<T> toto(2); std::cout << toto.back() << std::endl; print_vector(&toto);
        toto.insert(toto.begin(), 42); std::cout << toto.back() << std::endl; print_vector(&toto);
        toto.push_back(21); std::cout << toto.back() << std::endl; print_vector(&toto);
    }
}

template < typename T >
void test__assign(T _) {}

template < typename T >
void test__push_back(T _) {
    {
        NS::vector<T> toto(2); print_vector(&toto);
        toto.insert(toto.begin(), 42); print_vector(&toto);
        toto.push_back(21); print_vector(&toto);
        toto.push_back(0); print_vector(&toto);
        toto.push_back(12); print_vector(&toto);
        toto.push_back(-23); print_vector(&toto);
    }
}

template < typename T >
void test__pop_back(T _) {
    {
        NS::vector<T> toto(2); print_vector(&toto);
        toto.insert(toto.begin(), 42); print_vector(&toto);
        toto.push_back(21); print_vector(&toto);
        toto.push_back(0); print_vector(&toto);
        toto.push_back(12); print_vector(&toto);
        toto.push_back(-23); print_vector(&toto);
        toto.pop_back(); print_vector(&toto);
        toto.pop_back(); print_vector(&toto);
    }
}

template < typename T >
void test__insert(T _) {}

template < typename T >
void test__erase(T _) {}

template < typename T >
void test__swap(T _) {}

template < typename T >
void test__clear(T _) {
    {
        NS::vector<T> toto(2); print_vector(&toto);
        std::cout << toto.size() << std::endl;
        std::cout << toto.capacity() << std::endl;
        toto.insert(toto.begin(), 42); print_vector(&toto);
        toto.push_back(21); print_vector(&toto);
        std::cout << toto.size() << std::endl;
        std::cout << toto.capacity() << std::endl;
        toto.push_back(0); print_vector(&toto);
        toto.push_back(12); print_vector(&toto);
        toto.push_back(-23); print_vector(&toto);
        std::cout << toto.size() << std::endl;
        std::cout << toto.capacity() << std::endl;
        toto.pop_back(); print_vector(&toto);
        toto.pop_back(); print_vector(&toto);
        toto.clear(); print_vector(&toto);
        std::cout << toto.size() << std::endl;
        std::cout << toto.capacity() << std::endl;

    }
}

template < typename T >
void test__get_allocator(T _) {}


template < typename T >
void test__operator_1(T _) // []
{}

template < typename T >
void test__operator_2(T _) // ==
{}

template < typename T >
void test__operator_3(T _) // !=
{}

template < typename T >
void test__operator_4(T _) // <
{}

template < typename T >
void test__operator_5(T _) // >
{}

template < typename T >
void test__operator_6(T _) // <=
{}

template < typename T >
void test__operator_7(T _) // >=
{}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void ptitle(std::string title)
{
    std::cout << "\033[32;01m" << title << ":\033[0m\n" << std::endl;
}

int main(void)
{
    // try { ptitle("test__contructor_default"); __test__(test__contructor_default) } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__contructor_fill");    __test__(test__contructor_fill)    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__contructor_range");   __test__(test__contructor_range)   } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__contructor_copy");    __test__(test__contructor_copy)    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    // try { ptitle("test__begin");              __test__(test__begin)              } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__end");                __test__(test__end)                } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__rbegin");             __test__(test__rbegin)             } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__rend");               __test__(test__rend)               } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__size");               __test__(test__size)               } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__max_size");           __test__(test__max_size)           } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__resize");             __test__(test__resize)             } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    try { ptitle("test__capacity");           __test__(test__capacity)           } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__empty");              __test__(test__empty)              } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__reserve");            __test__(test__reserve)            } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__at");                 __test__(test__at)                 } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__front");              __test__(test__front)              } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__back");               __test__(test__back)               } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__assign");             __test__(test__assign)             } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__push_back");          __test__(test__push_back)          } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__pop_back");           __test__(test__pop_back)           } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__insert");             __test__(test__insert)             } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__erase");              __test__(test__erase)              } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__swap");               __test__(test__swap)               } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__clear");              __test__(test__clear)              } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__get_allocator");      __test__(test__get_allocator)      } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    // try { ptitle("test__operator_1");         __test__(test__operator_1)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__operator_2");         __test__(test__operator_2)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__operator_3");         __test__(test__operator_3)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__operator_4");         __test__(test__operator_4)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__operator_5");         __test__(test__operator_5)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__operator_6");         __test__(test__operator_6)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { ptitle("test__operator_7");         __test__(test__operator_7)         } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    return 0;
}

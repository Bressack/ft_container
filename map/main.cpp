# include "tree.hpp"
# include <ctime>
# include <cstdlib>

struct all
{
    int a;
    int b;
    
    all(int _a, int _b) : a(_a), b(_b) {};
    ~all() {};
};

int main(void)
{
    srand(time(NULL));

    ft::tree<int,all>    t;

    all a(21, 42);
    
    t.push(a);
    
    return (0);
}


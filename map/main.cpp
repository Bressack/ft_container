# include "tree.hpp"
# include <ctime>
# include <cstdlib>

struct all
{
    int a;
    int b;
    int c;
    
    all(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {};
    ~all() {};
};

int main(void)
{
    srand(time(NULL));

    ft::tree<int,all>    t;

    all a(rand(), rand(), rand());
    
    t.push(ft::pair<int,all>(rand(), a));

    t.print_tree();
    
    return (0);
}


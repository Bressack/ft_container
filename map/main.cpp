# include "../others/color.hpp"
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

std::ostream& operator<<(std::ostream& os, const all & a)
{
    os << "[ " << a.a << ", " << a.b << ", " << a.c << " ]";
    return os;
}

int main(void)
{
    srand(time(NULL));

    ft::tree<int,int>    t;

    all a(10, 100, 1000);
    
    for (int i = 0; i < 30000; i++)
    {
        t.push(ft::pair<int,int>(rand(), rand()));
        std::cout << i << std::endl;
    }
    // t.print_tree();
    // t.print_drawer_content();
    
    return (0);
}


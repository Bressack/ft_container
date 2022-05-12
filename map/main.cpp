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
    std::cout << _TEST_ << std::endl;
    
    t.push(ft::pair<int,int>(4, rand()));
    std::cout << _TEST_ << std::endl;
    t.push(ft::pair<int,int>(2, rand()));
    t.print_drawer_content();
    std::cout << _TEST_ << std::endl;
    t.push(ft::pair<int,int>(6, rand()));
    std::cout << _TEST_ << std::endl;
    t.push(ft::pair<int,int>(3, rand()));
    std::cout << _TEST_ << std::endl;
    t.push(ft::pair<int,int>(8, rand()));
    std::cout << _TEST_ << std::endl;
    t.print_tree();
    
    return (0);
}


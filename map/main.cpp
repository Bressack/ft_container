# include "../others/color.hpp"
# include "tree.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>

int main(void)
{
    srand(time(NULL));

    ft::tree<int,int>    t;

    // t.add(ft::pair<int,int>(42, 21));

    // int a[] = { 1,33,17,21,47,25,29,10,7,35,14,50,19,18,37,6,8,9,12,39,24,16,28,13,11,49,41,22,44,30,27,48,34,15,43,46,20,42,40,23,31,4,45,3,38,32,26,2,5,36 };
    int a[] = { 1,3,6,2,8,5,7,9,4,0 };
    // int a[] = { 1,2,3 };

    int len = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < 20; i++)
    {
        t.add(ft::pair<int,int>(i, 0));
        // t.print_tree();
    }

    // t.print_tree();
    bool islegal = t.is_tree_legal();
    std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;
    t.display();
    return (0);
}

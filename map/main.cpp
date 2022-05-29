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
    // int a[] = { 2,4,6,1,8,5,7,9,3,0 };
    int a[] = { 1,2,3 };

    for (int i = 0; i < 3; i++)
    {
        t.add(ft::pair<int,int>(a[i], 0));
        // t.print_tree();
    }

    // t.print_tree();
    t.display();
    return (0);
}

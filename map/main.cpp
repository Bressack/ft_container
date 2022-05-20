# include "../others/color.hpp"
# include "tree.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>


int main(void)
{
    srand(time(NULL));

    ft::tree<int,int>    t;

    t.add(ft::pair<int,int>(42, 21));
    
    // for (int i = 0; i < 3000; i++)
    // {
    //     t.add(ft::pair<int,int>(rand(), rand()));
    //     std::cout << i << std::endl;
    // }
    // t.print_tree();
    // t.print_drawer_content();
    
    return (0);
}


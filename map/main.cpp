# include "../others/color.hpp"
# include "tree.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>

#include <bits/stdc++.h>

typedef int* int_arr;
typedef ft::tree<int,int> tree_type;


// Shuffle array
void shuffle_array(int * arr, int n, unsigned int seed = 0)
{ std::shuffle(arr, arr + n, std::default_random_engine(seed)); }

void    info(tree_type & t)
{
    std::cout << "info: emtpy: " << t.empty() << ", size: " << t.size() << ", infix: ";
    t.infix_content_print();
    std::cout << "\nmax_size: " << t.max_size() << std::endl;
}

int main(void)
{
    srand(time(NULL));

    tree_type    t;

    info(t);

    # define LEN 40

    int a[LEN] = { 0 };
    for (int i = 0 ; i < LEN ; i++) { a[i] = i; }
    for (int i = 0 ; i < LEN ; i++) { std::cout << a[i] << ','; }
    std::cout << std::endl;
    shuffle_array(a, LEN, 42);
    for (int i = 0 ; i < LEN ; i++) { std::cout << a[i] << ','; }
    std::cout << std::endl;
    std::cout << "debug: " << __LINE__ << std::endl;

    // int len = sizeof(a) / sizeof(a[0]);
    // bool islegal;

    for (int i = 0 ; i < LEN ; i++)
    {
        std::cout << "=================================================" << std::endl;
        info(t);
        t.insert(a[i], 0);
        info(t);
        std::cout << "=================================================" << std::endl;
    }
    info(t);
    // t.display();
    int key = 20;
    std::cout << "debug: " << __LINE__ << std::endl;
    t.remove(key);
    // info(t);
    t.display();

    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;
    // t.display();
    return (0);
}

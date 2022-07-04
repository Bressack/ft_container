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
    std::cout << "info: empty: " << t.empty() << ", size: " << t.size() << ", infix: ";
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

    printf(C_G_GREEN "insert loop begin\n" C_RES);
    for (int i = 0 ; i < LEN ; i++)
    {
        printf(C_G_GREEN "insert loop -> %d\n" C_RES, a[i]);
        // std::cout << "=================================================" << std::endl;
        // info(t);
        t.insert(a[i], 0);
        // info(t);
        // std::cout << "=================================================" << std::endl;
    }
    // info(t);
    // t.display();
    int key;
    t.display("node_20");
    key = 20; t.remove(key);
    t.display("node_13"); std::cout << "debug: " << __LINE__ << std::endl;
    key = 13; t.remove(key);
    t.display("node_2");  std::cout << "debug: " << __LINE__ << std::endl;
    key = 2; t.remove(key);
    t.display("node_33"); std::cout << "debug: " << __LINE__ << std::endl;
    key = 33; t.remove(key);
    t.display("node_23"); std::cout << "debug: " << __LINE__ << std::endl;
    key = 23; t.remove(key);
    t.display("end"); std::cout << "debug: " << __LINE__ << std::endl;

    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;
    // t.display();
    return (0);
}

# include "../others/color.hpp"
# include "tree.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>

#include <bits/stdc++.h>

typedef int* int_arr;

// Shuffle array
void shuffle_array(int * arr, int n, unsigned int seed = 0)
{ std::shuffle(arr, arr + n, std::default_random_engine(seed)); }

void    info(ft::tree<int,int> & t)
{
    std::cout << "info: emtpy: " << t.empty() << ", size: " << t.size() << ", infix: ";
    t.infix_content_print();
    std::cout << "\nmax_size: " << t.max_size() << std::endl;
}

int main(void)
{
    srand(time(NULL));

    ft::tree<int,int>    t;

    info(t);
    // int a[] = { 1,33,17,21,47,25,29,10,7,35,14,50,19,18,37,6,8,9,12,39,24,16,28,13,11,49,41,22,44,30,27,48,34,15,43,46,20,42,40,23,31,4,45,3,38,32,26,2,5,36 };
    // int a[] = { 1,3,6,2,8,5,7,9,4,0 };
    // int a[] = { 1,2,3 };

    std::cout << "debug: " << __LINE__ << std::endl;
    # define LEN 40

    int a[LEN] = { 0 };
    for (int i = 0 ; i < LEN ; i++) { a[i] = i; }
    shuffle_array(a, LEN, 42);
    std::cout << "debug: " << __LINE__ << std::endl;

    // int len = sizeof(a) / sizeof(a[0]);
    bool islegal;

    for (int i = 0 ; i < LEN ; i++)
    {
        t.insert(a[i], 0);
    }
    info(t);
    int key = 1;
    std::cout << "debug: " << __LINE__ << std::endl;
    t.remove(key);
    info(t);

    // int ind = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     ind = rand() % len;
    //     std::cout << "[ CREATE ] i:" << i << "|" << ind << std::endl;
    //     a[i] = ind;
    // }
    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;

    // shuffle_array(&a[0], len);

    // for (int i = 0; i < len; i++)
    // {
    //     ind = rand() % len;
    //     std::cout << "[ INSERT ] i:" << i << "|" << ind << std::endl;
    //     t.add(ft::pair<int,int>(ind, 0));
    // }
    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;


    // for (int i = 0; i < len; i++)
    // {
    //     ind = rand() % len;
    //     std::cout << "[ REMOVE ] i:" << i << "|" << ind << std::endl;
    //     t.remove_node(ft::pair<int,int>(ind, 0));
    // }
    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;

    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;
    t.display();
    return (0);
}

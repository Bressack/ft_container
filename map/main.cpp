# include "../others/color.hpp"
# include "tree.hpp"
# include <ctime>
# include <cstdlib>
# include <vector>
# include <iostream>

#include <bits/stdc++.h>

typedef int* int_arr;
typedef ft::tree<int,int> tree_type;


// Shuffle array
void shuffle_array(int * arr, int n, unsigned int seed = 0)
{ std::shuffle(arr, arr + n, std::default_random_engine(seed)); }

void    info(tree_type & t)
{
    std::cout << "info: {" << std::endl;
    std::cout << "    " << "empty        : " << std::string(t.empty() ? "True" : "False") << std::endl;
    std::cout << "    " << "size         : " << t.size() << std::endl;
    std::cout << "    " << "max_size     : " << t.max_size() << std::endl;
    std::cout << "    " << "infix content: ";
    t.infix_content_print();
    std::cout << std::endl;
    std::cout << "    " << "is_tree_legal: ";
    t.is_tree_legal();
    std::cout << std::endl;
    std::cout << "}" << std::endl;
    // std::cout << "info: empty: " << std::string(t.empty() ? "True" : "False") << ", size: " << t.size() << ", infix: ";
    // t.infix_content_print();
    // std::cout << "\nmax_size: " << t.max_size() << std::endl;
}

bool    history_query(std::vector<int> & history, int n)
{
    std::vector<int>::iterator it = history.begin();
    for (; it != history.end(); ++it)
    {
        if (*it == n)
            return true;
    }
    return false;
}

int    pop_history(std::vector<int> & history)
{
    int n = std::rand() % (history.size() - 1);
    std::vector<int>::iterator it = history.begin();
    for (int i = 0 ; i < n ; i++)
        it++;
    int ret = *it;
    history.erase(it);
    return ret;
}

void    siege()
{
    std::vector<int>    history;
    tree_type           t;
    int n = 0;
    int start = 10;

    std::cout << "tree is now under siege:" << std::endl;
    int gen = 0;
    while (1)
    {
        std::vector<int>::iterator it = history.begin();
        std::cout << C_G_YELLOW << "history: ";
        for (; it != history.end(); ++it)
            std::cout << *it << " ";
        std::cout << C_RES << std::endl;
        info(t);
        if (start > 0 || history.size() == 0 || std::rand() % 2)
        { // INSERT
            while (1)
            {
                n = std::rand() % 1000;
                if (history_query(history, n) == false)
                    break;
            }
            history.push_back(n);
            std::cout << SKY_BLUE << "[ inserting " << CORAIL << n << SKY_BLUE << " ]" << C_RES << std::endl;
            t.insert(n, 0);
            start--;
        }
        else
        { // REMOVE
            n = pop_history(history);
            std::cout << ORANGE << "[ removing " << CORAIL << n << ORANGE << " ]" << C_RES << std::endl;
            t.remove(n);
        }
        // t.display(std::to_string(gen).c_str());
        gen++;
    }
}

int main(void)
{
    srand(time(NULL));

    tree_type    t;

    info(t);

    siege();
    return (0);
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
    info(t);
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
    t.display("node_23"); std::cout << "debug: " << __LINE__ << std::endl;
    key = 23; t.remove(key);
    t.display("end"); std::cout << "debug: " << __LINE__ << std::endl;
    info(t);
    for (int i = 0; i < LEN; i++) {
        std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
        t.remove(i);
        info(t);
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    }
    info(t);
    // islegal = t.is_tree_legal();
    // std::cout << (islegal ? "Tree is legal" : "Tree is illegal (some nodes are not reachable)") << std::endl;
    // t.display();
    return (0);
}

# include "tree.hpp"
# include <ctime>
# include <cstdlib>

int main(void)
{
    srand(time(NULL));

    ft::tree<int,int>    t;

    t.push(rand(), rand());
    return (0);
}


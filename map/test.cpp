#include <iostream>

class toto
{
    public:
        int fun(int & i)
        {
            i = 42;
            return i;
        }

        void    fun1(int(toto::*f)(int &))
        {
            int k = 21;
            std::cout << k << std::endl;
            (this->*f)(k);
            if (k == 35345)
                fun1(f);
            std::cout << k << std::endl;
        }

        void call(void)
        {
            fun1(&toto::fun);
        }
};
            // infix_apply = fun1
            // infix_content_print = call
            // __content_print = fun

int main(void)
{
    toto t;

    t.call();
    return 0;
}


int main(void)
{
    int a = 10;
    int b = 42;
    int j = 0;

    for (int i = 0; i < 1000000000; i++)
    {
        if (a - b < 0)
            j++;
    }
    return 0;
}

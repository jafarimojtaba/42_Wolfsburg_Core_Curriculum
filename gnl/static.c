#include <stdio.h>
void ft_print(int i)
{
    static int c;

    c++;
    printf("%d \n", c);
}

int main()
{
    for(int i = 20; i<41; i++)
    {
        ft_print(i);
    }
    return 0;
}
#include <stdio.h>

int add(int a, int b)
{
    return a+b;
}

int main()
{
    int num1;
    
    num1 = add(10,20);

    printf("%d\n",num1);

    return 0;
}
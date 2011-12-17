#include<stdio.h>

int fib(int n)
{
    int a = 0, b = 1;
    while(n--)b += a, a = b - a;
    return a;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}

#include<stdio.h>

int putbin(int n)
{
    if(n) putbin(n>>1), putc('0' + (n&1), stdout);
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    putbin(n);
    return 0;
}

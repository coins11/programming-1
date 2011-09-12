#include<stdio.h>

int input(char *string, int *p)
{
    fputs(string, stdout);
    return scanf("%d", p);
}

int main(void)
{
    int base, height;
    input("input base: ", &base);
    input("input height: ", &height);
    printf("area = %d\n", base * height / 2);
    return 0;
}


#include<stdio.h>

int main(void)
{
    int n, digits = 0;
    scanf("%d", &n);
    while(n){
        digits++;
        n = n/10;
    }
    printf("%d\n", digits);
    return 0;
}

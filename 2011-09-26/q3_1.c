
#include<stdio.h>

int main(void)
{
    int i = 50, sum = 0;
    while(i <= 100){
        sum += i;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}

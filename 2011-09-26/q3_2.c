
#include<stdio.h>

int main(void)
{
    int i = 0, arr[10];
    printf("input 10 numbers");
    while(i != 10){
        scanf("%d", &arr[i]);
        i++;
    }
    i = 0;
    while(i != 10){
        printf("%d ", arr[9-i]);
        i++;
    }
    printf("\n");
    return 0;
}

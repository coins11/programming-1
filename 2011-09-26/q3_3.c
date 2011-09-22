
#include<stdio.h>

int main(void)
{
    int i = 0, arr[10], min, max;
    printf("input 10 numbers");
    while(i != 10){
        scanf("%d", &arr[i]);
        i++;
    }
    i = 1;
    min = max = arr[0];
    while(i != 10){
        if(min > arr[i]) min = arr[i];
        if(max < arr[i]) max = arr[i];
        i++;
    }
    printf("min: %d\nmax: %d\n", min, max);
    return 0;
}

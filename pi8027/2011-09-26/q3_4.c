
#include<stdio.h>

int main(void)
{
    int i = 0, arr_a[10], arr_b[10];
    while(i != 10){
        scanf("%d", &arr_a[i]);
        i++;
    }
    i = 0;
    while(i != 10){
        scanf("%d", &arr_b[i]);
        i++;
    }
    i = 0;
    while(i != 10){
        int j = 0;
        while(j != 10){
            if(arr_a[i] == arr_b[j]){
                printf("%d ", arr_a[i]);
                break;
            }
            j++;
        }
        i++;
    }
    return 0;
}

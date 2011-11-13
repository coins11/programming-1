#include<stdio.h>
#include<stdlib.h>

typedef struct data {
    char name[10];
    int score;
} data_t;

int compare(const void *a, const void *b)
{
    return ((data_t *)a)->score - ((data_t *)b)->score;
}

int main(void)
{
    data_t arr[20];
    size_t i = 0;
    while(i != 20){
        scanf("%s %d", arr[i].name, &arr[i].score);
        i++;
    }
    qsort(arr, 20, sizeof(data_t), compare);
    i = 0;
    while(i != 20){
        printf("%s %d\n", arr[i].name, arr[i].score);
        i++;
    }
    return 0;
}

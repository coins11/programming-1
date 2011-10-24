#include<stdio.h>

int main(void)
{
    int a[5][5] ,b[5][5] ,c[5][5];
    int i, j, k;
    for(i = 0; i != 2; i++){
        for(j = 0; j != 5; j++){
            for(k = 0; k != 5; k++) scanf("%d", &(i ? b : a)[j][k]);
        }
    }
    for(i = 0; i != 5; i++){
        for(j = 0; j != 5; j++){
            c[i][j] = 0;
            for(k = 0; k != 5; k++) c[i][j] += a[i][k] * b[k][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

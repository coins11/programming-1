#include<stdio.h>

int main(void)
{
    int temp, i, j, n, sum[3] = {0, 0, 0};
    scanf("%d", &n);
    for(i = 0; i != n; i++){
        for(j = 0; j != 3; j++){
            scanf("%d", &temp);
            sum[j] += temp;
        }
    }
    printf("%d %d %d\n", sum[0]/n, sum[1]/n, sum[2]/n);
    return 0;
}

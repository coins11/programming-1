#include <stdio.h>

int main(void)
{
    char table[1001];
    size_t i, j;
    for(i = 0; i != 1001; i++) table[i] = 2 <= i;
    for(i = 0; i != 1001; i++){
        if(table[i]){
            for(j = i*2; j < 1001; j += i) table[j] = 0;
            printf("%d\n", (int)i);
        }
    }
    return 0;
}

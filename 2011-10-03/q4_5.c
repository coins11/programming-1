#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int arr[10];
    int i = 0;
    memset(arr, 0, sizeof(arr));
    while(1){
        char c = getc(stdin);
        if(ferror(stdin)){
            return -1;
        }
        else if(c == EOF){
            break;
        }
        else if('0' <= c && c <= '9'){
            arr[c-'0']++;
        }
    }
    while(i != 10){
        printf("%d: %d\n", i, arr[i]);
        i++;
    }
    return 0;
}

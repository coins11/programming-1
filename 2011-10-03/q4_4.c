#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    while(1){
        char c = getc(stdin);
        if(ferror(stdin)){
            return -1;
        }
        else if(c == EOF){
            break;
        }
        else if('A' <= c && c <= 'Z'){
            n++;
        }
    }
    printf("%d\n", n);
    return 0;
}

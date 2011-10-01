#include <stdio.h>
#include <stdlib.h>

int revputs(char *str, FILE *output)
{
    size_t i = 0;
    while(str[i]){
        i++;
    }
    while(i){
        i--;
        putc(str[i], output);
    }
    return 0;
}

int main(void)
{
    char *buf = NULL;
    size_t len = 0;
    while(1){
        char c;
        if(len%32 == 0){
            char *temp = realloc(buf, len+32);
            if(!temp){
                free(buf);
                return -1;
            }
            buf = temp;
        }
        c = getc(stdin);
        if(ferror(stdin)){
            return -1;
        }
        else if(c == EOF){
            buf[len] = '\0';
            break;
        }
        else{
            buf[len] = c;
        }
        len++;
    }
    revputs(buf, stdout);
    putc('\n', stdout);
    return 0;
}

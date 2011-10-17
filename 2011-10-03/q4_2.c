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

char *fgetline(FILE *input)
{
    char *buf = NULL;
    size_t iter = 0;
    while(1){
        char *temp = realloc(buf, (iter + 1) * 32 + 1);
        if(!temp){
            free(buf);
            return NULL;
        }
        buf = temp;
        fgets(&buf[iter * 32], 32 + 1, input);
        if(ferror(stdin)){
            free(buf);
            return NULL;
        }
        {
            size_t len = strlen(&buf[iter * 32]);
            if(len != 32){
                if(buf[iter * 32 + len - 1] == '\n'){
                    buf[iter * 32 + len - 1] = '\0';
                }
                return buf;
            }
        }
        iter++;
    }
}

int main(void)
{
    char *buf = fgetline(stdin);
    if(buf){
        revputs(buf, stdout);
        putc('\n', stdout);
    }
    return 0;
}

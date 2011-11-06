#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
            if(buf[iter * 32 + len - 1] == '\n'){
                buf[iter * 32 + len - 1] = '\0';
                return buf;
            }
            if(len != 32){
                return buf;
            }
        }
        iter++;
    }
}

char *strfilter(char *src, char c)
{
    char *dest = NULL;
    size_t si = 0, di = 0;
    while(1){
        if(src[si] != c){
            if(!(di & 31)){
                char *temp = realloc(dest, di + 32);
                if(!temp){
                    free(dest);
                    return NULL;
                }
                dest = temp;
            }
            dest[di] = src[si];
            di++;
        }
        if(src[si] == '\0'){
            return dest;
        }
        si++;
    }
}

int main(void)
{
    char *str1 = fgetline(stdin);
    if(str1){
        char c = fgetc(stdin);
        char *str2 = strfilter(str1, c);
        if(str2){
            fputs(str2, stdout);
            fputc('\n', stdout);
            free(str2);
        }
        free(str1);
    }
    return 0;
}

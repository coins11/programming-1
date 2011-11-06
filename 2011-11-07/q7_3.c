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

int string_compare(const char *str1, const char *str2)
{
    size_t iter = 0;
    while(1){
        if(str1[iter] == '\0' && str2[iter] == '\0'){
            return 1;
        }
        if(str1[iter] != str2[iter]){
            return 0;
        }
        iter++;
    }
}

int main(void)
{
    char *str1 = fgetline(stdin);
    char *str2 = fgetline(stdin);
    if(str1 && str2){
        if(string_compare(str1, str2)){
            fputs("The first input is equivalent to the second input.\n",
                stdout);
        }
        else{
            fputs("The First input isn\'t equivalent to the second input.\n",
                stdout);
        }
    }
    free(str1);
    free(str2);
    return 0;
}

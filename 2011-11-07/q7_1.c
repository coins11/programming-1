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

char *string_cotcat(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1), len2 = strlen(str2);
    char *result = malloc(len1+len2+1);
    if(result){
        memcpy(result, str1, len1);
        memcpy(result+len1, str2, len2);
        result[len1+len2] = '\0';
    }
    return result;
}

int main(void)
{
    char *str1 = fgetline(stdin);
    char *str2 = fgetline(stdin);
    if(str1 && str2){
        char *result = string_cotcat(str1, str2);
        if(result){
            fputs(result, stdout);
            fputc('\n', stdout);
            free(result);
        }
    }
    free(str1);
    free(str2);
    return 0;
}

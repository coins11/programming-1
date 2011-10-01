#include <stdio.h>

int main(void)
{
    char c = getc(stdin);
    putc('A' <= c && c <= 'J' ? '0' + c - 'A' : c , stdout);
    putc('\n', stdout);
    return 0;
}

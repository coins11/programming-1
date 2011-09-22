
#include <stdio.h>

int main(void)
{
    int a, b;
    printf("A? ");
    scanf("%d", &a);
    printf("B? ");
    scanf("%d", &b);
    printf(a%b ? "%dは%dの約数ではありません。" : "%dは%dの約数です。", b, a);
    return 0;
}

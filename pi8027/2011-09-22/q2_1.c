
#include <stdio.h>

int main(void)
{
    int n;
    printf("input number: ");
    scanf("%d", &n);
    printf(n&1 ? "odd\n" : "even\n");
    return 0;
}

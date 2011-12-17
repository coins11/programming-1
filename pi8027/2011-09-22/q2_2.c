
#include <stdio.h>

int main(void)
{
    int n;
    printf("input number (0 <= n <= 100): ");
    scanf("%d", &n);
    printf((0 <= n && n <= 100) ? (50 <= n ? "A\n" : "B\n") : "error\n");
    return 0;
}

#include <stdio.h>

int ack(int m, int n)
{
    return !m ? n + 1
         : !n ? ack(m - 1, 1)
         : ack(m - 1, ack(m, n - 1));
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n", ack(m, n));
    return 0;
}

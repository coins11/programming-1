#include<stdio.h>

int solve(float a1, float b1, float a2, float b2, float *x, float *y)
{
    if(a1*b2 == a2*b1){
        return 0;
    }
    *x = (b2-b1)/(a1*b2-a2*b1);
    *y = (a1-a2)/(a1*b2-a2*b1);
    return 1;
}

int main(void)
{
    float a1, b1, a2, b2, x, y;
    int r;
    scanf("%f %f %f %f", &a1, &b1, &a2, &b2);
    r = solve(a1, b1, a2, b2, &x, &y);
    if(r){
        printf("%f %f\n", x, y);
    }
    return 0;
}

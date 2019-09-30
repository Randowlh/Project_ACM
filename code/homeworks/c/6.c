#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    scanf("%lf",&x);
    if(x<=15&&x>0)
        y=4*x/3;
    else
        y=2.5*x-10.5;
    printf("f(%.2f) = %.2f",x,y);
    return 0;
}
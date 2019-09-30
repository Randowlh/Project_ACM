#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    scanf("%d",&a);
    if(a<1000&&a>99)
    {
        b=a%10;
        c=(a/10)%10;
        d=a/100;
    if(a==b*b*b+c*c*c+d*d*d)
        printf("Yes");
    else
        printf("No");}
    else
        printf("Invalid Value!");
        return 0;
}
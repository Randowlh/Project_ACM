#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    scanf("%2d-%2d-%4d",&a,&b,&c);
    
    printf("%4d-%02d-%02d",c,a,b);
    return 0;
}
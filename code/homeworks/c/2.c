#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f,g;
    scanf("%2d%2d %2d%d",&a,&b,&c,&d);
    e=a*60+b;
    f=c*60+d;
    g=f-e;
    b=g%60;
    a=(g-b)/60;
    printf("%02d:%02d",a,b);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%1d",&a);
    if(a>=1&&a<6)
        a+=2;
    else if(a==6)
        a=1;
    else a=2;
    printf("%d",a);
    return 0;
}


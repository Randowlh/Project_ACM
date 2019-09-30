#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,x;
    scanf("%d",&a);
    if(a<=1000)
    {
        x=a%5;
        if(x<=3&&x>0)
        printf("Fishing in day %d",a);
        else
        printf("Drying in day %d",a);
 } 
 return 0;
}

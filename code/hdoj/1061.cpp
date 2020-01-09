#include <stdio.h>
#include <string.h>
#include<math.h>
int main()
{
    int a,d2=0,d3=0,d5=0,d7=0,sum,i,j,m,n,str[20]={0,1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9};
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0; i<m; i++)
        {
            scanf("%d",&n);
            n=n%20;
            printf("%d\n",str[n]);
        }
    }
}
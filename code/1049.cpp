#include "iostream"
#include "stdio.h"
using namespace std;
int w[10500],val[10500];
int dp[100500];
int main()
{
    int t,m;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&w[i],&val[i]);
    }
    for(int i=1;i<=m;i++) 
        for(int j=0;j<=t;j++)  
        {
            if(j>=w[i])
            {
                dp[j]=max(dp[j-w[i]]+val[i],dp[j]);
            }  
        }
    printf("%d",dp[t]);
    return 0;
}
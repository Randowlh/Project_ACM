#include "iostream"
#include "stdio.h"
using namespace std;
int w[105],val[105];
int dp[1005];
int main()
{
    int t,m;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&w[i],&val[i]);
    }
    for(int i=1;i<=m;i++) 
        for(int j=t;j>=0;j--)  
        {
            if(j>=w[i])
            {
                dp[j]=max(dp[j-w[i]]+val[i],dp[j]);
            }  
        }
    printf("%d",dp[t]);
    return 0;
}
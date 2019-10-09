#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int map[22][22];
int biao[8][2]={{2,1},{1,2},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
int  m,n,x,y;
unsigned long long dp[22][22];
int main(){
    cin>>n>>m>>x>>y;
    map[x][y]=1;
    for(int i=0;i<8;i++){
        if(x+biao[i][0]>=0&&x+biao[i][0]<=n&&y+biao[i][1]>=0&&y+biao[i][1]<=m){
            map[x+biao[i][0]][y+biao[i][1]]=1;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(map[i][j]==0){
            if(i==0){
                if(j==0)continue;
                else  dp[i][j]=dp[i][j-1];
            }else 
            if (j==0)dp[i][j]=dp[i-1][j];
            else 
            dp[i][j]=max(dp[i][j],dp[i][j-1]+dp[i-1][j]);
        }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
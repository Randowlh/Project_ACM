#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int dp[100][1010];
int map[100][1010];
int check(int i,int j){
    j++;
    int ma=-9999999;
    for(int q=2;q<=j;q++){
        if(j%q==0){
            ma=max(ma,dp[i][j/q-1]);
        }
    }
    return ma;
}
int main(){
    int c;
    cin>>c;
    for(int q=0;q<c;q++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>map[i][j];
            }
        }
        dp[0][0]=map[0][0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+map[i][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i]=max(dp[0][i-1],check(0,i))+map[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=max(dp[i-1][j],max(check(i,j),dp[i][j-1]))+map[i][j];
            }
        }
        cout<<dp[n-1][m-1]<<endl;
    }
    return 0;
}
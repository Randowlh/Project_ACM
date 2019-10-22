#include<cstdio>
#include<iostream>
using namespace std;
int mod=100000007;
int f[2][1000010];
int main(){
    int n,m;
    cin>>n>>m;
    if(n==0||m==0){
        cout<<0<<endl;
        return 0;
    }
    f[1][1]=1;
    f[0][1]=1;
    f[1][2]=2;
    f[0][2]=2;
    for(int i=3;i<=max(n,m);i++){
        f[1][i]=(f[0][i-1]+f[0][i-2])%mod;
        f[0][i]=(f[1][i-1]+f[1][i-2])%mod;
    }
    int ans=(f[1][m]+f[0][m]-2)%mod+(f[1][n]+f[0][n])%mod;
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}
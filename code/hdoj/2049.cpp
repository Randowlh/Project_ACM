#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fac(ll x){
    ll ans=1;
    for(int i=1;i<=x;i++){
        ans=ans*i;
    }
    return ans;
}
ll calc(ll a,ll b){
    ll ans=1;
    ll t=a;
    ll o=1;
    for(int i=1;i<=b;i++){
        ans=ans*t;
        t--;
    }
    for(int i=1;i<=b;i++)
    ans/=i;
    return ans;
}
ll dp[100];
int main(){
    int t;
    cin>>t;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=99;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    for(int q=0;q<t;q++){
        int n,m;
        cin>>n>>m;
        ll ans=1;
        //cout<<calc(n,m)<<endl;
        ans*=calc(n,m);
        ans*=dp[m];
        cout<<ans<<endl;
    }
    return 0;
}
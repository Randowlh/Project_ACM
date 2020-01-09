#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
const int mod =1000000007;
typedef long long ll;
ll fast_pow(ll x, ll y){
    ll ans=1;
    ll tmp=1;
    ll now=x;
    while(tmp<=y){
        ans=ans*now%mod;
        y-=tmp;
        tmp=tmp*2%mod;
        now=now*now%mod;
    }
    if(y!=0){
        ans=ans*fast_pow(x,y)%mod;
    }
    return ans;
}
void work(){
    int n,m;
    cin>>n>>m;
    ll ans=1;
    ll cheng=fast_pow(2,m);
    cheng=(cheng+mod-1)%mod;
    ans=fast_pow(cheng,n);
    cout<<ans<<endl;
    return ;
    
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
   // cin>>t;
    while(t--){
        work();
    }
    return 0;
}
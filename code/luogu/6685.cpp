#include<bits/stdc++.h>
using namespace std;
#define int long long
int pows(int a,int b) {
    int ans=1;
    int now=a;
    while(b){
        if(b&1)
            ans*=now;
        b>>=1;
        now*=now;
    }
    return ans;
}
signed main(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(pow(i,m)<=n)
        ans++;
        else break;
    }
    cout<<ans<<endl;
}
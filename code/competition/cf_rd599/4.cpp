#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll x;
    cin>>x;
    ll tx=x;
    vector<ll> yz;
    yz.clear();
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            while(x%i==0)
            x/=i;
            if(x!=1){
                printf("1\n");
                return;
            }
            yz.push_back(i);
            break;
        }
    }
    if(yz.size()==0){
        cout<<tx<<endl;
    }else if(yz.size()==1){
        cout<<yz[0]<<endl;
    }
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
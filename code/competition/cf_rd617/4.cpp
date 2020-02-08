#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    vector<int> v;
    ll tmp;
    //cout<<"no"<<endl;
    for(int i=0;i<n;i++){
        cin>>tmp;
        tmp%=(a+b);
        if(tmp==0)
        tmp=a+b;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    ll now=0;
    while(k>0){
        if(now>=v.size())
        break;
        if((k+1)*a>=v[now]){
            v[now]-=a;
            if(v[now]<0){
                ans++;
                now++;
                continue;
            }else{
                if(v[now]%a==0){
                    k-=v[now]/a;
                }else k-=(v[now]/a+1);
                now++;
                ans++;
            }
        }else
        {
            break;
        }
    }
    cout<<ans<<endl;
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
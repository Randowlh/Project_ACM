#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[10000];
int tp[10000];
int ed=0;
void fj(int i){
    int now=0;
    while(i!=0){
        if(i&1){
            mp[now]++;
            if(now>ed){
                ed=now;
            }
        }
        i>>=1;
        now++;
    }
}
int zz(int i){
    for(int i=0;i<=ed;i++){
        tp[i]=mp[i];
    }
    int now=0;
    while(i!=0){
        if(i&1){
            tp[now]--;
        }
        i>>=1;
        now++;
    }
    int c=0;
    for(int i=ed;i>=0;i--){
        if(tp[i]!=0){
            c=c|1;
        }
        if(i!=0)
        c<<=1;
    }
   
    return c;
}
void work(){
    int n;
    cin>>n;
    ll tmp;
    vector<ll> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        fj(tmp);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),greater<ll>());
    // for(int i=0;i<=ed;i++){
    //     cout<<mp[i]<<endl;
    // }
    // cout<<endl;
    int mx=-1;
    int mix=-1;
    for(int i=0;i<n;i++){
        int z=zz(v[i]);
        if(mx<(v[i]|z)-z){
            mx=(v[i]|z)-z;
            mix=i;
        }
    }
   // cout<<mx<<endl;
    cout<<v[mix]<<' ';
    for(int i=0;i<n;i++){
        if(i!=mix){
            cout<<v[i]<<' ';
        }
    }
    cout<<endl;
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
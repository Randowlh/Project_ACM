#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
map<ll,ll> M;
void work(){
    ll n,m;
    cin>>n>>m;
    ll tol=0;
    vector<int>  v;
    int tmp;
    for(int i=0;i<m;i++){
        scanf("%d",&tmp);
        v.push_back(tmp);
        tol+=tmp;
    } 
    if(tol<n){
        cout<<-1<<endl;
        return;
    }
    if(tol==n){
        cout<<0<<endl;
        return;
    }
    sort(v.begin(),v.end());
    ll tn=n;
    ll to=0;
    for(int i=0;i<v.size(); i++){
        to=i;
        tn-=v[i];
        if(tn==0){
            cout<<0<<endl;
            return;
        }
        if(tn<0)
        break;
    }
    ll t=v[to]-tn;
    ll ans=0;
    vector<int> fj;
    int now=0;
    while(t!=0){
        if(t&1){
            fj.push_back(now);
        }
        now++;
        t>>=1;
    }
    for(int i=0;i<fj.size(); i++){
        ans+=M[v[to]]-fj[i];
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    ll now=1;
    int cnt=0;
    while(now<1000000000){
        M[now]=cnt;
        cnt++;
        now*=2;
    }
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
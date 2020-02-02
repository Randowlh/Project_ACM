#include<bits/stdc++.h>
using namespace std;
const int inf =10000000;
typedef long long ll;
ll n,m,k,d;
ll dis[110][1100];
ll mp[1100][1100];
ll read(string a){
    ll ans=0;
    int fl=0;
    if(a[0]=='G'){
        fl=1;
    }
    for(int i=0+fl;i<a.size();i++){
        ans*=10;
        ans+=a[i]-'0';
    }
    if(fl)
    ans+=n;
    return ans;
}
ll dij(int s){
    int c=s-n;
    memset(dis[c],inf,sizeof(dis[c]));
    dis[c][s]=0;
    bool fl[1100];
    memset(fl,true,sizeof(fl));
    int flag=1;
    while(true){
        flag=1;
        ll mx=inf+100;
        int mix=-1;
        for(int i=0;i<=n+m;i++){
            if(dis[c][i]<mx&&fl[i]){
                mx=dis[c][i];
                mix=i;
                flag=0;
            }
        }
        if(flag==1)
        break;
        for(int i=0;i<=n+m;i++){
            dis[c][i]=min(dis[c][i],mp[mix][i]+dis[c][mix]);
        }
        fl[mix]=false;
    }
    ll eva=inf;
    for(int i=1;i<=n;i++){
        if(dis[c][i]>d){
            return -1;
        }
        eva=min(dis[c][i],eva);
    }
   // cout<<eva<<' '<<n<<endl;
    //eva/=n;
    return eva;
}
void work(){
    //freopen("in.txt","r",stdin);
    cin>>n>>m>>k>>d;
    for(int i=0;i<=n+m;i++)
    for(int j=0;j<=n+m;j++){
        mp[i][j]=inf;
    }
    for(int i=0;i<=n+m;i++)
    mp[i][i]=inf;
    ll v;
    string su,sw;
    ll u,w;
    for(int i=0;i<k;i++){
        cin>>su>>sw>>v;
        u=read(su);
        w=read(sw);
        mp[u][w]=min(mp[u][w],v);
        mp[w][u]=mp[u][w];
    }
    ll mi=-1;
    ll mix=0;
    for(int i=1+n;i<=m+n;i++){
        ll k=dij(i);
        if(k>mi){
            mi=k;
            mix=i-n;
        }
    }
    if(mix==0){
        cout<<"No Solution"<<endl;
    }else{
        //mix=1;
    cout<<'G'<<mix<<endl;
    double mixx=0;
    for(int i=1;i<=n;i++){
        mixx+=dis[mix][i];
    }
    mixx/=n;
    printf("%.1f %.1f\n",(double)mi,mixx);
    //cout<<endl;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
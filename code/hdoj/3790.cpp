#include<bits/stdc++.h>
using namespace std;
const int inf =1000000;
typedef long long ll;
struct node {
    ll l;
    ll c;
    bool operator<(node a){
        if(l==a.l){
            return c<a.c;
        }else 
        return l<a.l;
    }
    bool operator>(node a){
        if(l==a.l){
            return c>a.c;
        }else 
        return l>a.l;
    }
    node& operator=(node& value)
    {
        l = value.l;
        c = value.c;
        return *this;
    }
    node& operator+(node& value)
    {
        l += value.l;
        c += value.l;
        return *this;
    }
}dis[1010];
struct cmp{
    bool operator()(ll a,ll b){
        return dis[a]>dis[b];
    }
};
ll n,m;
bool flag[1010];
node mp[1010][1010];
void work(){
    while(true){
        cin>>n>>m;
        if(n==0&&m==0){
            break;
        }
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++){
            if(i==j){
            mp[i][j].l=0;
            mp[i][j].c=0;
            }
            else{
                mp[i][j].c=inf;
                mp[i][j].l=inf;
            }
        }
        for(int i=0;i<=n;i++){
            dis[i].c=inf;
            dis[i].l=inf;
            flag[i]=true;
        }
        ll w,u,l,c;
        for(int i=0;i<m;i++){
            scanf("%lld%lld%lld%lld",&w,&u,&l,&c);
            node x;
            x.l=l;
            x.c=c;
            if(x<mp[w][u]&&x<mp[u][w]){
                mp[w][u].c=x.c;
                mp[w][u].l=x.l;
                mp[u][w].c=x.c;
                mp[u][w].l=x.l;
            }
        }
        ll s,e;
        node in;
        in.c=inf+9999;
        in.l=inf+9999;
        cin>>s>>e;
        dis[s].c=0;
        dis[s].l=0;
        int cnt=0;
        while(cnt<n){
            node mi=in;
            int mit=0;
            for(int i=1;i<=n;i++){
                if(flag[i]&&dis[i]<mi){
                    mi=dis[i];
                    mit=i;
                }
            }
           // cout<<q.top()<<' '<<dis[q.top()].l<<" "<<dis[q.top()].c<<endl;
            for(int i=1;i<=n;i++){
                node x;
                x.c=dis[mit].c+mp[mit][i].c;
                x.l=dis[mit].l+mp[mit][i].l;
                if(x<dis[i]&&flag[i]){
                    dis[i].c=x.c;
                    dis[i].l=x.l;
                }
            }
            flag[mit]=false;
            cnt++;
        }
        cout<<dis[e].l<<' '<<dis[e].c<<endl;
    }
    return ;
}
int main(){
    freopen("in.txt","r",stdin);
    ll t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
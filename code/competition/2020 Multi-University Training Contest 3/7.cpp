#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n,k;
int mp[55][55];
int dis[55];
int flag[55];
void dij(){
    memset(flag, 0, sizeof(flag));
    memset(dis,63, sizeof(dis));
    dis[1]=1;
    int ct=0;
    while(ct<n){
        int mi=llinf,mix;
        for(int i=1;i<n;i++){
            if(mi<dis[i]&&!flag){
                mi=dis[i];
                mix=i;
            }
        }
        for(int i=1;i<n;i++){
            dis[i]=min(dis[i],dis[i]+mp[mix][i]);
        }
        flag[mix]=1;
        ct++;
    }
}
int ans=llinf;
void dfs(int step){
    if(step==k){
        dij();
        ans=min(ans,dis[n]);
        return;
    }
    int a=rand()%n;
    int b=rand()%n;
    int t=mp[a][b];   
    mp[a][b]=llinf;
    dfs(step + 1);
    mp[a][b]=t;
}
void work()
{
    ans=llinf;
    rd(n),rd(k);
    int u,v,w;
    for(int i=0;i<n*(n-1)/2;i++){
        rd(u),rd(v),rd(w);
        mp[u][v]=w;
        mp[v][u]=w;
    }
    int cnt=0;
    while(cnt<500000){
        dfs(0);
        cnt++;
    }
    printf("%lld\n",ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n,k;
int dis[55];
int fr[55];
int mp[55][55];
int ans=0;
void dij(){
    int flag[55];
    for(int i=1;i<=n;i++)
    dis[i]=llinf,fr[i]=-1,flag[i]=1;
    dis[1]=0;
    int ct=0;
    while(ct<n){
        int mi=llinf+100,mix=0;
        for(int i=1;i<=n;i++){
            if(dis[i]<mi&&flag[i])
                mi=dis[i],mix=i;
        }
        for(int i=1;i<=n;i++)
            if(flag[i]&&mp[mix][i]+dis[mix]<dis[i]){
                dis[i]=mp[mix][i]+dis[mix],fr[i]=mix;
            }
        flag[mix]=0,ct++;
    }
}
void dfs(int step){
    if(step==k){
        dij();
        ans=max(ans,dis[n]);
        return;
    }
    dij();
    vector<int> s;  
    //printf("step%lld\n",step);
    int now=n;
    s.push_back(n);
    while(fr[now]!=-1){
        now=fr[now];
        s.push_back(now);
    }
    for(int i=0;i<s.size()-1;i++){
        int t=mp[s[i]][s[i+1]];
        mp[s[i]][s[i+1]]=llinf;
        mp[s[i+1]][s[i]]=llinf;
        dfs(step + 1);
        mp[s[i]][s[i+1]]=t;
        mp[s[i+1]][s[i]]=t;
    }
}
void work()
{
    rd(n),rd(k);
    int u,v,w;
    for(int i=0;i<n*(n-1)/2;i++){
        rd(u), rd(v), rd(w);
        mp[u][v]=w;
        mp[v][u]=w;
    }
    ans=0;
  //  printf("dasdsad");
    dfs(0);
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
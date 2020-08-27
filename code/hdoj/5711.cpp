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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
int n,m,k,l;
int dp[1<<18][20];
int dis[100];
int vl[100];
int mp[100][100];
int ccnt=0;
void work()
{
    ccnt++;
    rd(n),rd(m),rd(k),rd(l);
    for(int i=1;i<=n;i++)
        rd(vl[i]);
    for(int i=1;i<=n;i++)
        rd(dis[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            mp[i][j]=llinf;
    for(int i=0;i<=n;i++)
        mp[i][i]=0;
    int u,v,w;
    for(int i=0;i<m;i++){
        rd(u), rd(v), rd(w);
        mp[u][v]=min(mp[u][v],w);
        mp[v][u]=mp[u][v];
    }
    for(int j=0;j<=n;j++)
        for(int i=0;i<=n;i++)
            for(int k=0;k<=n;k++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    for(int i=0;i<(1<<(n+1));i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=llinf;
    dp[1][0]=0;
    int end=(1<<(n+1));
    for(int i=1;i<end;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if((i&(1<<j))==0)continue;
            for(int k=1;k<=n;k++)
            {
                int q=(i|(1<<k));
                dp[q][k]=min(dp[q][k],dp[i][j]+mp[j][k]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<end;i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j]+mp[j][0]<=l){
                int tans=0;
                int t=i;
                int cnt=0;
                priority_queue<pair<int,int>> q;
                while(t){
                    if(t&1)
                        q.push(make_pair(vl[cnt],cnt));
                    cnt++;
                    t>>=1;
                }
                for(int tt=0;tt<k;tt++){
                    tans+=q.top().first;
                    pair<int,int> tmp=q.top();
                    tmp.first-=dis[tmp.second];
                    q.pop();
                    q.push(tmp);
                }
                ans=max(tans,ans);
            }
        }
    }
    printf("Case %lld: %lld\n",ccnt,ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 1;
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
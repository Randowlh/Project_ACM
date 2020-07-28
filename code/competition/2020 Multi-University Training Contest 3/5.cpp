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
int mp[55][55];
int fr[55][55];
int flag[55];
void work()
{
    memset(flag, 0, sizeof(flag));
    memset(fr,63, sizeof(fr));
    int n,k;
    rd(n), rd(k);
    int u,v,w;
  //  printf("asdasdsadasdsa\n");
    for(int i=1;i<=n;i++){
        mp[i][i]=0;
    }
    //printf("%lld\n",n*(n+1)/2);
    for(int i=0;i<n*(n-1)/2;i++){
        rd(u), rd(v), rd(w);
        mp[u][v]=w;
        mp[v][u]=w;
    }
    int last=0;
    for (int kk = 1; kk <= n; kk++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(i!=1||j!=n)
                     fr[i][j] = min(mp[i][j], mp[i][kk] + mp[kk][j]);
                        if(i==1&&j==n&&!flag[kk]){
                        fr[i][j] = min(mp[i][j], mp[i][kk] + mp[kk][j]);
                        last=kk;
                        }
            }
        }
    }
    printf("%lld\n",fr[1][n]);
    flag[last]=1;
    for(int q=0;q<k;q++){
        fr[1][n]=llinf;
        int last=0;
        for (int kk = 1; kk <= n; kk++) 
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= n; j++) {
                     if(i!=1||j!=n)
                        fr[i][j] = min(mp[i][j], mp[i][kk] + mp[kk][j]);
                        else
                        if(!flag[kk]){
                        fr[i][j] = min(mp[i][j], mp[i][kk] + mp[kk][j]);
                        last=kk;
                        }
                }
        flag[last]=1;
    }
    printf("%lld\n",fr[1][n]);
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
     //   printf("asdasdsadasdsa\n");
        work();
    }
    return 0;
}
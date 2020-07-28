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

string a[5];
int ans=0;
void dfs(int x,int y){
    if(x==3&&y==3){
        a[3][3]=1;
        int f=0;
        for(int i=1;i<3;i++)
        for(int j=i+1;j<=3;j++){
            if(a[i]==a[j]){
                f=1;
                break;
            }
        }
         if(!f){
            for(int i=1;i<=3;i++)
                for(int j=i+1;j<=3;j++){
                    int  flag=0;
                    for(int k=1;k<=3;k++)
                    if(a[k][i]!=a[k][j]){
                        flag=1;break;
                    }
                    if(!flag)
                    f=1;
                }
        }
        if(!f)
        ans++;
        f=0;
        a[3][3]=0;
        for(int i=1;i<3;i++)
            for(int j=i+1;j<=3;j++)
                if(a[i]==a[j]){
                    f=1;
                    break;
                }
        if(!f){
            for(int i=1;i<=3;i++)
                for(int j=i+1;j<=3;j++){
                    int  flag=0;
                    for(int k=1;k<=3;k++)
                    if(a[k][i]!=a[k][j]){
                        flag=1;break;
                    }
                    if(!flag)
                    f=1;
                }
        }
        if(!f)
        ans++;
        return;
    }
    int nextx,nexty;
    if(y==3)
    nexty=1,nextx=x+1;
    else nextx=x,nexty=y+1;
    a[x][y]=1;
    dfs(nextx,nexty);
    a[x][y]=0;
    dfs(nextx,nexty);
}
void work()
{
    for(int i=0;i<=3;i++)
    a[i].resize(5);
    for(int i=0;i<=3;i++)
    for(int j=0;j<=3;j++)
    a[i][j]=0;
    dfs(1,1);
    cout<<ans<<endl;
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
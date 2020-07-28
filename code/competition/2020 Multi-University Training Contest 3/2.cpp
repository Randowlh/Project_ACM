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
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline int pow(int x, int a, int mod)
{
    int ans = 0;
    int now = x;
    while (a != 0)
    {
        if (a & 1)
        {
            ans = ans * now % mod;
        }
        now = now * now % mod;
        a >>= 1;
    }
    return ans;
}
inline int niyuan(int x, int mod) { return pow(x, mod - 2, mod); }
struct node{
    int o1, o2;
    int fa;
}date[110000];
int n;
int out1,out2;
map<pair<int,int>,int> M;
int find(int x){
    if(date[x].fa==x)
    return  x;
    else return date[x].fa=find(date[x].fa);
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    date[l].fa=r;
    date[r].o1+=date[l].o1,date[r].o2+=date[l].o2;
}
void work()
{
    out1=0,out2=0;
    rd(n);
    int tmp;
    for(int i=1;i<=n;i++){
        rd(tmp);
        date[i].fa=i;
        if(tmp==1)
        date[i].o1=1,date[i].o2=0,out1++;
        else 
        date[i].o1=0,date[i].o2=1,out2++;
    }
    int  u,v;
    int ans= out2*(out2-1)/2%mod*out1+out2*(out2-1)/2*(out2-2)/3%mod;
    ans%=mod;
    printf("%lld\n",ans);
    for(int q=0;q<n-1;q++){
        rd(u), rd(v);
        if(find(u)==find(v)){
            printf("%lld\n",ans);
            continue;
        }
        node& l=date[find(u)];
        node& r=date[find(v)];
        ans-=(l.o2*r.o2%mod*(out2-l.o2-r.o2))%mod;
        ans=(ans+mod)%mod;
        ans-=(l.o2*r.o2%mod*(out1-l.o1-r.o1))%mod;
        ans=(ans+mod)%mod;
        ans-=(l.o2*r.o1%mod*(out2-l.o2-r.o2))%mod;
        ans=(ans+mod)%mod;
        ans-=(l.o1*r.o2%mod*(out2-l.o2-r.o2))%mod;
        ans=(ans+mod)%mod;
        printf("%lld\n",ans);
        merge(u,v);
    }
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
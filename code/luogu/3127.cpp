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
template<class T>
void wt(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) wt(x / 10);
    putchar('0' + x % 10);
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
bool iscap[110000];
int len[110000];
pair<int,int> wall[110000];
int n;
inline void ck(int x){
    int flag=1;
    int now=len[x];
    int l=x-1;
    int r=x;
    int f=0;
    while(flag){
        flag=0;
        while(now>wall[r].second){
            r++;
            if(iscap[r]){
                f=1;
                break;
            }
            flag=1;
            now+=len[r];
        }
        while(!f&&now>wall[l].second){
            l--;
            flag=1;
            if(iscap[l+1]){
                f=1;
                break;
            }
            now+=len[l+1];
        }
        if(f)
        break;
    }
    iscap[x]=f;
}
void work()
{
    rd(n);
    iscap[0]=iscap[n]=1;
    for(int i=0;i<n;i++)
        rd(wall[i].second),rd(wall[i].first);
    sort(wall,wall+n);
    for(int i=1;i<n;i++)
        len[i]=wall[i].first-wall[i-1].first;
    for(int i=n-1;i>=1;i--)
            ck(i);
    int ans=0;
    for(int i=n-1;i>=1;i--)
        if(!iscap[i])
            ans+=len[i];
    wt(ans);
    putchar('\n');
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
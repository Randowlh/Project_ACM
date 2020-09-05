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
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
int n,m,k;
int date[2][110000];
int ans[110000];
int rp[110000];
vector<int> v;
void work()
{
    rd(n),rd(m),rd(k);
    for(int i=1;i<=n;i++)
        ans[i]=date[0][i]=i;
    int l,r;
    for(int i=1;i<=m;i++){
        rd(l),rd(r);
        for(int j=l;j<=r;j++){
            date[1][r-j+l]=date[0][j];
        }
        for(int j=1;j<l; j++)
            date[1][j]=date[0][j];
        for(int j=r+1;j<=n;j++)
            date[1][j]=date[0][j];
        for(int j=1;j<=n;j++)
            date[0][j]=date[1][j];
    }
    for(int i=1;i<=n;i++)
        date[1][date[0][i]]=i;
    for(int i=1;i<=n;i++){
        if(rp[i])
            continue;
        int now=date[1][i];
        v.clear();
        v.push_back(i);
        while(now!=i){
            v.push_back(now);
            now=date[1][now];
        }
        for(int i=0;i<v.size();i++)
            rp[v[i]]=v[(i+k)%v.size()];
    }
    for(int i=1;i<=n;i++)
        ans[rp[i]]=i;
    for(int i=1;i<=n;i++){
        wt(ans[i]),putchar(' ');
    }
    putchar('\n');
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
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
#define pt putchar
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
int  tmp[210000];
int  lo[210000];
char date[210000];
int tail=0;
void work()
{
    int n,q,k;
    rd(n),rd(q);
    scanf("%s",date+1);
    for(int i=1;i<=n;i++)
        if(date[i]=='1')
            lo[++tail]=i;
    int l,r;
    for(int k=0;k<q; k++){
        rd(l), rd(r);
        int dis=0;
        int frt=1<<(r-l+1);
        int ttail=0,flag=0;
        int bk=(1<<(r-l+1))-(r-l+1);
        for(int i=1;i<=tail;i++){
            if(lo[i]<l) tmp[++ttail]=lo[i];
            else if(lo[i]<=r) frt-=(1<<(r-lo[i]));
            else if(flag)tmp[++ttail]=lo[i]+bk;
            else {
                tmp[++ttail]=l-1+frt;
                flag=1;
                tmp[++ttail]=lo[i]+bk;
            }
        }
        tail=ttail;
        for(int i=1;i<=ttail;i++)
            lo[i]=tmp[i];
    }
    wt(tail),pt('\n');
    for(int i=1;i<=tail;i++)
    {
        wt(lo[i]),pt(' ');
    }
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
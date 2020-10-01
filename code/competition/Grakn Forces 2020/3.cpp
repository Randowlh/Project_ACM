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
#define MP make_pair
#define pb push_back
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
const int maxn = 110000;
int date[maxn];
double lc[maxn],rc[maxn];
void work()
{
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    date[n+1]=l;
    double t=0;
    lc[0]=0,rc[n+1]=0;
    for(int i=1;i<=n+1;i++){
        t+= (date[i]-date[i-1])/(db)i;
        lc[i]=t;
    }
    t=0;
    for(int i=n;i>=0;i--){
        t+=(date[i+1]-date[i])/(db)(n-i+1);
        rc[i]=t;
    }
    int mix=-1;
    for(int i=0;i<=n;i++){
        if(fabs(lc[i]-rc[i])<eps){
            printf("%.10f\n",lc[i]);
            return;
        }
        if(lc[i]<rc[i]&&lc[i+1]>rc[i+1]){
            mix=i;
            break;
        }
    }
    double dis=date[mix+1]-date[mix];
    double t1=lc[mix],t2=rc[mix+1],v1=mix+1,v2=n-mix+1;
    if(t1<t2)
        swap(t1,t2),swap(v1,v2);
    double ans=t1;
    dis-=(t1-t2)*v2;
    ans+=(dis)/(v1+v2);
    printf("%.10f\n",ans);
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}
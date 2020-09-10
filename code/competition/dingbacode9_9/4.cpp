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
const double eps = 1e-9;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
int n,l,r;
double tim[11000],x[11000];
double tr[11000],tl[11000];
double f(int i,int j,double mid){
    double lv=(mid-l)/(r-l);
    double rv=(r-mid)/(r-l);
    double ti=min((x[i]-l)/lv,(r-x[i])/rv)+tim[i];
    double tj=min((x[j]-l)/lv,(r-x[j])/rv)+tim[j];
    return ti-tj;
}
void work()
{
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
        cin>>x[i],tr[i]=r,tl[i]=l;
    for(int i=1;i<=n;i++)
        cin>>tim[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            double ll=l,rr=r;
            while((rr-ll)>eps){
                double mid=(ll+rr)/2.0;
                if(f(i,j,mid)<0)
                    rr=mid;
                else ll=mid;
            }
            MIN(tr[i],ll);
        }
    double len=(r-l);
    tr[0]=l;
    for(int i=1;i<=n;i++){
        printf("%.6f\n",max(tr[i]-tr[i-1],0.0)/len);
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
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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 1100;
int date[maxn];
int find(int x){
    if(date[x]==x)
        return x;
    else return date[x]=find(date[x]);
}
void merge(int a,int b){ 
    int l=find(a);
    int r=find(b);
    if(l^r)
        date[l]=r;
}
int x[maxn],y[maxn],z[maxn];
void work()
{
    vector<int> shang,xia;
    int n,h,r;   
    rd(n),rd(h),rd(r);
    for(int i=1;i<=n;i++)
        rd(x[i]),rd(y[i]),rd(z[i]),date[i]=i;
    for(int i=1;i<=n;i++){
        if(z[i]<=r)
            xia.push_back(i);
        if(z[i]<=h&&h-z[i]<=r)
            shang.push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            int dx,dy,dz;
            dx=abs(x[i]-x[j]);
            dy=abs(y[i]-y[j]);
            dz=abs(z[i]-z[j]);
            if(dx*dx+dy*dy+dz*dz<=r*r*4)
                merge(i,j);
        }
    }
    int f=0;
    for(int i=0;i<shang.size();i++)
        for(int j=0;j<xia.size();j++)
            if(find(shang[i])==find(xia[j])){
                f=1;
                break;
            }
    if(f)
        printf("Yes\n");
    else printf("No\n");
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
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
const int maxn = 1010000;
struct tree_arr{
    int date[maxn<<2];
    inline int lowbit(int x){return x&-x;}
    inline void update(int x,int v){while(x<maxn){date[x]+=v,x+=lowbit(x);}}
    inline int query(int x){int ans=0;while(x){ans+=date[x],x-=lowbit(x);}return ans;}
}T[2];
int a[maxn];
int n,D,K;
vector<int> v;
int getrk(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
void work()
{
    rd(n),rd(D),rd(K);
    for(int i=1;i<=n;i++)
        rd(a[i]);
    for(int i=1;i<=n;i++){
        int x=D*i+a[i],y=a[i]-D*i;
        v.push_back(x),v.push_back(y),v.push_back(K-x),v.push_back(K-y);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int ans=0;
    for(int i=1;i<=n;i++){T[1].update(getrk(D*i+a[i]),1);}
    for(int i=1;i<=n;i++){
        T[1].update(getrk(D*i+a[i]),-1);
        int x=D*i+a[i],y=a[i]-D*i;
        x=K-x,y=K-y;
        x=getrk(x),y=getrk(y);
        int v1=T[0].query(x)+T[1].query(y);
        ans+=v1*(n-1-v1);
        T[0].update(getrk(a[i]-D*i),1);
    }
    cout<<n*(n-1)*(n-2)/6-ans/2<<endl;
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
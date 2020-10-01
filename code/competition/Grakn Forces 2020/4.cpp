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
const int maxn = 2100;
pair<int,int> lt[maxn],ps[maxn],cst[maxn];
int mi[maxn];
bool f[maxn];
vector<pair<int,int>> pnt,jhd;
void work()
{  
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>ps[i].first>>ps[i].second;
    sort(ps+1, ps+n+1);
    int mix=llinf;
    for(int i=n;i>=1;i--){
        MIN(mix,ps[i].second);
        mi[i]=mix;
    }
    for(int j=1;j<=m;j++)
        cin>>lt[j].first>>lt[j].second;
    sort(lt+1,lt+1+m);
    lt[0]=MP(0,llinf);
    lt[m+1]=MP(llinf,0);
    for(int i=0;i<=m;i++){
        if(lt[i].second>lt[i+1].second)
            pnt.push_back(lt[i]);
    }  
    pnt.push_back(lt[m+1]);
    for(int i=0;i<pnt.size()-1;i++)
        jhd.push_back(MP(pnt[i].first,pnt[i+1].second));    
    int ans=llinf;
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        int tans=llinf;
        int tl=0,tr=0;
        for(int j=0;j<jhd.size();j++){
            if(max(0ll,jhd[i].first-ps[i].first+l)+max(0ll,jhd[i].second-ps[i].second+r)<tans){
                tans=max(0ll,jhd[i].first-ps[i].first+l)+max(0ll,jhd[i].second-ps[i].second+r);
                tl=max(0ll,jhd[i].first-ps[i].first+l);
                tr=max(0ll,jhd[i].second-ps[i].second+r);
            }
        }
        l+=tl;
        r+=tr;
    }
    cout<<l+r<<endl;
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
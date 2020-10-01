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
const int maxn = 11000;
pair<int,int> lt[maxn],qd[maxn];
vector<pair<int,int>> aa;
vector<int> v;
void work()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>qd[i].first>>qd[i].second;
    for(int i=1;i<=m;i++)
        cin>>lt[i].first>>lt[i].second;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(qd[i].first<=lt[j].first&&qd[i].second<=lt[j].second)
                aa.push_back(MP(lt[j].first-qd[i].first+1,lt[j].second-qd[i].second+1));
    sort(aa.begin(),aa.end());
    int now=0;
    v.push_back(0);
    for(int i=aa.size()-1;i>=0;i--){
        MAX(now,aa[i].second);
        v.push_back(now);
    }
    reverse(v.begin(),v.end());
    int ans=llinf;
    for(int i=0;i<aa.size();i++)
        MIN(ans,v[i+1]+aa[i].first);
    MIN(ans,v[0]);
    cout<<(aa.empty()?0:ans)<<endl;
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
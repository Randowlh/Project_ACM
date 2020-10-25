#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int n;
vector<int> mp[210000];
int cap[210000];
int ps[210000];
int ex[210000];
int sz[210000];
int ans;
void dfs(int pos){
   if(mp[pos].size()==0){
      sz[pos]=1;
      ex[pos]=ps[pos];
      cap[pos]=0;
      return;
   }
   vector<pair<int,int>> v;
   for(int i=0;i<mp[pos].size();i++){
      dfs(mp[pos][i]);
      sz[pos]+=sz[mp[pos][i]];
      v.push_back(make_pair(ex[mp[pos][i]],mp[pos][i]));
   }
   sort(v.begin(),v.end());
   int ca=0;
   for(int i=0;i<v.size();i++)
      ca+=(cap[v[i].second]+(v[v.size()-1].first-v[i].first)*sz[v[i].second]);
   if(ca>=ps[pos]){
      cap[pos]=ca-ps[pos];
      ex[pos]=v[v.size()-1].first;
      return;
   }
   int dis=ps[pos]-ca;
   cap[pos]=(sz[pos]-dis%sz[pos])%sz[pos];
   ex[pos]=v[v.size()-1].first+dis/sz[pos]+(dis%sz[pos]>0);
}
void work()
{
   int n;
   cin>>n;
   int tmp;
   for(int i=2;i<=n;i++){
      cin>>tmp;
      mp[tmp].push_back(i);
   }
   for(int i=1;i<=n;i++){
      cin>>ps[i];
   }
   dfs(1);
   //solve(1,0);
   cout<<ex[1]<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}
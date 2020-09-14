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
int n;
vector<int> mp[110000];
int sz[110000];
int wt[110000];
int f[110000];
int cnt[110000];
void getzx(int pos,int fa){
   sz[pos]=1;
   f[pos]=fa;
   wt[pos]=0;
   cnt[pos]=0;
   for(int i=0;i<mp[pos].size(); i++){
      if(mp[pos][i]==fa)
         continue;
      getzx(mp[pos][i],pos);
      sz[pos]+=sz[mp[pos][i]];
      if(sz[mp[pos][i]]==wt[pos])
         cnt[pos]++;
      if(sz[mp[pos][i]]>wt[pos]){
         wt[pos]=sz[mp[pos][i]];
         cnt[pos]=1;
      }
   }
   int a=n-sz[pos];
   if(a==wt[pos])
      cnt[pos]++;
   if(a>wt[pos]){
      cnt[pos]=1;
      wt[pos]=a;
   }
}
void work()
{
   cin>>n;
   for(int i=1;i<=n;i++)
      mp[i].clear();
   int u,w;
   for(int i=1;i<=n-1;i++){
      cin>>u>>w;
      mp[u].push_back(w);
      mp[w].push_back(u);
   }
   getzx(1,-1);
   int ma=llinf;
   int ct=0;
   int mix=0;
   for(int i=1;i<=n;i++)
      MIN(ma,wt[i]);
   vector<pair<int,int>> v;
   for(int i=1;i<=n;i++)
      if(wt[i]==ma)
         v.push_back(make_pair(cnt[i],i));
   sort(v.begin(),v.end());
   if(v.size()==1){
      cout<<v[0].second<<' '<<mp[v[0].first][0]<<endl;
      cout<<v[0].second<<' '<<mp[v[0].first][0]<<endl;
      return;
   }
   for(int i=1;i<=n;i++){
      if(mp[i].size()==1&&f[i]!=v[0].second){
         cout<<f[i]<<' '<<i<<endl;
         cout<<v[i].second<<' '<<i<<endl;
         return ;
      }
   }
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
cin>>t;
while (t--)
{
work();
}
return 0;
}
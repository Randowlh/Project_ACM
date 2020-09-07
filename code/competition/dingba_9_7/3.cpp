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
vector<pair<int,int>> mp[110000];
vector<pair<int,pair<int,int>>> aa;
map<tuple<int,int,int>,int> M;
void work()
{
    int n,m;
    rd(n), rd(m);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u), rd(v),rd(w);
        if(u==v)
            continue;
        if(u>v)
            swap(u,v);
        mp[u].push_back(make_pair(w,v));
        mp[v].push_back(make_pair(w,u));
        aa.push_back(make_pair(w,make_pair(u,v)));
    }
    for(int i=1;i<=n;i++)
        sort(mp[i].begin(),mp[i].end(),greater<pair<int, int>>());
    sort(aa.begin(), aa.end(),greater<pair<int,pair<int, int>>>());
    int aans=0;
    for(int i=0;i<aa.size();i++){
        int ans=0;
        int u=aa[i].second.first;
        int w=aa[i].first;
        int v=aa[i].second.second;
        // if(!M[make_tuple(u,v,w)])
        //     continue;
        for(int j=0;j<mp[u].size();j++){
            if(mp[u][j].first<=w)
                break;
            int to=mp[u][j].second;
            int fr=u;
            int ww=mp[u][j].first;
            if(fr>to)
                swap(fr, to);
            MAX(ans,M[make_tuple(fr,to,ww)]);
        }
        for(int j=0;j<mp[v].size();j++){
            if(mp[v][j].first<=w)
                 break;
            int to=mp[v][j].second;
            int fr=v;
            int ww=mp[v][j].first;
            if(fr>to)
                swap(fr, to);
            MAX(ans,M[make_tuple(fr,to,ww)]);
        }
        M[make_tuple(u,v,w)]=ans+1;
        MAX(aans,ans);
    }
    cout<<aans<<endl;
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
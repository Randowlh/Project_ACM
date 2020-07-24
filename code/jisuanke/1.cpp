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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
vector<int> mp[5100];
void work()
{
    int n;
    rd(n);
    int u, v;
    for (int i = 0; i < n - 1;i++){
        rd(u), rd(v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    pair<int, int> date[5100];
    for (int i = 1;i<=n;i++)
        date[i] = make_pair(mp[i].size(), i);
    sort(date + 1, date + n + 1,greater<pair<int,int>>());
    int ans = date[1].first;
    for (int i = 0; i < mp[date[1].second].size(); i++){
        mp[mp[date[1].second][i]].pop_back();
    }
    mp[date[1].second].clear();
    for (int i = 1;i<=n;i++)
        date[i] = make_pair(mp[i].size(), i);
    sort(date + 1, date + n + 1,greater<pair<int,int>>());
    ans += date[1].first-1;
    printf("%lld\n", ans);
}
signed main()
{

    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
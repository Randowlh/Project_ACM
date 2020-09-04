#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template <class T>
inline void MAX(T &x, T y)
{
    if (y > x)
        x = y;
}
template <class T>
inline void MIN(T &x, T y)
{
    if (y < x)
        x = y;
}
template <class T>
inline void rd(T &x)
{
    x = 0;
    char o, f = 1;
    while (o = getchar(), o < 48)
        if (o == 45)
            f = -f;
    do
        x = (x << 3) + (x << 1) + (o ^ 48);
    while (o = getchar(), o > 47);
    x *= f;
}
template <class T>
void wt(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        wt(x / 10);
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
const int m1 = 998244353;
const int m2 = 1000001011;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm = 1;
const int maxn = 510000;
int n;
int mp[330][330];
int lt[330][330];
int dis[330][330];
int vis[330][330];
int lj[330];
int flag[330];
int ans = 0;
void dij(int s)
{
    for (int i = 1; i <= n; i++)
        dis[s][i] = llinf, flag[i] = 0;
    dis[s][s] = 0;
    int cnt = 0;
    while (cnt < n)
    {
        int mi = llinf + 100;
        int mix = 1;
        for (int i = 1; i <= n; i++)
            if (mi > dis[s][i] && !flag[i])
                mi = dis[s][i], mix = i;
        for (int i = 1; i <= n; i++)
        {
            if (dis[s][i] > dis[s][mix] + mp[mix][i])
                dis[s][i] = dis[s][mix] + mp[mix][i];
        }
        flag[mix] = 1;
        cnt++;
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i][s] = dis[s][i];
    }
}
vector<pair<int, pair<int, int>>> v;
void work()
{
    rd(n);
    int t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            rd(mp[i][j]);
    int ans=n*(n-1);
    int jian=0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(k==i||k==j||i==j)
                    continue;
                if(mp[i][j]==mp[i][k]+mp[k][j]&&!vis[i][j])
                    ans--,vis[i][j]=1;
            }
        }
    }
    cout<<ans/2<<endl;
    return ;
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second.first == v[i].second.second)
            continue;
        if (dis[v[i].second.first][v[i].second.second] > v[i].first)
        {
            mp[v[i].second.first][v[i].second.second] = v[i].first;
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
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

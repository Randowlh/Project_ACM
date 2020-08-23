#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <vector>
#include <set>
#include <cstdio>
#include <string>
#include <deque>
#include <iostream>
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const int maxm = 1;
struct Edges
{
    int w, to, next;
} edge[maxm];
int head[maxm];
int ecnt = 0;
void add(int u, int v, int w)
{
    edge[++ecnt].next = head[u];
    edge[ecnt].to = v;
    edge[ecnt].w = w;
    head[u] = ecnt;
}
int a[1010][1010], b[1010][1010];
void work()
{
    int n, q;
    while (scanf("%d%d",&n,&q)!=EOF)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                rd(a[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                rd(b[i][j]);
        int ans = 0;
        for (int r = 1; r <= n; r++)
        {
            for (int i = 1; i <= n; i++)
                ans += a[r][i] * b[i][r];
        }
        int opt, x, y, v;
        for (int i = 0; i < q; i++)
        {
            rd(opt) ,rd(x),rd( y),rd(v);
            if (opt == 0)
            {
                ans -= a[x][y] * b[y][x];
                a[x][y] = v;
                ans += a[x][y] * b[y][x];
            }
            else
            {
                ans -= b[x][y] * a[y][x];
                b[x][y] = v;
                ans += b[x][y] * a[y][x];
            }
            cout<<ans<<endl;
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
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
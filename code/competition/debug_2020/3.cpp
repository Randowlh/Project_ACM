#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxn = 200100;
int v[maxn];
int w[maxn];
int afthv[maxn];
int bfthv[maxn];
int bfthw[maxn];
int afthw[maxn];
void work()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        if (v[i] == 1)
            cin >> v[i];
    }
    afthv[0] = 0;
    bfthv[0] = 0;
    afthw[0] = 0;
    bfthw[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        bfthv[i] = bfthv[i - 1] + v[i];
        bfthw[i] = bfthw[i - 1] + w[i];
    }
    for (int j = 1; j <= n; j++)
    {
        afthw[j] = afthw[j - 1] + w[n - j + 1];
        afthv[j] = afthv[j - 1] + v[n - j + 1];
    }
    int ans = 0;
    int nowb = -1;
    int nowa = -1;
    for (int i = 1; i <= n; i++)
    {
        if (bfthw[i] > m)
        {
            nowb = i - 1;
            break;
        }
    }
    if (nowb == 0)
    {
        cout << bfthv[n] << endl;
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (afthw[j] > m - bfthw[nowb])
        {
            nowa = j - 1;
            break;
        }
    }
    while (nowb != 0)
    {
        ans = max(ans, afthv[nowa] + bfthv[nowb]);
        nowb--;
        for (int i = nowa; i <= n; i++)
        {
            if (afthw[i] > m - bfthw[nowb])
            {
                nowa = i - 1;
                break;
            }
        }
    }
    nowb = 0;
    nowa = 0;
    for (int i = 1; i <= n; i++)
    {
        if (afthw[i] > m)
        {
            nowa = i - 1;
            break;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        if (bfthw[j] > m - afthw[nowa])
        {
            nowb = j - 1;
            break;
        }
    }
    while (nowa != 0)
    {
        ans = max(ans, afthv[nowa] + bfthv[nowb]);
        nowa--;
        for (int i = nowb; i <= n; i++)
        {
            if (bfthw[i] > m - afthw[nowa])
            {
                nowb = i - 1;
                break;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
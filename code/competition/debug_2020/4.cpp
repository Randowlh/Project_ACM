#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int d[500100];
pair<int, int> pr[500100];
pair<int, int> af[500100];
void work()
{
    int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &d[i]);
    af[n].first = -inf;
    af[n].second = n;
    for (int i = n - 1; i > 0; i--)
    {
        if (af[i + 1].first < d[i])
        {
            af[i].first = d[i];
            af[i].second = i;
        }
        else
            af[i] = af[i + 1];
    }
    pr[0].first = d[0];
    pr[0].second = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (pr[i - 1].first < d[i])
        {
            pr[i].first = d[i];
            pr[i].second = i;
        }
        else
            pr[i] = pr[i - 1];
    }
    int ans = 0;
    int ma = 0;
    int a = -1, b = -1;
    for (int i = 1; i <= n - 1; i++)
    {
        ans += abs(d[i] - d[i - 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (af[i].first - pr[i].first > ma)
        {
            a = af[i].second;
            b = pr[i].second;
        }
    }
    if (a != -1)
    {
        ans += abs(d[b - 1] - d[a]) + abs(d[a + 1] - d[b]) - abs(d[b - 1] - d[b]) - abs(d[a + 1] - d[a]);
    }
    printf("%lld\n", ans);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        work();
    }
    return 0;
}
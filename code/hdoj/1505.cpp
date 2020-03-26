#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
ll dp[1100], r[1100], l[1100];
void work()
{
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n >> m;
    char tmp;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            if (tmp == 'F')
                dp[j]++;
            else
                dp[j] = 0;
        }
        for (int k = 0; k < m; k++)
        {
            l[k] = k;
            while (l[k] > 0 && dp[l[k] - 1] >= dp[k])
            {
                l[k] = l[l[k] - 1];
            }
        }
        for (int k = m - 1; k >= 0; k--)
        {
            r[k] = k;
            while (r[k] < m - 1 && dp[r[k] + 1] >= dp[k])
            {
                r[k] = r[r[k] + 1];
            }
        }
        for (int k = 0; k < m; k++)
        {
            ans = max(ans, (r[k] - l[k] + 1) * dp[k]);
        }
    }
    cout << ans * 3 << endl;
}
int main()
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
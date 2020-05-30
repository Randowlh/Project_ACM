#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
char mp[1010][1010];
void work()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '.')
                cnt++;
        }
    if (x * 2 <= y)
    {
        cout << cnt * x << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '.')
            {
                if (j != m - 1 && mp[i][j + 1] == '.')
                {
                    ans += y;
                    mp[i][j + 1] = '*';
                }
                else
                {
                    ans += x;
                }
                mp[i][j] = '*';
            }
        }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
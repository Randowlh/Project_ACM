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
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int ans[100][100];
void work()
{
    memset(ans, 0, sizeof(ans));
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b)
    {
        out(0);
        return;
    }
    out(1);
    int f = 0;
    if (n > m)
    {
        f = 1;
        //cout << "dasda" << endl;
        swap(a, b);
        swap(n, m);
    }
    for (int i = 0; i < b; i++)
    {
        int x = i;
        for (int j = 0; j < m; j++)
        {
            ans[x][j] = 1;
            x = (x + 1) % n;
        }
    }
    if (!f)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << ans[i][j];
            cout << endl;
        }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[j][i];
            }
            cout << endl;
        }
    }
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
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int mp[110][110];
void work()
{
    int n, m;
    cin >> n >> m;
    memset(mp, 0, sizeof(mp));
    int fl = 0;
    if (n % 2 == 0 || m % 2 == 0)
        fl = 1;
    int tmp = 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = tmp;
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = cnt;
            if (cnt == 1)
                cnt = 0;
            else
                cnt = 1;
        }
        if (tmp == 1)
            tmp = 0;
        else
            tmp = 1;
    }
    if (fl)
        for (int i = 0; i < n; i++)
            if (mp[i][0] == 0)
            {
                mp[i][0] = 1;
                break;
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 1)
                cout << 'B';
            else
                cout << 'W';
        }
        cout << endl;
    }
    return;
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
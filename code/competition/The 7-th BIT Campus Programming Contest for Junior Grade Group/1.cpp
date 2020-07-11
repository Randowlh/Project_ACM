#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int mp[100][100];
int book[100];
void work()
{
    memset(book, 0, sizeof(book));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    for (int i = 0; i < m; i++)
    {
        int now = -1;
        for (int j = 0; j < n; j++)
        {
            // cout << j << endl;
            // cout << "book" << book[j] << ' ' << mp[j][i] << endl;
            if (!book[j] && mp[j][i])
            {
                now = j;
                book[j] = 1;
                break;
            }
        }
        if (now == -1)
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (book[j])
                continue;
            if (mp[j][i] == 0)
                continue;
            int tt = lcm(mp[now][i], mp[j][i]);
            //    cout << "tt=" << tt << endl;
            int chn = tt / mp[now][i];
            int cht = tt / mp[j][i];
            for (int k = 0; k < m; k++)
            {
                mp[j][k] = mp[j][k] * cht - mp[now][k] * chn;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (book[i] == 0)
        {
            out(1);
            return;
        }
    }
    //  cout << "dasdad" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << mp[i][j] << ' ';
    //     cout << endl;
    // }
    out(0);
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
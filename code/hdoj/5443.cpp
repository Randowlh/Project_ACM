#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct st_table
{
    int date[100100];
    int mx[100100][30];
    void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
void work()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b.date[i];
    cin >> m;
    int l, r;
    b.RMQ(n);
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << b.query(l, r) << endl;
    }
    return;
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
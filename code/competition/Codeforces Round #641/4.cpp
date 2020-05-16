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
int dp[110000];
void work()
{
    int tmp;
    int n, k;
    cin >> n >> k;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < k)
            dp[i] = -1;
        else if (tmp == k)
        {
            dp[i] = 0;
            f = 1;
        }
        else
            dp[i] = 1;
    }
    if (!f)
    {
        out(0);
        return;
    }
    if (n == 1)
    {
        out(1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 3; j++)
        {
            if (i + j < n)
                if (dp[i + j] >= 0)
                    cnt++;
        }
        if (cnt >= 2)
        {
            out(1);
            return;
        }
    }
    out(0);
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
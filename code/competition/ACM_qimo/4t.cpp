#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1100000];
int date[1100000];
signed main()
{
    int tmp;
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> date[i];
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + date[i - 1];
        }
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            cout << dp[b] - dp[a - 1] << endl;
        }
    }
}
`
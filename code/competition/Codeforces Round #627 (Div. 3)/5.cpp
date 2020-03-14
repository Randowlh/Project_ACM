#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int dp[2100][2100];
void work()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < 2010; i++)
        for (int j = 0; j < 2010; j++)
            dp[i][j] = -1;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (dp[i][j] == -1)
                continue;
            dp[i + 1][(j + v[i]) % h] = max(dp[i][j] + (((j + v[i]) % h <= r) && ((j + v[i]) % h >= l)), dp[i + 1][(j + v[i]) % h]);
            dp[i + 1][(j + v[i] - 1) % h] = max(dp[i][j] + (((j + v[i] - 1) % h <= r) && ((j + v[i] - 1) % h >= l)), dp[i + 1][(j + v[i] - 1) % h]);
        }
    }
    int ma = 0;
    for (int i = 0; i < h; i++)
    {
        ma = max(ma, dp[n][i]);
    }
    cout << ma - 1 << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
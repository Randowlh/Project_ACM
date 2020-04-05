#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int dp[2100];
void work()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, v, w;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    int t;
    for (int i = 0; i < m; i++)
    {
        cin >> t >> tmp;
        v.push_back(tmp);
        w.push_back(t);
    }
    map<int, int> M;
    dp[0] = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = w[i]; j <= 200; j++)
            if (dp[j - w[i]] != -1)
            {
                M[dp[j]] = j;
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
    }
    // return;
    int cnt = 0;
    for (int k = a[0]; k <= a[a.size() - 1]; k++)
    {
        int tol = 0;
        int left = k;
        while (left > a[0])
        {
            int z = 0;
            for (int i = 0; i < n; i++)
            {
                if (left < a[i])
                {
                    z = i - 1;
                    break;
                }
            }
            //cout << left << ' ' << M.count(a[z]) << endl;
            for (int i = a[z]; i >= 0; i--)
            {
                if (M.count(i))
                {
                    tol += M[i];
                    left -= i;
                    break;
                }
            }
        }
        cnt += tol;
    }
    cout << cnt << endl;
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
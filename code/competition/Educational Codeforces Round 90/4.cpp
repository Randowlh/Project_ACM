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
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int dp[2100000];
void work()
{
    int tmp;
    vector<int> v, a, a2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int tol = 0;
    for (int i = 0; i < n; i += 2)
    {
        tol += v[i];
    }
    for (int i = 0; i + 1 < n; i += 2)
    {
        a.push_back(v[i + 1] - v[i]);
    }
    int ans = 0;
    if (!a.empty())
    {
        dp[0] = max(0LL, a[0]);
        for (int i = 1; i < a.size(); i++)
        {
            dp[i] = max(0LL, dp[i - 1] + a[i]);
        }
        for (int i = 0; i < a.size(); i++)
        {
            ans = max(ans, dp[i]);
        }
    }
    for (int i = 2; i < n; i += 2)
    {
        a2.push_back(v[i - 1] - v[i]);
    }
    int ans2 = -llinf;
    if (!a2.empty())
    {
        dp[0] = max(0LL, a2[0]);
        for (int i = 1; i < a2.size(); i++)
        {
            dp[i] = max(0LL, dp[i - 1] + a2[i]);
        }

        for (int i = 0; i < a2.size(); i++)
        {
            ans2 = max(ans2, dp[i]);
        }
    }
    tol += max(ans, ans2);
    cout << tol << endl;
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
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int dp[301000];
void work()
{
    int k, n;
    cin >> n >> k;
    int tmp;
    vector<int> v, bk;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            bk.push_back(0);
            continue;
        }
        if (v[i - 1] < v[i] && v[i] > v[i + 1])
            bk.push_back(1);
        else
            bk.push_back(0);
    }
    int now = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + 1 < n && bk[i + 1])
            now++;
        if (i + k - 1 < n && bk[i + k - 1] == 1)
            now--;
        dp[i] = now;
    }
    int mix = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > mx)
        {
            mx = dp[i];
            mix = i;
        }
    }
    cout << mx + 1 << ' ' << mix + 1 << endl;
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
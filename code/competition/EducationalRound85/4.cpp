#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n, l, r;
    cin >> n >> l >> r;
    int cnt = 1;
    int tol = 0;
    while (tol + n - cnt < l - 1)
    {
        tol += (n - cnt) * 2;
        cnt++;
    }
    // cout << cnt << endl;
    int now = (l - tol) % 2 + cnt + (l - tol) / 2;
    int f = (l - tol) % 2;
    vector<int> ans;
    for (int i = l; i < r; i++)
    {
        if (f == 1)
        {
            ans.push_back(cnt);
            f = 0;
        }
        else
        {
            ans.push_back(now);
            if (now == n)
            {
                cnt++;
                now = cnt + 1;
            }
            else
            {
                now++;
            }
            f = 1;
        }
    }
    if (cnt == n)
    {
        ans.push_back(1);
    }
    else
    {
        if (f == 1)
        {
            ans.push_back(cnt);
            f = 0;
        }
        else
        {
            ans.push_back(now);
            if (now == n)
            {
                cnt++;
                now = cnt + 1;
            }
            else
            {
                now++;
            }
            f = 1;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    pair<int, int> now;
    if (n % 2 == 1)
    {
        now.first = 1;
        now.second = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            now.second++;
            ans.push_back(now);
        }
        for (int q = 0; q < (n - 1) / 2; q++)
        {
            now.first++;
            int f = 1;
            for (int i = n + 1; i > 1; i--)
            {
                ans.push_back(now);
                now.second--;
                now.first += f;
                f = -f;
            }
            ans.push_back(now);
            now.first--;
            f = 1;
            for (int i = 1; i < n + 1; i++)
            {
                ans.push_back(now);
                now.second++;
                now.first += f;
                f = -f;
            }
            ans.push_back(now);
        }
    }
    else
    {
        now.first = n;
        now.second = 1;
        for (int i = n; i > 1; i--)
        {
            ans.push_back(now);
            now.first--;
        }
        ans.push_back(now);
        for (int q = 0; q < n / 2; q++)
        {
            now.second++;
            int f = 1;
            for (int i = n; i > 1; i--)
            {
                ans.push_back(now);
                now.first++;
                now.second += f;
                f = -f;
            }
            ans.push_back(now);
            now.second--;
            f = 1;
            for (int i = 1; i < n; i++)
            {
                ans.push_back(now);
                now.first--;
                now.second += f;
                f = -f;
            }
            ans.push_back(now);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
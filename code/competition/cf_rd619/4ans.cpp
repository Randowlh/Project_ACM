#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
vector<pair<int, char>> ans;
void work()
{
    int n, m, k;
    cin >> n >> m >> k;
    int tol = n * (m - 1) * 2 + m * (n - 1) * 2;
    if (k > tol)
    {
        cout << "NO" << endl;
        exit(0);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (m > 1)
            if (cnt + m - 1 >= k)
            {
                pair<int, char> x(k - cnt, 'R');
                ans.push_back(x);
                return;
            }
            else
            {
                pair<int, char> x(m - 1, 'R');
                ans.push_back(x);
                cnt += m - 1;
            }
        if (i == n - 1)
            break;
        if (m > 1)
            if (cnt + m - 1 >= k)
            {
                pair<int, char> x(k - cnt, 'L');
                ans.push_back(x);
                return;
            }
            else
            {
                pair<int, char> x(m - 1, 'L');
                ans.push_back(x);
                cnt += m - 1;
            }
        pair<int, char> x(1, 'D');
        ans.push_back(x);
        cnt++;
        if (cnt >= k)
            return;
    }
    for (int i = m; i > 0; i--)
    {
        if (n > 1)
            if (cnt + n - 1 >= k)
            {
                pair<int, char> x(k - cnt, 'U');
                ans.push_back(x);
                return;
            }
            else
            {
                pair<int, char> x(n - 1, 'U');
                ans.push_back(x);
                cnt += n - 1;
            }
        if (n > 1)
            if (cnt + n - 1 >= k)
            {
                pair<int, char> x(k - cnt, 'D');
                ans.push_back(x);
                return;
            }
            else
            {
                pair<int, char> x(n - 1, 'D');
                ans.push_back(x);
                cnt += n - 1;
            }
        pair<int, char> x(1, 'L');
        ans.push_back(x);
        cnt++;
        if (cnt >= k)
            return;
    }
    cout << "BUG" << endl;
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
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define ck        \
    if (cnt == k) \
    break
typedef long long ll;
struct node
{
    int t;
    string cmd;
};
void work()
{
    int n, m, k;
    cin >> n >> m >> k;
    ll tol = 2 * n * (m - 1) + 2 * m * (n - 1);
    if (tol < k)
    {
        cout << "NO" << endl;
        return;
    }
    int now = 0;
    int x = 0;
    int y = 0;
    int cnt = 0;
    vector<node> ans;
    while (y <= m - 1)
    {
        if (y == m - 1)
        {
            for (int i = 1; i < n; i++)
            {
                node x;
                x.cmd = "R";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
            }
            ck;
            for (int i = 1; i < n; i++)
            {
                node x;
                x.cmd = "L";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
            }
            ck;
            for (int i = 1; i < m; i++)
            {
                node x;
                x.cmd = "U";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
            }
            ck;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                node x;
                x.cmd = "R";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
                x.cmd = "D";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
                x.cmd = "U";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
            }
            ck;
            for (int i = 1; i < n; i++)
            {
                node x;
                x.cmd = "L";
                x.t = 1;
                ans.push_back(x);
                cnt++;
                ck;
            }
            ck;
        }
        ck;
        y++;
        node x;
        x.cmd = "D";
        x.t = 1;
        ans.push_back(x);
        cnt++;
        ck;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].t << ' ' << ans[i].cmd << endl;
    }
    return;
}
int main()
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
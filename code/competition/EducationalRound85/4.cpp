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
    int sum = 1;
    int nw = 2;
    int cnt = 1;
    while (sum + nw <= l)
    {
        cnt++;
        sum += nw;
        nw += 2;
    }
    vector<int> ans;
    int fl = 1;
    int res = l - sum;
    int pos = l - 1;
    cnt++;
    //  cout << "cnt=" << cnt << endl;
    //cout << "res=" << res << endl;
    if (res == 0)
    {
        ans.push_back(1);
        pos++;
        fl = 0;
        res = 2;
    }
    else if (res & 1)
        fl = 0;
    int now = 1 + (res / 2 + res & 1);
    while (pos < r)
    {
        pos++;
        if (fl == 0)
        {
            ans.push_back(cnt);
            fl = 1;
            continue;
        }
        if (now == cnt)
        {
            cnt++;
            ans.push_back(1);
            now = 2;
            fl = 0;
            continue;
        }

        fl = 0;
        ans.push_back(now);
        now++;
        continue;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
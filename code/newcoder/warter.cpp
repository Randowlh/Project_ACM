#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int n;
    int tmp;
    vector<int> v, vv, c;
    cin >> n;
    vv.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vv.push_back(tmp);
    }
    vv.push_back(0);
    int now = -llinf;
    n += 2;
    for (int i = 0; i < n; i++)
    {
        if (now != vv[i])
        {
            v.push_back(vv[i]);
            now = vv[i];
        }
    }
    n = v.size();
    now = 0;
    for (int i = 0; i < n; i++)
    {
        c.push_back(v[i] - now);
        now = v[i];
    }
    vector<pair<int, int>>
        ans;
    for (int i = 1; i < n - 1; i++)
    {
        if (c[i] > 0 && c[i + 1] < 0)
            ans.push_back(make_pair(v[i], -1));
        else if (c[i] < 0 && c[i + 1] > 0)
            ans.push_back(make_pair(v[i], 1));
    }
    int aa = 0;
    int tt = 0;
    sort(ans.begin(), ans.end());
    vector<pair<int, int>> anst;
    now = 0;
    int cnt = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (now != ans[i].first)
        {
            anst.push_back(make_pair(now, cnt));
            now = ans[i].first;
            cnt = ans[i].second;
        }
        else
        {
            cnt += ans[i].second;
        }
    }
    if (cnt != 0)
    {
        anst.push_back(make_pair(now, cnt));
    }
    for (int i = 0; i < anst.size(); i++)
    {
        // cout << anst[i].first << ' ' << anst[i].second << endl;
        tt += anst[i].second;
        aa = max(aa, tt);
    }
    cout << aa + 1 << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
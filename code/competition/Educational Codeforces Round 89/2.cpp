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
void work()
{
    int n, x, m;
    cin >> n >> x >> m;
    vector<pair<int, int>> v;
    pair<int, int> tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    int now = -1;
    for (int i = 0; i < m; i++)
    {
        if (v[i].first <= x && v[i].second >= x)
        {
            now = i;
            break;
        }
    }
    if (now == -1)
    {
        cout << 1 << endl;
        return;
    }
    pair<int, int> ans = v[now];
    for (int i = now + 1; i < m; i++)
    {
        if (v[i].first <= ans.second)
            ans.second = max(ans.second, v[i].second);
        if (v[i].second >= ans.first)
            ans.first = min(ans.first, v[i].first);
    }
    cout << ans.second - ans.first + 1 << endl;
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
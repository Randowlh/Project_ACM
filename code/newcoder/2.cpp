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
int n, k;
vector<pair<int, int>> v;
set<int> mp[60000];
int nxt[60000];
pair<int, int> tmp;
int sqr(int a, int b)
{
    if (max(abs(v[a].first - v[b].first), abs(v[a].second - v[b].second)) >= k)
        return 0;
    return (k - abs(v[a].first - v[b].first)) * (k - abs(v[a].second - v[b].second));
}
void work()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int now = n;
    int pr = v[n - 1].first;
    for (int i = n - 1; i >= 0; i--)
    {
        if (pr != v[i].first)
        {
            nxt[i] = i;
            now = i;
            pr = v[i].first;
        }
        else
            nxt[i] = now;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            //cout << i << "j=" << j << endl;
            if (abs(v[i].first - v[j].first) >= k)
                break;
            if (abs(v[i].second - v[j].second) >= k)
            {
                j = nxt[j];
                continue;
            }
            int t = sqr(i, j);
            if (t)
            {
                for (auto q = mp[j].begin(); q != mp[j].end(); q++)
                {
                    if (mp[i].count(*q))
                    {
                        cout << -1 << endl;
                        return;
                    }
                }
                mp[j].insert(i);
            }
            ans += t;
        }
    }
    cout << ans << endl;
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
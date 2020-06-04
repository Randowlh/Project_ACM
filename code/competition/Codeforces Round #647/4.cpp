#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
vector<int> mp[510000];
int mmp[510000];
void work()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    vector<pair<int, int>> an;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        an.push_back(make_pair(tmp, i + 1));
    }
    sort(an.begin(), an.end());
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (mmp[an[i].second] + 1 != an[i].first)
        {
            cout << -1 << endl;
            return;
        }
        ans.push_back(an[i].second);
        for (int j = 0; j < mp[an[i].second].size(); j++)
        {
            if (mmp[mp[an[i].second][j]] == an[i].first - 1)
            {
                mmp[mp[an[i].second][j]]++;
            }
        }
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
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
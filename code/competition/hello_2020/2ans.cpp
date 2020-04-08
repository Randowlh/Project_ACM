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
    vector<int> mi;
    vector<int> ma;
    vector<vector<int>> date;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        int tmp;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            t.push_back(tmp);
        }
        date.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int mii = inf;
        int maa = -1;
        int fl = 1;
        int pr = inf;
        for (int j = 0; j < date[i].size(); j++)
        {
            if (date[i][j] > pr)
            {
                cnt++;
                fl = 0;
                break;
            }
            pr = date[i][j];
            maa = max(maa, date[i][j]);
            mii = min(mii, date[i][j]);
        }
        if (fl)
        {
            ma.push_back(maa);
            mi.push_back(mii);
        }
    }
    int ans = 0;
    ans += 1ll * 2 * cnt * n - 1ll * cnt * cnt;
    sort(mi.begin(), mi.end());
    for (int i = 0; i < ma.size(); i++)
    {
        ans += lower_bound(mi.begin(), mi.end(), ma[i]) - mi.begin();
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
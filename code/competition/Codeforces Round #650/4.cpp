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
    int n;
    string tmp;
    string ans;
    cin >> n;
    ans.resize(n);
    cin >> tmp;
    vector<pair<int, int>> v;
    int tt;
    for (int i = 0; i < n; i++)
    {
        cin >> tt;
        v.push_back(make_pair(tt, i));
    }
    int nn = 0;
    sort(v.begin(), v.end());
    sort(tmp.begin(), tmp.end(), greater<char>());
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            int now = 0;
            for (int j = 0; j < i; j++)
            {
                if (tmp[nn] < ans[v[j].second])
                    now += abs(v[j].second - v[i].second);
            }
            cout << "dad" << endl;
            if (now == v[i].first)
            {
                ans[v[i].second] = tmp[nn];
                nn++;
                break;
            }
            nn++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
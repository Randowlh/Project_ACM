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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    int tmp;
    int sum = 0;
    int ma = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        sum += tmp;
        ma = max(ma, tmp);
        v.push_back(make_pair(tmp, i + 1));
    }
    if (sum < n)
    {
        cout << -1 << endl;
        return;
    }
    if (m > n)
    {
        cout << -1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<int> ans;
    ans.resize(m + 10);
    int cnt = m;
    int last = n;
    int f = 0;
    for (int i = 0; i < m; i++)
    {
        if (v[i].first + cnt - 1 < n)
        {
            ans[v[i].second - 1] = last - v[i].first + 1;
            last -= v[i].first;
            cnt += v[i].first - 1;
        }
        else
        {
            ans[v[i].second - 1] = m - i;
            last = m - i - 1;
            f = i + 1;
            break;
        }
    }
    for (int i = f; i < m; i++)
    {
        ans[v[i].second - 1] = last;
        last--;
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
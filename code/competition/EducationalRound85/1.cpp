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
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    pair<int, int> x;
    for (int i = 0; i < n; i++)
    {
        cin >> x.first >> x.second;
        v.push_back(x);
    }
    x.first = 0;
    x.second = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first < v[i].second)
        {
            cout << "NO" << endl;
            return;
        }
        if (v[i].first < x.first || v[i].second < x.second)
        {
            cout << "NO" << endl;
            return;
        }
        if (v[i].first - x.first < v[i].second - x.second)
        {
            cout << "NO" << endl;
            return;
        }
        x.first = v[i].first;
        x.second = v[i].second;
    }
    cout << "YES" << endl;
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
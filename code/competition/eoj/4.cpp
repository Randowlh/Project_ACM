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
int date[210000];
int find(int x)
{
    if (date[x] == x)
        return x;
    else
        return date[x] = find(date[x]);
}
void merge(int x, int y)
{
    int l = find(x);
    int r = find(y);
    if (l != r)
        date[l] = r;
}
void work()
{
    map<int, int> M;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        date[i] = i;
    vector<pair<int, int>> v;
    pair<int, int> x;
    for (int i = 0; i < m; i++)
    {
        cin >> x.first >> x.second;
        if (x.first < x.second)
            swap(x.first, x.second);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (find(v[i].first) != find(v[i].second))
        {

            M[v[i].first]++;
            M[v[i].second]++;
            merge(v[i].first, v[i].second);
        }
    }
    int ans = 0;
    for (auto j = M.begin(); j != M.end(); j++)
    {
        ans = max(ans, j->second);
    }
    cout << ans << endl;
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
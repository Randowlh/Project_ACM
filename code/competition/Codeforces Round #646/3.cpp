#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
vector<int> mp[1100];
int n, x;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void work()
{
    cin >> n >> x;
    int u, v;
    for (int i = 0; i <= n; i++)
    {
        mp[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    if (mp[x].size() <= 1)
    {
        cout << "Ayush" << endl;
    }
    else
    {
        if (n & 1)
        {
            cout << "Ashish" << endl;
        }
        else
        {
            cout << "Ayush" << endl;
        }
    }
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
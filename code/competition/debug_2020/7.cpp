#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int n, m;
    int tmp;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    if (n > 2 * m)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int ans = 1;
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                ans = ans * abs(v[i] - v[j]) % m;
            }
        }
        cout << ans << endl;
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
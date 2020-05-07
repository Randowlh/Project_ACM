#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int mp[210000];
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        mp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        mp[(i + v[i] % n + n) % n]++;
    }
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        if (mp[i] != 1)
        {
            f = 0;
            break;
        }
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
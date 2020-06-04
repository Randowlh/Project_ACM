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
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v, tt;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    tt.resize(n);
    for (int i = 1; i <= 1024; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tt[j] = v[j] ^ i;
        }
        sort(tt.begin(), tt.end());
        int f = 0;
        for (int j = 0; j < n; j++)
        {
            if (tt[j] != v[j])
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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
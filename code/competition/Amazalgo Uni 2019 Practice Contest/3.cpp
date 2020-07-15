#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int n;
    cin >> n;
    string tmp, tt;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        stringstream ss(tmp);
        int f = 0;
        while (ss >> tt)
        {
            if (!f && tt.size() > 1)
            {
                tt[0] -= 'A';
                tt[0] += 'a';
                tt[1] -= 'a';
                tt[1] += 'A';
            }
            for (int i = 1; i < tt.size(); i++)
            {
                cout << tt[i];
            }
            cout << tt[0] << "ay ";
            f = 1;
        }
        cout << endl;
    }
}
signed main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
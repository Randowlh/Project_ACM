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
int biao[][2] = {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
void work()
{
    int n;
    cin >> n;
    cout << 7 * (n + 1) + 1 << endl;
    cout << 0 << ' ' << 0 << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << biao[j][0] + i * 2 << ' ' << biao[j][1] + i * 2 << endl;
        }
    }
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
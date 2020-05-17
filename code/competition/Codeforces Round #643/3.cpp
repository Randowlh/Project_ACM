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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        for (int j = max(c + 1 - i, b); j <= c; j++)
        {
            if (i + j >= d + 1)
            {
                ans += 1ll * (c - j + 1) * (d - c + 1);
                break;
            }
            else
            {
                int temp = min(d - i, c);
                ans += 1ll * (i + j - c + i + temp - c) * (temp - j + 1) / 2;
                if (temp == c)
                    break;
                if (temp == d - i)
                    j = temp;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
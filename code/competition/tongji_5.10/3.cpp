#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    string tmp;
    cin >> tmp;
    double ans = 0;
    int now2 = 0;
    int fl = 0;
    int now = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] >= '0' && tmp[i] <= '9')
        {
            if (fl)
            {
                now2 *= 10;
                now2 += tmp[i] - '0';
            }
            else
            {
                now *= 10;
                now += tmp[i] - '0';
            }
        }
        if (tmp[i] == 'd')
            fl = 1;
        if (tmp[i] == '+')
        {
            if (fl == 0)
                ans += now;
            else
                ans += (double)now * (double)(now2 + 1) / 2.0;
            fl = 0;
            now = 0;
            now2 = 0;
        }
    }
    if (fl == 0)
        ans += now;
    else
        ans += (double)now * (double)(now2 + 1) / 2.0;
    if (ans - (ll)ans < eps)
        printf("%d\n", (ll)ans);
    else
        printf("%.1f\n", ans);
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
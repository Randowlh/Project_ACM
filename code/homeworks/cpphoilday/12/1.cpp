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
class ws
{
public:
    int now;
    bool ck()
    {
        if (now == 1)
            return false;
        int tol = 1;
        for (int i = 2; i * i <= now; i++)
        {
            if (now % i == 0)
            {
                tol += i;
                if (i * i != now)
                {
                    tol += now / i;
                }
            }
        }
        return tol == now;
    }
} tmp;
void work()
{
    int mix = 0;
    int ans = 0;
    int cnt = 1;
    int tol = 0;
    while (cin >> tmp.now)
    {
        if (tmp.ck())
        {
            if (!ans)
            {
                ans = cnt;
                mix = tmp.now;
            }
            tol++;
        }
        cnt++;
    }
    cout << tol << endl;
    if (tol)
    {
        cout << ans << "	" << mix << endl;
    }
    else
        cout << "none" << endl;
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
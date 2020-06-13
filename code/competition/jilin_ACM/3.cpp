#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const int maxn = 1000010;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int pr[1000100];
void pre()
{
    for (int i = 1; i <= maxn; i++)
    {
        for (int j = 1; j * i <= maxn; j++)
        {
            pr[j * i] += i;
        }
    }
}
inline int zhiyinshu(int x)
{
    int ans = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans += i;
            if (i * i != x)
                ans += x / i;
        }
    }
    return ans;
}

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int biao[1000100];
void work()
{
    int n;
    pre();
    biao[0] = 0;
    biao[1] = 1;
    for (register int i = 2; i <= maxn; i++)
    {
        biao[i] = biao[i - 1] + pr[i];
    }
    cin >> n;
    int l, r;
    for (int j = 0; j < n; j++)
    {
        cin >> l >> r;
        cout << biao[r] - biao[l - 1] << endl;
    }
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
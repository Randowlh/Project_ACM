#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
const ll mod = 1000000007;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int cn[1000100];
#define int long long
int pows(int x, int a)
{
    int ans = 1;
    int now = x;
    while (a != 0)
    {
        if (a & 1)
        {
            ans = ans * now % mod;
        }
        now = now * now % mod;
        a >>= 1;
    }
    return ans;
}

void work()
{
    register int i;
    int n, p;
    cin >> n >> p;
    int tmp;
    vector<int> v;
    int ma = 0;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        ma = max(ma, tmp);
    }
    if (p == 1)
    {
        cout << n % 2 << endl;
        return;
    }
    for (i = 0; i <= ma + 70; i++)
    {
        cn[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cn[v[i]]++;
    }
    int now = ma;
    int ans = 0;
    while (now >= 0)
    {
        if (cn[now] % 2 == 0)
        {
            now--;
            continue;
        }
        else
        {
            ans = pows(p, now);
            for (i = now - 1; i >= 0; i--)
            {
                if (cn[i])
                {
                    ans = (ans - (cn[i] * pows(p, i)) % mod) % mod;
                    ans += mod;
                    ans %= mod;
                }
            }
            break;
        }
    }
    cout << (ans + mod) % mod << endl;
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
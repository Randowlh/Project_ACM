#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
const ll mod = 1000000007;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const ll mod2 = 999998639;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int cn[1000100];
#define int long long
int pows(int x, int a, int mod)
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
    int n, p;
    cin >> n >> p;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (ans1 == 0 && ans2 == 0)
        {
            ans1 = pows(p, v[i], mod);
            ans2 = pows(p, v[i], mod2);
        }
        else
        {
            ans1 = (ans1 + mod - pows(p, v[i], mod)) % mod;
            ans2 = (ans2 + mod2 - pows(p, v[i], mod2)) % mod2;
        }
    }
    cout << ans1 << endl;
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
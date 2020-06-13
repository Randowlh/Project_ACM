#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (1 ? 1000000007 : 998244353);
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
int tt[110000];
inline int pows(int x, int a)
{
    return tt[a];
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
int biaos[110000];

void work()
{
    tt[0] = 1;
    for (int i = 1; i < 100010; i++)
    {
        tt[i] = tt[i - 1] * 10 % mod;
    }
    int n;
    cin >> n;
    string tmp;
    for (int q = 0; q < n; q++)
    {
        cin >> tmp;
        int ans = 0;
        int now = 0;
        biaos[tmp.size()] = 0;
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            //cout << tmp[i];
            biaos[i] = (now + ((ll)(tmp[i] - '0') * pows(10, tmp.size() - 1 - i))) % mod;
            now = biaos[i];
            // cout << "i=" << i << ' ' << biaos[i] << endl;
        }
        now = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            //cout << "now=" << now << "tmp[i]=" << tmp[i] << endl;
            //cout << "pows" << pows(10, tmp.size() - 1 - i) << endl;
            int dis = 0;
            if (tmp[i] > '7')
            {
                dis = ((now + 1) * pows(10, tmp.size() - 1 - i)) % mod;
            }
            else if (tmp[i] == '7')
                dis = ((now)*pows(10, tmp.size() - 1 - i) + biaos[i + 1] + 1) % mod;
            else
                dis = ((now)*pows(10, tmp.size() - 1 - i)) % mod;
            ans = (ans + dis) % mod;
            // if (q == 5)
            //     cout << i << "dis=" << dis << endl;
            now = (now * 10 + tmp[i] - '0') % mod;
        }
        cout << ans << endl;
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
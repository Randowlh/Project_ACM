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
// int date[210000];
// int lowbit(int x) { return x & -x }
// int query(int x)
// {
//     int ans = 0;
//     while (x)
//     {
//         ans += date[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// void update(int x, int v)
// {
//     while (x <= 210000)
//     {
//         date[x] += v;
//         x += lowbit(x);
//     }
// }
void work()
{
    int n, x;
    cin >> n >> x;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int bg = 0;
    int ed = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        now += v[i];
        if (now > x)
        {
            ed = i;
            break;
        }
    }
    int ma = ed - bg;
    int mix = 0;
    for (int i = 1; i < n; i++)
    {
        bg++;
        now -= v[bg - 1];
        while (now < x)
        {
            ed += 1;
            ed %= n;
            now += v[ed];
        }
        int dis;
        if (ed < bg || (bg == ed && v[ed] < x))
        {
            dis = ed + n - bg;
        }
        else
            dis = ed - bg;
        if (ma > dis)
        {
            ma = dis;
            mix = bg;
        }
    }
    int ans = 0;
    int i = ed;
    while (true)
    {
        if (v[i] >= x)
        {
            for (int i = v[i]; i > v[i] - x; i--)
            {
                ans += i;
            }
            break;
        }
        x -= v[i];
        ans += v[i] * (v[i] + 1) / 2;
        i++;
        i += n;
        i %= n;
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
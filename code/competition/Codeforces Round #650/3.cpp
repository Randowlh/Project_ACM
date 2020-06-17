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
int tree[210000];
inline int lowbit(int x) { return x & -x; }
int n, k;
void update(int x, int v)
{
    while (x <= n)
    {
        tree[x] += v;
        x += lowbit(x);
    }
}
int query(int x)
{
    if (x >= n)
        x = n;
    if (x <= 0)
        return 0;
    int ans = 0;
    while (x >= 1)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
string tmp;
bool ck(int x)
{
    // if (x <= 0 || x > tmp.size() + 1)
    //     return false;
    return true;
}
void work()
{

    cin >> n >> k;
    cin >> tmp;
    for (int i = 0; i <= n; i++)
    {
        tree[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i - 1] == '1')
        {
            update(i, 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i - 1] == '1')
            continue;
        if (ck(i - k - 1) && query(i) != query(i - k - 1))
            continue;
        if (ck(i + k) && query(i) != query(i + k))
            continue;
        ans++;
        update(i, 1);
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
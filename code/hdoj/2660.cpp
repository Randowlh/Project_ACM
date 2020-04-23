#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n, k, a, b, tw;
vector<int> v, w;
int ans = -inf;
void dfs(int step, int now, int nowv, int noww)
{
    if (noww > tw)
        return;
    if (step == k)
    {
        ans = max(ans, nowv);
        return;
    }
    for (int i = now + 1; i <= n - k + step; i++)
        dfs(step + 1, i, nowv + v[i], noww + w[i]);
    return;
}
void work()
{
    v.clear();
    w.clear();
    ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(a);
        w.push_back(b);
    }
    cin >> tw;
    for (int i = 0; i <= n - k; i++)
    {
        dfs(1, i, v[i], w[i]);
    }
    cout << ans << endl;
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
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
ll dp[3100][3100];
ll n, h, l, r;
vector<ll> v;
ll dfs(ll a, ll b)
{
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    if (a >= n)
    {
        if (b >= l && b <= r)
            return 1;
        else
            return 0;
    }
    ll ans;
    ans = dfs(a + 1, (v[a] + b + h) % h);
    ans = max(ans, dfs(a + 1, (v[a] - 1 + b + h) % h));
    if (b <= r && b >= l)
    {
        ans++;
    }
    dp[a][b] = ans;
    return ans;
}
void work()
{

    cin >> n >> h >> l >> r;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i <= 2010; i++)
        for (int j = 0; j <= 2010; j++)
            dp[i][j] = -1;
    int f = 0;
    if (l == 0)
        f++;
    cout << dfs(0, 0) + f << endl;
    return;
}
int main()
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
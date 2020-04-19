#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
vector<int> mp[100100];
vector<int> dpt[100100];
int p[100100];
int c[100100];
int fa[100100];
int cnt[100100];
bool book[100100];
bool vis[100100];
void work()
{
    int n;
    scanf("%lld", &n);
    for (int i = 0; i <= n; i++)
    {
        dpt[i].clear();
        cnt[i] = 0;
        vis[i] = 0;
        book[i] = 0;
        mp[i].clear();
    }
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lld%lld", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    fa[1] = 1;
    queue<pair<int, int>> q2;
    q2.push(make_pair(1, 0));
    vis[1] = 1;
    int ma = 0;
    while (!q2.empty())
    {
        pair<int, int> x = q2.front();
        dpt[x.second].push_back(x.first);
        ma = max(ma, x.second);
        q2.pop();
        for (int i = 0; i < mp[x.first].size(); i++)
        {
            int &t = mp[x.first][i];
            if (!vis[t])
            {
                fa[t] = x.first;
                q2.push(make_pair(t, x.second + 1));
                vis[t] = 1;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &p[i], &c[i]);
        if (mp[i].size() == 1 && i != 1)
        {
            cnt[i] = 1;
            q.push(i);
        }
    }
    if (p[1] - c[1] > 0)
    {
        printf("NO\n");
        return;
    }
    for (int i = ma; i > 0; i--)
    {
        for (int j = 0; j < dpt[i].size(); j++)
        {
            int &t = dpt[i][j];
            c[fa[t]] -= max(0LL, p[t] - c[t]);
        }
    }
    if (p[1] - c[1] > 0)
    {
        printf("NO\n");
        return;
    }
    else
        printf("YES\n");
}
signed main()
{
    //   freopen("in.txt", "r", stdin);
    int t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        work();
    }
    return 0;
}
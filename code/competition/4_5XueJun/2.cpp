#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
vector<int> mp[2100];
pair<int, int> prize[2100];
int G[2010][2010];
int book[2100];
int n;
void bfs(int s)
{
    for (int i = 0; i <= n; i++)
        book[i] = 0;
    book[s] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(s, (int)0));
    G[s][s] = 0;
    while (!q.empty())
    {
        int t = q.front().first;
        int tt = q.front().second;
        q.pop();
        for (int i = 0; i < mp[t].size(); i++)
        {
            if (!book[mp[t][i]])
            {
                G[mp[t][i]][s] = tt + 1;
                G[s][mp[t][i]] = tt + 1;
                q.push(make_pair(mp[t][i], tt + 1));
                book[mp[t][i]] = 1;
            }
        }
    }
}
void work()
{
    //int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &prize[i].first);
        prize[i].second = i;
    }
    int w, v;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lld%lld", &w, &v);
        mp[w].push_back(v);
        mp[v].push_back(w);
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    int ans = 0;
    sort(prize + 1, prize + n + 1);
    reverse(prize + 1, prize + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            ans = max(ans, G[prize[i].second][prize[j].second] * prize[i].first);
    }
    cout << ans << endl;
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
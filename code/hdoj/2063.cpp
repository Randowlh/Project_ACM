#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int k, n, m;
int mp[510][510];
int ans = 0;
int pr[510];
int book[510];
bool dfs(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (mp[x][i] && !book[i])
        {
            book[i] = 1;
            if (pr[i] == -1 || dfs(pr[i]))
            {
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
    ans = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 1; i <= m; i++)
    {
        memset(book, 0, sizeof(book));
        if (dfs(i))
        {
            ans++;
        }
    }
    return;
}
void work()
{
    while (cin >> k)
    {
        if (!k)
            break;
        cin >> m >> n;
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a][b] = 1;
        }
        xyl();
        cout << ans << endl;
    }
}
int main()
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
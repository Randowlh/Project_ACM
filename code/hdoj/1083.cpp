#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define bug puts("here!!!")
int n, p;
int mp[510][510];
int pr[510];
int book[510];
int ans = 0;
bool dfs(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (mp[x][i] == 1 && book[i] == 0)
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
void work()
{
    cin >> p >> n;
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= p; i++)
    {
        int k;
        cin >> k;
        int tmp;
        for (int j = 1; j <= k; j++)
        {
            cin >> tmp;
            mp[i][tmp] = 1;
        }
    }
    ans = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 1; i <= p; i++)
    {
        memset(book, 0, sizeof(book));
        if (dfs(i))
        {
            ans++;
        }
    }
    //cout << ans << endl;
    if (ans == p)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}
int main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
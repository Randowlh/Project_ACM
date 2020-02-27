#include <bits/stdc++.h>
using namespace std;
int mp[510][510];
int book[510];
vector<int> ans;
int n, m;
bool dfs(int x)
{
    book[x] = -1;
    for (int i = n; i >= 1; i--)
    {
        if (mp[x][i])
        {
            if (book[i] == -1)
            {
                return false;
            }
            else
            {
                if (!book[i])
                {
                    dfs(i);
                }
            }
        }
    }
    book[x] = 1;
    ans.push_back(x);
    return true;
}
bool Toposort()
{
    ans.clear();
    memset(book, 0, sizeof(book));
    for (int i = n; i >= 1; i--)
    {
        if (!book[i])
        {
            if (!dfs(i))
                return false;
        }
    }
    reverse(ans.begin(), ans.end());
    return true;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (cin >> n >> m)
    {
        memset(mp, 0, sizeof(mp));
        int w, u;
        for (int i = 0; i < m; i++)
        {
            cin >> w >> u;
            mp[w][u] = 1;
        }
        Toposort();
        for (int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << ans[ans.size() - 1] << endl;
    }
}
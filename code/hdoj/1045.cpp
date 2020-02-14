#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int x, y;
    bool operator==(node a) const
    {
        if (x == a.x && y == a.y)
            return true;
        else
            return false;
    }
} nu;
node pr[10][10];
int book[10][10];
int mp[10][10];
int ans = 0;
int n;
bool check(int x, int y, int i, int j)
{
    if (mp[i][j])
        return false;
    if (x != i && j != y)
    {
        return true;
    }
    if (x == i && y == j)
    {
        return false;
    }
    if (y == j)
    {
        int fl = 0;
        for (int k = min(x, i); k <= max(x, i); k++)
        {
            if (mp[k][j])
            {
                fl = 1;
                break;
            }
        }
        return fl;
    }
    else
    {
        int fl = 0;
        for (int k = min(y, j); k <= max(y, j); k++)
        {
            if (mp[x][k])
            {
                fl = 1;
                break;
            }
        }
        return fl;
    }
}
bool dfs(int x, int y)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!book[i][j] && check(x, y, i, j))
            {
                book[i][j] = 1;
                if (pr[i][j] == nu || dfs(i, j))
                {
                    node q;
                    q.x = x;
                    q.y = y;
                    pr[i][j] = q;
                    return true;
                }
            }
        }
    return false;
}
void xyl()
{
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pr[i][j] = nu;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memset(book, 0, sizeof(book));
            if (dfs(i, j))
            {
                ans++;
            }
        }
    }
    return;
}
void work()
{
    //int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        char c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                if (c == 'X')
                {
                    mp[i][j] = 1;
                }
                else
                    mp[i][j] = 0;
            }
        }
        xyl();
        cout << ans << endl;
    }
    return;
}
int main()
{
    nu.x = -1;
    nu.y = -1;
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
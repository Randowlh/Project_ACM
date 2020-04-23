#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n, m, s;
char mp[1010][1010];
int book[1010][1010];
map<char, int> M;
int b[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int x, int y)
{
    int tx = x + b[M[mp[x][y]]][0];
    int ty = y + b[M[mp[x][y]]][1];
    if (tx < 0 || ty < 0 || tx >= n || ty >= m)
    {
        cout << book[x][y] << " step(s) to exit" << endl;
        return;
    }
    if (book[tx][ty])
    {
        cout << book[tx][ty] - 1 << " step(s) before a loop of " << book[x][y] - book[tx][ty] + 1 << " step(s)" << endl;
        return;
    }
    book[tx][ty] = book[x][y] + 1;
    dfs(tx, ty);
    return;
}
void work()
{
    M['W'] = 3;
    M['E'] = 1;
    M['S'] = 0;
    M['N'] = 2;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        cin >> s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                book[i][j] = 0;
                cin >> mp[i][j];
            }
        book[0][s - 1] = 1;
        dfs(0, s - 1);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
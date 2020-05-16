#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const int llinf = 9223372036854775807LL;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int m, n, tt;
char a[1100][1100];
int dis[1100][1100];
int biao[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
inline int ck(int x, int y)
{
    for (int i = 0; i < 4; i++)
        if (x + biao[i][0] < n && x + biao[i][0] >= 0 && y + biao[i][1] < m && y + biao[i][1] >= 0)
            if (a[x][y] == a[x + biao[i][0]][y + biao[i][1]])
                return 0;
    return llinf;
}
inline bool ck2(int x, int y)
{
    if (x < 0 || x > n)
        return false;
    if (y < 0 || y > m)
        return false;
    return dis[x][y] == llinf;
}
void work()
{
    cin >> n >> m >> tt;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = ck(i, j);
            if (!dis[i][j])
                q.push(make_pair(i, j));
        }
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (ck2(t.first + biao[i][0], t.second + biao[i][1]))
            {
                dis[t.first + biao[i][0]][t.second + biao[i][1]] = dis[t.first][t.second] + 1;
                q.push(make_pair(t.first + biao[i][0], t.second + biao[i][1]));
            }
        }
    }
    //cout << dis[0][0] << endl;
    int x, y, c;
    for (int i = 0; i < tt; i++)
    {
        // cout << "dadad" << endl;
        cin >> x >> y >> c;
        // cout << x << " " << y << " " << c << endl;
        x--;
        y--;
        if (c <= dis[x][y])
            cout << a[x][y] << endl;
        else
        {
            // cout << "??" << endl;
            cout << (c - dis[x][y] + a[x][y] - '0') % 2 << endl;
        }
    }
}
signed main()
{
    //cout << LONG_LONG_MAX << endl;
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
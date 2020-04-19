#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
bool mp[1010][1010];
bool book[1010][1010];
int n, m, k;
int b[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct node
{
    int x, y, t;
    node(int xx, int xy, int xt) : x(xx), y(xy), t(xt) {}
    bool operator<(node a)
    {
        if (x == a.x)
            return y < a.y;
        else
            return x < a.x;
    }
};
bool ck2(int x, int y)
{
    if (x > n || x < 1)
        return false;
    if (y > m || y < 1)
        return false;
    return true;
}
bool ck(int x, int y)
{
    if (x > n || x < 1)
        return false;
    if (y + 1 > m || y < 1)
        return false;
    if (mp[x][y] == 1)
        return false;
    if (mp[x][y + 1] == 1)
        return false;
    return true;
}
void output(pair<int, int> ans)
{
    if (ans.first == 0 && ans.second == 0)
        cout << -1 << endl;
    else
        cout << '(' << ans.first << ',' << ans.second << ") (" << ans.first << ',' << ans.second + 1 << ")" << endl;
}
void work()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            mp[i][j] = 0;
            book[i][j] = 0;
        }
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    pair<int, int> ans(0, 0);
    if (ck((n + 1) / 2, m / 2))
    {
        ans.first = (n + 1) / 2;
        ans.second = m / 2;
        output(ans);
        return;
    }
    vector<node> an;
    book[(n + 1) / 2][m / 2] = 1;
    queue<node> q;
    q.push(node((n + 1) / 2, m / 2, 0));
    int mx = inf;
    while (!q.empty())
    {
        node t = q.front();
        //  cout << t.x << ' ' << t.y << ' ' << t.t << ' ' << "test" << endl;
        q.pop();
        if (ck(t.x, t.y) && t.t <= mx)
        {
            mx = t.t;
            an.push_back(node(t.x, t.y, t.t));
        }
        for (int i = 0; i < 4; i++)
        {

            if (!ck2(t.x + b[i][0], t.y + b[i][1]))
                continue;
            if (t.t > mx)
                continue;
            if (book[t.x + b[i][0]][t.y + b[i][1]] == 1)
                continue;
            book[t.x + b[i][0]][t.y + b[i][1]] = 1;
            q.push(node(t.x + b[i][0], t.y + b[i][1], t.t + 1));
        }
    }
    /// cout << ck(3, 1) << "cl" << endl;
    sort(an.begin(), an.end());
    //cout << an.size() << endl;
    if (an.empty())
    {
        cout << -1 << endl;
    }
    else
        output(make_pair(an[0].x, an[0].y));
    return;
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
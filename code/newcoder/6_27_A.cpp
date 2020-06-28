#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
struct node
{
    int x, y, t;
    node(int xx, int yy, int tt) : x(xx), y(yy), t(tt) {}
};
int b[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
char mp[110][110];
int tail = 1;
int mmp[110][110];
int dis[110][110];
int dp[1 << 16];
int r, c;
pair<int, int> ct[110];
inline bool ck(int x, int y)
{
    if (x < 0 || x >= r)
        return false;
    if (y < 0 || y >= c)
        return false;
    return true;
}
void bfs1(int x, int y, int num)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    mmp[x][y] = num;
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (ck(t.first + b[i][0], t.second + b[i][1]) && mmp[t.first + b[i][0]][t.second + b[i][1]] == 0 && mp[t.first + b[i][0]][t.second + b[i][1]] == 'X')
            {
                mmp[t.first + b[i][0]][t.second + b[i][1]] = num;
                q.push(make_pair(t.first + b[i][0], t.second + b[i][1]));
            }
        }
    }
}
void bfs2(int num)
{
    int book[101][101];
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= c; j++)
        {
            book[i][j] = 0;
        }
    queue<node> q;
    queue<pair<int, int>> tq;
    tq.push(ct[num]);
    q.push(node(ct[num].first, ct[num].second, 0));
    book[ct[num].first][ct[num].second] = 1;
    while (!tq.empty())
    {
        pair<int, int> t = tq.front();
        tq.pop();
        for (int i = 0; i < 4; i++)
        {
            if (ck(t.first + b[i][0], t.second + b[i][1]) && mmp[t.first + b[i][0]][t.second + b[i][1]] == num && !book[t.first + b[i][0]][t.second + b[i][1]])
            {
                book[t.first + b[i][0]][t.second + b[i][1]] = 1;
                q.push(node(t.first + b[i][0], t.second + b[i][1], 0));
                tq.push(make_pair(t.first + b[i][0], t.second + b[i][1]));
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> t(q.front().x, q.front().y);
        int times = q.front().t;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (ck(t.first + b[i][0], t.second + b[i][1]) && !book[t.first + b[i][0]][t.second + b[i][1]]) // && mp[t.first + b[i][0]][t.second + b[i][1]] != '.')
            {
                if (mmp[t.first + b[i][0]][t.second + b[i][1]])
                    dis[num][mmp[t.first + b[i][0]][t.second + b[i][1]]] = min(dis[num][mmp[t.first + b[i][0]][t.second + b[i][1]]], times);
                book[t.first + b[i][0]][t.second + b[i][1]] = 1;
                q.push(node(t.first + b[i][0], t.second + b[i][1], times + 1));
            }
        }
    }
}
int dfs(int now, int s)
{
    // cout << now << endl;
    if (dp[now] != -1)
        return dp[now];
    int ans = llinf;
    for (int i = 0; i < tail - 1; i++)
    {
        if ((now & (1 << i)) == 0)
        {
            ans = min(ans, dis[s][i + 1] + dfs(now | (1 << i), i + 1));
        }
    }
    dp[now] = ans;
    return ans;
}
void work()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mp[i][j];
        }
    }
    memset(mmp, 0, sizeof(mmp));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mmp[i][j] == 0 && mp[i][j] == 'X')
            {
                bfs1(i, j, tail);
                ct[tail].first = i;
                ct[tail].second = j;
                tail++;
            }
        }
    }
    for (int i = 1; i < tail; i++)
        for (int j = 1; j < tail; j++)
            dis[i][j] = llinf;
    for (int i = 1; i < tail; i++)
        bfs2(i);
    for (int i = 0; i < (1 << tail - 1); i++)
        dp[i] = -1;
    dp[(1 << (tail - 1)) - 1] = 0;
    int ans = llinf;
    for (int i = 1; i < tail; i++)
    {
        ans = min(ans, dfs(1 << (i - 1), i));
    }
    cout << ans << endl;
}
signed main()
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

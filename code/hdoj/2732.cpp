#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
class DC
{
public:
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    int book[2010];
    int cur[2010];
    int depth[2010];
    int n, m, t, s;
    int cnt = 0;
    vector<Edge> edge;
    vector<int> mp[2010];
    int bfs(int s, int t)
    {
        memset(book, 0, sizeof(book));
        queue<int> q;
        q.push(s);
        book[s] = 1;
        depth[s] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < mp[now].size(); i++)
            {
                Edge &e = edge[mp[now][i]];
                if (!book[e.to] && e.cap > e.flow)
                {
                    depth[e.to] = depth[e.from] + 1;
                    book[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return book[t];
    }
    int dfs(int now, int a)
    {
        if (now == t || a == 0)
            return a;
        int flow = 0;
        int f;
        for (int &i = cur[now]; i < mp[now].size(); i++)
        {
            Edge &e = edge[mp[now][i]];
            if (depth[now] + 1 == depth[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                flow += f;
                edge[mp[now][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int Dinic()
    {
        int ans = 0;
        while (bfs(s, t))
        {
            memset(cur, 0, sizeof(cur));
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
} fl;
char mp[100][100];
int mmp[100][100];
int cnt = 0;
void work()
{
    cnt++;
    cout << "Case #" << cnt << ": ";
    int n, d;
    cin >> n >> d;
    int m;
    string tmp;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        m = tmp.size();
        for (int j = 0; j < m; j++)
        {
            mmp[i][j] = tmp[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        m = tmp.size();
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = tmp[j];
        }
    }
    fl.s = 0;
    fl.t = 1004;
    fl.edge.clear();
    for (int i = 0; i <= 2000; i++)
    {
        fl.mp[i].clear();
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'L')
            {
                total++;
                fl.add_edge(0, i * m + j + 1, 1);
            }
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mmp[i][j])
            {
                fl.add_edge(i * m + j + 1, i * m + j + 1 + 500, mmp[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mmp[i][j])
            {
                if ((i - d < 0) || (j - d < 0) || (i + d >= n) || (j + d >= m))
                {
                    fl.add_edge(i * m + j + 1 + 500, 1004, inf);
                }
                for (int x = max(i - d, (int)0); x <= min(i + d, n - 1); x++)
                    for (int y = max(j - d, (int)0); y <= min(j + d, m - 1); y++)
                    {
                        if ((x == i) && (j == y))
                            continue;
                        if (mmp[x][y] == 0)
                            continue;
                        if (abs(x - i) + abs(y - j) <= d)
                            fl.add_edge(i * m + j + 1 + 500, x * m + 1 + y, inf);
                    }
            }
    int ans = fl.Dinic();
    total -= ans;
    if (total == 0)
    {
        cout << "no lizard was left behind." << endl;
    }
    else if (total == 1)
    {
        cout << "1 lizard was left behind." << endl;
    }
    else
        cout << total << " lizards were left behind." << endl;
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
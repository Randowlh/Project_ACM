#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
char mp[100][100];
bool book[100][100];
int n, m;
bool ck(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}
int biao[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int cnt = 0;
void work()
{
    int tol = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mp[i][j] == 'G')
                tol++;
            else if (mp[i][j] == 'B')
                for (int k = 0; k < 4; k++)
                    if (ck(i + biao[k][0], j + biao[k][1]))
                        if (mp[i + biao[k][0]][j + biao[k][1]] == 'G')
                        {
                            out(0);
                            return;
                        }
                        else if (mp[i + biao[k][0]][j + biao[k][1]] == 'B')
                            continue;
                        else
                            mp[i + biao[k][0]][j + biao[k][1]] = '#';
    memset(book, 0, sizeof(book));
    if (mp[n - 1][m - 1] == '#')
    {
        out(tol == 0);
        return;
    }
    queue<pair<int, int>> q;
    book[n - 1][m - 1] = 1;
    q.push(make_pair(n - 1, m - 1));
    int cnt = 0;
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (ck(t.first + biao[i][0], t.second + biao[i][1]) && book[t.first + biao[i][0]][t.second + biao[i][1]] == 0 && mp[t.first + biao[i][0]][t.second + biao[i][1]] != '#')
            {
                if (mp[t.first + biao[i][0]][t.second + biao[i][1]] == 'G')
                    cnt++;
                q.push(make_pair(t.first + biao[i][0], t.second + biao[i][1]));
                book[t.first + biao[i][0]][t.second + biao[i][1]] = 1;
            }
        }
    }
    out(tol == cnt);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
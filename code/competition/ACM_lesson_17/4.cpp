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
int biao[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char mp[110][110];
int book[110][110];
int n, m;
int x1, x2, yf, y2;
bool ck(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}
void work()
{

    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
            }
        memset(book, 0, sizeof book);
        cin >> x1 >> yf >> x2 >> y2;
        x1--;
        yf--;
        x2--;
        y2--;
        queue<pair<int, int>> q;
        mp[x1][yf] = 1;
        q.push(make_pair(x1, yf));
        while (!q.empty())
        {
            pair<int, int> t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (ck(t.first + biao[i][0], t.second + biao[i][1]) && book[t.first + biao[i][0]][t.second + biao[i][1]] == 0)
                {
                    if (mp[t.first + biao[i][0]][t.second + biao[i][1]] == '.')
                    {
                        book[t.first + biao[i][0]][t.second + biao[i][1]] = book[t.first][t.second] + 1;
                        q.push(make_pair(t.first + biao[i][0], t.second + biao[i][1]));
                    }
                    else if (ck(t.first + biao[i][0] * 2, t.second + biao[i][1] * 2) && book[t.first + biao[i][0] * 2][t.second + biao[i][1] * 2] == 0 && mp[t.first + biao[i][0] * 2][t.second + biao[i][1] * 2] == '.')
                    {
                        book[t.first + biao[i][0] * 2][t.second + biao[i][1] * 2] = book[t.first][t.second] + 1;
                        q.push(make_pair(t.first + biao[i][0] * 2, t.second + biao[i][1] * 2));
                    }
                }
            }
        }
        if (book[x2][y2])
        {
            cout << book[x2][y2] << endl;
        }
        else
            cout << -1 << endl;
    }
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
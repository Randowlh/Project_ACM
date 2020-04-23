#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
char mp[1100][1100];
int date[110000];
int n, m;
int b[][2] = {{1, 1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}};
int find(int x)
{
    if (date[x] == x)
        return x;
    date[x] = find(date[x]);
    return date[x];
}
bool ck(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return mp[x][y] == '@';
}
void merge(int a, int b)
{
    int l = find(a);
    int r = find(b);
    if (l == r)
        return;
    else
        date[l] = r;
}
void work()
{
    while (cin >> n >> m, n + m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                date[i * m + j] = i * m + j;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 8; k++)
                    if (mp[i][j] == '@' && ck(i + b[k][0], j + b[k][1]))
                        merge(i * m + j, (i + b[k][0]) * m + j + b[k][1]);
        set<int> s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] == '@')
                    s.insert(find(i * m + j));
        cout << s.size() << endl;
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
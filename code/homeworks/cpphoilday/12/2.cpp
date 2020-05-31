#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int date[210000];
int find(int x)
{
    if (date[x] == x)
        return x;
    else
        return date[x] = find(date[x]);
}
void merge(int i, int j)
{
    int l = find(i);
    int r = find(j);
    if (l != r)
        date[l] = r;
}
int n, m;
int biao[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool ck(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}
vector<vector<int>> mp;
void work()
{
    cin >> n >> m;
    mp.resize(n);
    for (int i = 0; i < n; i++)
        mp[i].resize(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            date[i * m + j] = i * m + j;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 4; k++)
                if (ck(i + biao[k][0], j + biao[k][1]) && mp[i][j] == mp[i + biao[k][0]][j + biao[k][1]])
                    merge(i * m + j, (i + biao[k][0]) * m + j + biao[k][1]);
    set<int> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s.insert(find(i * m + j));
    cout << s.size() << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
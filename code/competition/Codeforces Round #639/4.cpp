#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
char mp[1010][1010];
int date[1101000];
int find(int x)
{
    if (date[x] == x)
        return x;
    else
        return date[x] = find(date[x]);
}
void merge(int a, int b)
{
    int l = find(a);
    int r = find(b);
    if (l != r)
        date[l] = r;
}
void work()
{
    int flag = 0;
    int ff1 = 0;
    int ff2 = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            date[i * m + j] = i * m + j;
            cin >> mp[i][j];
        }
    for (int i = 0; i < n; i++)
    {
        int f = 0;
        for (int j = 0; j < m; j++)
        {
            if (f == 1 && mp[i][j] == '.')
                f++;
            if (mp[i][j] == '#')
            {
                if (j != m - 1)
                {
                    if (mp[i][j + 1] == '#')
                        merge(i * m + j, i * m + j + 1);
                }
                if (!f)
                    f++;
                else if (f == 2)
                {
                    cout << "-1" << endl;
                    return;
                }
            }
        }
        if (!f)
        {
            ff1 = 1;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (f == 1 && mp[i][j] == '.')
                f++;
            if (mp[i][j] == '#')
            {
                if (i != n - 1)
                {
                    if (mp[i + 1][j] == '#')
                        merge(i * m + j, (i + 1) * m + j);
                }
                if (!f)
                    f++;
                else if (f == 2)
                {
                    cout << "-1" << endl;
                    return;
                }
            }
        }
        if (!f)
        {
            ff2 = 1;
        }
    }
    if (ff1 ^ ff2)
    {
        cout << -1 << endl;
        return;
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '#')
                s.insert(find(date[i * m + j]));
        }
    }
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
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int fa[210000];
vector<int> mp[210000];
int n, root;
vector<int> qst(int x)
{
    vector<int> aa;
    if (mp[x].size() == 1)
    {
        aa.push_back(x);
        return aa;
    }
    while (mp[x].size() == 2)
    {
        for (int i = 0; i < mp[x].size(); i++)
        {
            if (mp[x][i] != fa[x])
            {
                x = mp[x][i];
                break;
            }
        }
    }
    if (mp[x].size() == 1)
    {
        aa.push_back(x);
        return aa;
    }
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] != fa[x])
        {
            vector<int> a = qst(mp[x][i]);
            for (int j = 0; j < a.size(); j++)
            {
                aa.push_back(a[j]);
            }
        }
    }
    return aa;
}
void dfs(int x)
{
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (fa[x] == mp[x][i])
            continue;
        fa[mp[x][i]] = x;
        dfs(mp[x][i]);
    }
}
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void work()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        int a, b;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a].push_back(b);
            mp[b].push_back(a);
            // cout << a << ' ' << b << endl;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i].size() >= 2)
            {
                root = i;
            }
            else
                ans++;
        }
        fa[root] = -1;
        printf("%d\n", ans / 2 + ans % 2);
        dfs(root);
        vector<int> aa = qst(root);
        for (int i = 0; i + 1 < aa.size(); i += 2)
        {
            printf("%d %d\n", aa[i], aa[aa.size() / 2 + i]);
        }
        if (aa.size() % 2 == 1)
        {
            printf("%d %d\n", aa[aa.size() - 1], root);
        }
    }
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
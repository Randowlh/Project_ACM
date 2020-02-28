#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll tree_arr[56][50010];
int tmp[50010];
int mp[20][20];
inline int lowbit(int x) { return x & -x; }

void update(int x, int l, ll v)
{
    while (l <= n)
    {
        tree_arr[x][l] += v;
        l += lowbit(l);
    }
    return;
}
void add_range(int x, int l, int r, int v)
{
    update(x, l, v);
    update(x, r + 1, -v);
}
ll merge(int x, int l)
{
    ll ans = 0;
    while (l >= 1)
    {
        ans += tree_arr[x][l];
        l -= lowbit(l);
    }
    return ans;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int cnt = 0;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            //  cout << i << "->" << j << "->" << cnt << endl;
            mp[i][j] = cnt;
            cnt++;
        }
    }
    while (scanf("%d", &n) == 1)
    {
        memset(tree_arr, 0, sizeof(tree_arr));
        int pr = 0;
        int t;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            tmp[i] = t - pr;
            pr = t;
        }
        for (int i = 1; i <= n; i++)
        {
            update(0, i, tmp[i]);
        }
        int m;
        scanf("%d", &m);
        int a, b, c, d, e;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            if (a == 2)
            {
                ll ans = 0;
                for (int i = 1; i <= 10; i++)
                {
                    ans += merge(mp[i][b % i], b);
                }
                printf("%lld\n", ans);
            }
            else
            {
                scanf("%d%d%d", &c, &d, &e);
                add_range(mp[d][b % d], b, c, e);
            }
        }
    }
    return 0;
}
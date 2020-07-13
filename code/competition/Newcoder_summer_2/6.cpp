#include <bits/stdc++.h>
using namespace std;
int n, m = 0, tot = 0, root, fa[200005], que[200005], ans[200005][2];
vector<int> e[200005];
void dfs(int x)
{
    int i, sz = e[x].size();
    que[++tot] = x;
    for (i = 0; i < sz; i++)
        if (e[x][i] ^ fa[x])
        {
            fa[e[x][i]] = x;
            dfs(e[x][i]);
        }
}
int main()
{
    int i, j, x, y, sz;
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (n < 3)
    {
        if (n == 1)
            printf("0\n");
        else
            printf("1\n1 2\n");
        return 0;
    }
    for (i = 1; i <= n; i++)
        if (e[i].size() > 1)
            break;
    root = i;
    dfs(root);
    i = 1;
    j = n;
    while (i <= j)
    {
        while (i < j && e[que[i]].size() > 1)
            i++;
        while (i < j && e[que[j]].size() > 1)
            j--;
        ans[++m][0] = que[i];
        ans[m][1] = (i ^ j ? que[j] : root);
        i++;
        j--;
    }
    printf("%d\n", m);
    for (i = 1; i <= m; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}

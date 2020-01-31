#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))

using namespace std;

const int maxn = 130;

int ans;
bool g[maxn][maxn];
int some[maxn][maxn], none[maxn][maxn];
int all[maxn][maxn];

void dfs(int cur, int sz, int sn, int nn)
{
    if (!sn && !nn)
        ans++;
    if (ans > 1000)
        return;
    int key = some[cur][1];
    range(i, 1, sn)
    {
        int v = some[cur][i], tsn = 0, tnn = 0;
        if (g[key][v])
            continue;
        range(j, 1, sz) all[cur + 1][j] = all[cur][j];
        all[cur + 1][sz + 1] = v;
        range(j, 1, sn) if (g[v][some[cur][j]]) some[cur + 1][++tsn] = some[cur][j];
        range(j, 1, nn) if (g[v][none[cur][j]]) none[cur + 1][++tnn] = none[cur][j];
        dfs(cur + 1, sz + 1, tsn, tnn);
        some[cur][i] = 0, none[cur][++nn] = v;
    }
}

int main()
{
    int u, v, n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        fill(g, false), ans = 0;
        while (m--)
        {
            scanf("%d %d", &u, &v);
            g[u][v] = g[v][u] = true;
        }
        range(i, 1, n) some[1][i] = i;
        dfs(1, 0, n, 0);
        if (ans > 1000)
            puts("Too many maximal sets of friends.");
        else
            printf("%d\n", ans);
    }
    return 0;
}
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <string>
#include <iostream>
#include <queue>
#include <math.h>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include <time.h>
#define left (now << 1)
#define right ((now << 1) + 1)
#define mid ((l + r) >> 1)
#define midmid ((r + mid) >> 1)
#define LONG_LONG_MIN -9223372036854775808ll
#define LONG_LONG_MAX 9223372036854775807ll
using namespace std;
typedef long long int ll;

const int MAXN = 70;

struct Point
{
    int x, y;
};

int dis[MAXN][MAXN], g[MAXN][MAXN], cnum[MAXN];
int l, r, k2, num, cans;
int n;
Point a[MAXN];
vector<int> p, k;

int getdis(Point x, Point y)
{
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}

bool dfs(int step, int *R, int Rlen)
{
    int R2[MAXN], R2len;
    if (step > cans)
    {
        cans = step;
        return true;
    } //剪枝3
    for (int i = 1; i <= Rlen; ++i)
    {
        if (step + n - R[i] + 1 <= cans)
        {
            break;
        } //剪枝1
        if (step + cnum[R[i]] <= cans)
        {
            break;
        } //剪枝2
        R2len = 0;
        for (int j = i + 1; j <= Rlen; ++j)
        {
            if (g[R[i]][R[j]])
            {
                R2[++R2len] = R[j];
            }
        }
        if (dfs(step + 1, R2, R2len))
        {
            return true;
        }
    }
    return false;
}

void maxClique()
{
    int R[MAXN], Rlen = 0;
    cans = 1;
    cnum[n] = 1;
    for (int i = n - 1; i >= 1; --i)
    {
        Rlen = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            if (g[i][j])
            {
                R[++Rlen] = j;
            }
        }
        dfs(1, R, Rlen);
        cnum[i] = cans;
    }
}

bool pd(int now)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (dis[i][j] >= now)
            {
                g[i][j] = g[j][i] = 1;
            }
            else
            {
                g[i][j] = g[j][i] = 0;
            }
        }
    }
    maxClique();
    return cans >= k2;
}

int main()
{
    while (scanf("%d%d", &n, &k2) != EOF)
    {
        p.clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                dis[i][j] = dis[j][i] = getdis(a[i], a[j]);
                p.push_back(dis[i][j]);
            }
        }
        p.push_back(INT_MAX);
        sort(p.begin(), p.end());
        l = 0;
        r = p.size() - 1;
        while (l < r)
        {
            if (pd(p[mid]))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        --l;
        //printf("%d\n",getdis(a[2],a[3]));
        double ans = sqrt(p[l]);
        printf("%.2f\n", ans);
    }
    return 0;
}
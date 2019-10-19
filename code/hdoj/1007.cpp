#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;
int min(int a, int b)
{
    if (a <= b)
        return a;
    return b;
}
int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}
double min(double a, double b)
{
    if (a <= b)
        return a;
    return b;
}
double max(double a, double b)
{
    if (a >= b)
        return a;
    return b;
}
#define N 100100

struct node
{
    double x, y;
} g[N];

node save[N];

int cmp(node t, node t1)
{
    return t.x < t1.x;
}

int cmp1(node t, node t1)
{
    return t.y < t1.y;
}
double cal(node t, node t1)
{
    return sqrt((t.x - t1.x) * (t.x - t1.x) + (t.y - t1.y) * (t.y - t1.y));
}

double fuc(int b, int d)
{
    if (d - b == 1)
        return cal(g[b], g[d]);
    if (d - b == 2)
    {
        return min(cal(g[b], g[b + 1]), min(cal(g[b], g[d]), cal(g[b + 1], g[d])));
    }
    int mid = (b + d) / 2;
    double mi = min(fuc(b, mid), fuc(mid + 1, d));
    for (int i = mid - 1; i >= b; i--)
    {
        if (g[mid].x - g[i].x > mi)
        {
            b = i;
            break;
        }
    }
    for (int i = mid; i <= d; i++)
    {
        if (g[i].x - g[mid - 1].x > mi)
        {
            d = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = b; i <= d; i++)
        save[cnt++] = g[i];
    sort(save, save + cnt, cmp1);
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++)
        {
            if (save[j].y - save[i].y > mi)
                break;
            if (cal(save[i], save[j]) < mi)
                mi = cal(save[i], save[j]);
        }
    return mi;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &g[i].x, &g[i].y);
        }
        sort(g, g + n, cmp);
        printf("%.2lf\n", fuc(0, n - 1) / 2);
    }
    return 0;
}
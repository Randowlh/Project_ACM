#include <stdio.h>
#include <math.h>
#include <string.h>
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int x[1000];
int y[1000];
int flag[1000];
//int lx[1000];
int tail;
int n;
int k;
int tm[1000];
int ans[1000];
double mi = 1 << 29;
double tol = 0;
void dfs(int step)
{
    if (step == n - 1)
    {
        int tol = 0;
        for (int i = 1; i < n; i++)
        {
            tol += dis(x[tm[i]], y[tm[i]], x[tm[i - 1]], y[tm[i - 1]]);
        }
        if (tol > k && tol < mi)
        {
            mi = tol;
            for (int i = 0; i < n; i++)
            {
                ans[i] = tm[i];
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (flag[i] == 0)
        {
            tm[step] = i;
            dfs(step + 1);
        }
    }
    return;
}
int main()
{
    memset(flag, 0, sizeof(flag));
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    dfs(0);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d->", ans[i] + 1);
    }
    printf("%d\n", ans[n - 1] + 1);
    printf("%f\n", mi);
    return 0;
}
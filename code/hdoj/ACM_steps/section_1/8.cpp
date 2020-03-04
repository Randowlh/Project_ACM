#include <cstdio>
int main()
{
    int n, m;
    int tmp, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ans = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            ans += tmp;
        }
        printf("%d\n", ans);
        if (i == n - 1)
        {
            continue;
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
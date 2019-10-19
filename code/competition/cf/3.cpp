#include <cstdio>
int ans[310][310];
int main()
{
    int n;
    scanf("%d", &n);
    int now = n * n;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (flag == 0)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][i] = now;
                now--;
            }
            flag = 1;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                ans[j][i] = now;
                now--;
            }
            flag = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
#include <cstdio>
int dp[431000];
int v[431000];
int tail;
int main()
{
    //  freopen("in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
        {
            break;
        }
        tail = 0;
        int a, b;
        int tol = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &b, &a);
            tol += a * b;
            v[tail] = b;
            tail++;
            a--;
            while (a--)
            {
                v[tail] = v[tail - 1];
                tail++;
            }
        }
        int cnt = tol >> 1;
        for (int i = 0; i <= cnt; i++)
        {
            dp[i] = 0;
        }
        for (int i = 0; i < tail; i++)
        {
            for (int j = cnt; j >= v[i]; j--)
            {
                dp[j] = dp[j] > dp[j - v[i]] + v[i] ? dp[j] : dp[j - v[i]] + v[i];
            }
        }
        printf("%d %d\n", tol - dp[cnt], dp[cnt]);
    }
}

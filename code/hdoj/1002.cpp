#include <cstring>
#include <cstdio>
char a[1010], b[1010], c[1010];
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int k;
    scanf("%d", &k);
    for (int q = 1; q <= k; q++)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%s%s", a, b);
        memset(c, 0, sizeof(c));
        int tmp1 = strlen(a) - 1;
        int tmp2 = strlen(b) - 1;
        for (int i = 0; i <= max(tmp1, tmp2); i++)
        {
            if (tmp1 - i < 0)
            {
                c[i] = b[tmp2 - i] - '0';
            }
            else if (tmp2 - i < 0)
            {
                c[i] = a[tmp1 - i] - '0';
            }
            else
                c[i] = a[tmp1 - i] + b[tmp2 - i] - '0' - '0';
        }
        for (int i = 0; i <= max(tmp1, tmp2); i++)
        {
            if (c[i] >= 10)
            {
                c[i + 1] += c[i] / 10;
                c[i] = c[i] % 10 + '0';
            }
            else
            {
                c[i] = c[i] + '0';
            }
        }

        if (c[max(tmp1, tmp2) + 1] != 0)
        {
            c[max(tmp1, tmp2) + 1] += '0';
        }
        printf("Case %d:\n", q);
        printf("%s + %s = ", a, b);
        for (int i = strlen(c) - 1; i >= 0; i--)
        {
            printf("%c", c[i]);
        }
        printf("\n");
        if (k != q)
        {
            printf("\n");
        }
    }
    return 0;
}
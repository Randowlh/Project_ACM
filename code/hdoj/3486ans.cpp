#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 200000 + 5;
int n, a[maxn], mm[maxn][30], mi[maxn][30];
char str[1010];
long long int m;
void get_rmq()
{
    for (int i = 1; i <= n; i++)
        mm[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) <= n + 1; i++)
            mm[i][j] = max(mm[i][j - 1], mm[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r)
{
    int k = 0;
    while (1 << (k + 1) <= r - l + 1)
        k++;
    return max(mm[l][k], mm[r - (1 << k) + 1][k]);
}
int main()
{
    while (~scanf("%d %I64d", &n, &m))
    {
        if (n < 0 && m < 0)
            break;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        get_rmq();
        int t = rmq(1, n);
        int num = max(1, int((m + 1) / t));
        while (1 && num <= n)
        {
            //int all=n/num*num;
            long long int sum = 0;
            for (int i = 0; i < num; i++)
            {
                sum += rmq(i * (n / num) + 1, (i + 1) * (n / num));
                if (sum > m)
                    break;
            }
            if (sum > m)
                break;
            num++;
        }
        if (num > n)
            printf("-1\n");
        else
            printf("%d\n", num);
    }
    return 0;
}

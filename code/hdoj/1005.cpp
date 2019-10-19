#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1000];
int tail;
int a, b, n;
int main()
{
    while (true)
    {
        f[1] = 1;
        f[2] = 1;
        scanf("%d%d%d", &a, &b, &n);
        if (a == 0 && b == 0 && n == 0)
            return 0;
        for (int i = 3; i < 100; i++)
        {
            f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
        }
        if (n < 100)
        {
            printf("%d\n", f[n]);
            continue;
        }
        int flag1 = -1;
        int flag2 = -1;
        for (int i = 0; i < 50; i++)
        {
            for (int j = i + 1; j < 100; j++)
            {
                if (f[i] == f[j] && f[i + 1] == f[j + 1])
                {
                    flag1 = i;
                    flag2 = j;
                }
            }
        }
        n -= flag1;
        n %= flag2 - flag1;
        printf("%d\n", f[n + flag1]);
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, m;
    char a, b;
    int wifi[100];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < 4; j++)
        {
            scanf("%c-%c ", &a, &b);
            if (b == 'T')
            {
                switch (a)
                {
                case 'A':
                    wifi[i] = 1;
                    break;
                case 'B':
                    wifi[i] = 2;
                    break;
                case 'C':
                    wifi[i] = 3;
                    break;
                case 'D':
                    wifi[i] = 4;
                    break;
                }
            }
        }
    }
    for (m = 1; m <= n; m++)
        printf("%d", wifi[m]);
    return 0;
}

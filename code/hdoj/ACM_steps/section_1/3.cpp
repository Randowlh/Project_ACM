#include <cstdio>
int main()
{
    int a, b;
    while (true)
    {
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0)
        {
            return 0;
        }
        else
        {
            printf("%d\n", a + b);
        }
    }
    return 0;
}
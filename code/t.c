#include <stdio.h>
int stak[1000];
int top;
int tmp;
int main()
{
    top = 0;
    while (scanf("%d", &tmp) != EOF)
    {
        stak[top] = tmp;
        top++;
    }
    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d ", stak[i]);
    }
    return 0;
}
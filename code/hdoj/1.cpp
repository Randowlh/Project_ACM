#include <cstdio>
#include <cstring>
int main()
{
    char c = 'A';
    printf("%d %o %x", c);
    char tmp[100000];
    int flag[100000];
    memset(flag, 0, sizeof(flag));
    int n;
    scanf("%s", tmp);
    scanf("%d", &n);
    for (int i = 0; i < strlen(tmp) - 1; i++)
    {
        if (n > 0 && tmp[i] > tmp[i + 1])
        {
            flag[i] = 1;
            n--;
        }
    }
    if (n != 0)
    {
        for (int i = strlen(tmp) - 1; i >= 0 && n > 0; i--)
        {
            if (flag[i] == 0)
            {
                flag[i] = 1;
                n--;
            }
        }
    }
    int flag1 = 0;
    for (int i = 0; i < strlen(tmp); i++)
    {
        if (flag[i] == 0 && flag1 == 0)
        {
            if (tmp[i] != '0')
            {
                flag1 = 1;
                printf("%c", tmp[i]);
            }
            else
            {
                continue;
            }
        }
        else if (flag[i] == 0 && flag1 == 1)
        {
            printf("%c", tmp[i]);
        }
    }
    if (flag1 == 0)
    {
        printf("0");
    }
    printf("\n");
    return 0;
}
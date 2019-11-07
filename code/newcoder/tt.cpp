#include <cstdio>
#include <cstring>
struct node
{
    int na;
    int val;
} date[1000][1000];
int tail;
char in[100000];
int tails[1000];
int map[70000];
int main()
{
    gets(in);
    tail = 0;
    int l = strlen(in);
    for (int i = 0; i < l - 1; i++)
    {
        if (in[i] <= 'Z' && in[i] >= 'A')
        {
            if (in[i + 1] <= 'z' && in[i + 1] >= 'a')
            {
                i++;
                if (in[i + 1] <= 'Z' && in[i + 1] >= 'A')
                {
                    date[tail][tails[tail]].na = in[i - 1];
                    date[tail][tails[tail]].na <<= 8;
                    date[tail][tails[tail]].na += in[i];
                    date[tail][tails[tail]].val = 1;
                    tails[tail]++;
                    continue;
                }
                if (in[i + 1] == '(' || in[i + 1] == ')')
                {
                    date[tail][tails[tail]].na = in[i - 1];
                    date[tail][tails[tail]].na <<= 8;
                    date[tail][tails[tail]].na += in[i];
                    date[tail][tails[tail]].val = 1;
                    tails[tail]++;
                    continue;
                }
                int x = 0;
                date[tail][tails[tail]].na = in[i - 1];
                date[tail][tails[tail]].na <<= 8;
                date[tail][tails[tail]].na += in[i];
                i++;
                while (in[i] >= '0' && in[i] <= '9')
                {
                    x = x * 10 + in[i] - '0'; //将数字串变成整数
                    i++;
                }
                i--;
                
                date[tail][tails[tail]].val = x;
                tails[tail]++;
                continue;
            }
            else
            {
                if (in[i + 1] <= 'Z' && in[i + 1] >= 'A')
                {
                    date[tail][tails[tail]].na = in[i];
                    date[tail][tails[tail]].na <<= 8;
                    date[tail][tails[tail]].val = 1;
                    tails[tail]++;
                    continue;
                }
                if (in[i + 1] == '(' || in[i + 1] == ')')
                {
                    date[tail][tails[tail]].na = in[i];
                    date[tail][tails[tail]].na <<= 8;
                    date[tail][tails[tail]].val = 1;
                    tails[tail]++;
                    continue;
                }
                int x = 0;
                date[tail][tails[tail]].na = in[i];
                date[tail][tails[tail]].na <<= 8;
                i++;
                while (in[i] >= '0' && in[i] <= '9')
                {
                    x = x * 10 + in[i] - '0'; //将数字串变成整数
                    i++;
                }
                i--;
                date[tail][tails[tail]].val = x;
                tails[tail]++;
                continue;
            }
        }
        if (in[i] == '(')
        {
            tail++;
        }
        if (in[i] == ')')
        {
            if (in[i + 1] <= 'Z' && in[i + 1] >= 'A')
            {
                for (int i = 0; i < tails[tail]; i++)
                {
                    date[tail - 1][tails[tail - 1]].na = date[tail][i].na;
                    date[tail - 1][tails[tail - 1]].val = date[tail][i].val;
                    tails[tail - 1]++;
                }
                tail--;
            }
            else
            {
                int x = 0;
                i++;
                while (in[i] >= '0' && in[i] <= '9')
                {
                    x = x * 10 + in[i] - '0'; //将数字串变成整数
                    i++;
                }
                i--;
                for (int i = 0; i < tails[tail]; i++)
                {
                    date[tail - 1][tails[tail - 1]].na = date[tail][i].na;
                    date[tail - 1][tails[tail - 1]].val = date[tail][i].val * x;
                    tails[tail - 1]++;
                }
                tail--;
            }
        }
    }
    if (in[l - 1] <= 'z' && in[l - 1] >= 'a')
    {
        ;
    }
    else if (in[l - 1] <= 'Z' && in[l - 1] >= 'A')
    {
        date[tail][tails[tail]].na = in[l - 1];
        date[tail][tails[tail]].na <<= 8;
        date[tail][tails[tail]].val = 1;
    }
    memset(map, 0, sizeof(map));
    for (int i = 0; i <= tails[0]; i++)
    {
        map[date[0][i].na] += date[0][i].val;
    }
    for (int i = 0; i <= 65536; i++)
    {
        if (map[i] != 0)
        {
            if (i % 256 == 0)
            {
                printf("%c", i / 256);
                if (map[i] > 1)
                    printf("%d", map[i]);
            }
            else
            {
                printf("%c%c", i / 256, i % 256);
                if (map[i] > 1)
                printf("%d", map[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
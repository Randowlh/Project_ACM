#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int m[110][110], mp[110][110], w[110];
int s, e, n;
void Floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int cur = m[i][k] + m[k][j] + w[k];
                if (cur < m[i][j])
                    m[i][j] = cur, mp[i][j] = mp[i][k];
                else if (cur == m[i][j])
                {
                    if (mp[i][j] > mp[i][k])
                    {
                        mp[i][j] = mp[i][k];
                    }
                }
            }
        }
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        int data;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &data);
                if (data == -1)
                    m[i][j] = inf;
                else
                    m[i][j] = data;
                mp[i][j] = j;
            }
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        Floyd();
        while (scanf("%d%d", &s, &e))
        {
            if (s == -1 && e == -1)
                break;
            printf("From %d to %d :\n", s, e);
            printf("Path: %d", s);
            int temp = s;
            while (temp != e)
            {
                temp = mp[temp][e];
                printf("-->%d", temp);
            }
            printf("\nTotal cost : %d\n\n", m[s][e]);
        }
    }
    return 0;
}

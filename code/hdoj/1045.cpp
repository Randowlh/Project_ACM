#include <bits/stdc++.h>
using namespace std;
int pr[110];
int mp[110][110];
int n;
int he[110][110], shu[110][110];
char rd[110][110];
int ans = 0;
int book[110];
int cntm;
bool dfs(int x)
{
    for (int i = 1; i <= cntm; i++)
    {
        if (mp[x][i] && !book[i])
        {
            book[i] = 1;
            if (pr[i] == 0 || dfs(pr[i]))
            {
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
    memset(pr, 0, sizeof(pr));
    for (int i = 1; i <= cntm; i++)
    {
        memset(book, 0, sizeof(book));
        if (dfs(i))
        {
            ans++;
        }
    }
    return;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> rd[i][j];
            }
        }
        int cnt = 0;
        memset(mp, 0, sizeof(mp));
        memset(he, 0, sizeof(he));
        memset(shu, 0, sizeof(shu));
        for (int i = 0; i < n; i++)
        {
            cnt++;
            int f = 0;
            for (int j = 0; j < n; j++)
            {
                if (rd[i][j] == '.')
                {
                    if (f && j > 0 && rd[i][j - 1] == 'X')
                        cnt++;
                    f = 1;
                    he[i][j] = cnt;
                }
            }
        }
        cntm = cnt;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt++;
            int f = 0;
            for (int j = 0; j < n; j++)
            {
                if (rd[j][i] == '.')
                {
                    if (f && j > 0 && rd[j - 1][i] == 'X')
                        cnt++;
                    f = 1;
                    shu[j][i] = cnt;
                }
            }
        }
        cntm = max(cntm, cnt);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (he[i][j] && shu[i][j])
                {
                    mp[shu[i][j]][he[i][j]] = 1;
                }
            }
        }
        ans = 0;
        xyl();
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFF;
int t;
int mp[1010][1010], mp1[1010][1010], in[1010];
void work(int x)
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &in[i]);
    in[n + 1] = 0;
    scanf("%d", &m);
    memset(mp, -1, sizeof(mp));
    memset(mp1, 0, sizeof(mp1));
    int w, u;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &w, &u);
        mp[w][u] = in[u];
        mp1[w][u] = u;
    }

    for (int k = 1; k <= n + 1; k++)
    {
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                if (mp[i][k] != -1 && mp[k][j] != -1 && mp[i][j] < mp[i][k] + mp[k][j])
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                    mp1[i][j] = mp1[i][k];
                }
            }
        }
    }

    cout << "CASE " << x << "#" << endl;
    cout << "points : " << mp[1][n + 1] << endl;
    cout << "circuit : ";
    int s = 1, e = n + 1;
    while (s != e)
    {
        printf("%d->", s);
        s = mp1[s][e];
    }
    printf("%d\n", 1);
    if (x != t)
        printf("\n");
}
int main()
{
    freopen("in.txt", "r", stdin);
    //  int t;
    // cout<<"no"<<endl;
    cin >> t;
    int tmp = t;
    while (tmp > 0)
    {
        tmp--;
        //cout<<"yes"<<endl;
        work(t - tmp);
    }

    return 0;
}
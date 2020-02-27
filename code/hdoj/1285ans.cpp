#include <bits/stdc++.h>
using namespace std;
int book[510];
int mp[510][510];
int n, m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> m)
    {
        memset(mp, 0, sizeof(mp));
        memset(book, 0, sizeof(book));
        int u, w;
        for (int i = 0; i < m; i++)
        {
            cin >> w >> u;
            if (mp[w][u] == 0)
                book[u]++;
            mp[w][u] = 1;
        }
        int cnt = 0;
        vector<int> ans;
        while (cnt < n)
        {
            for (int i = 1; i <= n; i++)
            {
                if (book[i] == 0)
                {
                    book[i] = -1;
                    for (int j = 1; j <= n; j++)
                    {
                        if (mp[i][j])
                        {
                            mp[i][j] = 0;
                            book[j]--;
                        }
                    }
                    cnt++;
                    ans.push_back(i);
                    break;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << ans[n - 1] << endl;
    }
    return 0;
}
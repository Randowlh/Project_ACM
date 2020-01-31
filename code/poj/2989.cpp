#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> t;
int mp[200][200];
int n;
int ct;
bool check(int step)
{
    for (int i = 0; i < t.size(); i++)
        if (mp[t[i]][step] == 0)
        {
            return false;
        }
    return true;
}
void dfs()
{
    while (ct < n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (check(i))
            {
                
            }
            {
            }
        }
    }
}
int cnt = 0;
int flag[200];
void work()
{
    // int n;
    int m;
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                mp[i][j] = 0;
            flag[i] = 1;
        }
        int w, u;
        for (int i = 0; i < m; i++)
        {
            mp[w][u] = 1;
            mp[u][w] = 1;
        }
        ct = 0;
        cnt = 0;
        dfs();
        cout << cnt << endl;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    work();
    return 0;
}
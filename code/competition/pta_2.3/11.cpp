#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int v, e, k;
int mp[550][550];
int c[550];
bool bfs()
{
    int book[550];
    for (int i = 0; i <= v; i++)
    {
        book[i] = 0;
    }
    int s = 1;
    while (true)
    {
        queue<int> q;
        q.push(s);
        book[s] = 1;
        while (!q.empty())
        {  
            for (int i = 1; i <= v; i++)
            {
                if (q.front() != i && mp[q.front()][i] == 1)
                {
                    if (book[i] == 1)
                    {
                        if (c[q.front()] == c[i])
                        {
                            return false;
                        }
                    }
                    else
                    {
                        book[i] = 1;
                        if (c[q.front()] == c[i])
                        {
                            return false;
                        }
                        q.push(i);
                    }
                }
            }
            q.pop();
        }
        int fl = 1;
        for (int i = 1; i <= v; i++)
        {
            if (book[i] == 0)
            {
                fl = 0;
                s = i;
                break;
            }
        }
        if (fl == 1)
            break;
    }
    return true;
}
void work()
{
    cin >> v >> e >> k;
    int u, w;
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < e; i++)
    {
        cin >> u >> w;
        mp[u][w] = 1;
        mp[w][u] = 1;
    }
    int n;
    cin >> n;
    for (int q = 0; q < n; q++)
    {
        set<int> s;
        s.clear();
        for (int i = 1; i <= v; i++)
        {
            cin >> c[i];
            s.insert(c[i]);
        }
        if (s.size() > k)
        {
            cout << "No" << endl;
        }
        else if (bfs())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
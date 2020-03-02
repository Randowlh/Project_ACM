#include <bits/stdc++.h>
using namespace std;
const int inf = 100000;
struct edge
{
    int w, u, v;
};
vector<edge> v;
int n, m;
int dis[30000];
int Bellman_ford(int s, int e)
{
    memset(dis, 1000000, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            dis[v[j].u] = min(dis[v[j].u], dis[v[j].w] + v[j].v);
        }
    }
    return dis[e];
}
int main()
{
    int s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        edge x;
        cin >> x.w >> x.u >> x.v;
        v.push_back(x);
        swap(x.w, x.u);
        v.push_back(x);
    }
    cout << Bellman_ford(s, t) << endl;
    return 0;
}
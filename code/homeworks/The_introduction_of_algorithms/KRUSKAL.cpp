#include <bits/stdc++.h>
using namespace std;
int n, m;
int date[10000];
struct edge
{
    int w, u, v;
    bool operator<(const edge a) const
    {
        return v < a.v;
    }
};
int find(int x)
{
    if (date[x] == x)
    {
        return x;
    }
    else
    {
        date[x] = find(date[x]);
        return date[x];
    }
}
void merge(int a, int b)
{
    int l = find(a);
    int r = find(b);
    if (l == r)
        return;
    else
        date[l] = r;
    return;
}
vector<edge> v;
int ans;
void Kruskal()
{
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++)
    {
        date[i] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (find(v[i].w) != find(v[i].u))
        {
            ans = v[i].v;
            merge(v[i].w, v[i].u);
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        edge x;
        cin >> x.w >> x.u >> x.v;
        v.push_back(x);
    }
    Kruskal();
    cout << n - 1 << ' ' << ans << endl;
    return 0;
}
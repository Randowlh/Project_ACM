#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int date[100010];
int n, m;
struct node
{
    int x, y;
    bool operator<(node a) const
    {
        if (x == a.x)
            return y < a.y;
        else
            return x < a.x;
    }
};
set<node> s;
set<int> bk;
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
    {
        return;
    }
    else
        date[l] = r;
    return;
}
void dfs(int x)
{   
    cout<<"Yes"<<endl;
    set<int>::iterator iter = bk.begin();
    while (iter != bk.end())
    {
        if (find(x) != find(*iter))
        {
            node k;
            k.x = x;
            k.y = *iter;
            if (!s.count(k))
            {
                merge(x, *iter);
                int a = *iter;
                bk.erase(*iter);
                dfs(a);
            }
        }
        ++iter;
    }
    return;
}
void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        node a;
        scanf("%d%d", &a.x, &a.y);
        s.insert(a);
        swap(a.x, a.y);
        s.insert(a);
    }
    for (int i = 1; i <= n; i++)
    {
        date[i] = i;
        bk.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (bk.count(i))
        {
            bk.erase(i);
            dfs(i);
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(find(i));
    }
    printf("%d\n", s.size() - 1);
    return;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
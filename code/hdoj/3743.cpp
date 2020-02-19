#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node
{
    int x;
    int y;
    bool operator<(node a)
    {
        return x < a.x;
    }
};
bool cmp(node a, node b)
{
    return a.y < b.y;
}
int tree[1000100];
int lowbit(int x)
{
    return x & -x;
}
void update(int x, int v)
{
    while (x <= n)
    {
        tree[x] += v;
        x += lowbit(x);
    }
}
ll query(int x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    while (cin >> n)
    {
        int t;
        vector<node> v;
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            node x;
            x.x = t;
            x.y = i;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            v[i].x = i + 1;
        }
        sort(v.begin(), v.end(), cmp);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans + query(n) - query(v[i].x - 1);
            update(v[i].x, 1);
        }
        cout << ans << endl;
    }
    return 0;
}
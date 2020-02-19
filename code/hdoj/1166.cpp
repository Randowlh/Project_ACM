#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tree[500000];
int n;
int cnt = 0;
int lowbit(int x)
{
    return x & -x;
}
int update(int x, int v)
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
ll add_range(int l, int r)
{
    return query(r) - query(l - 1);
}
void work()
{
    cnt++;
    int t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tree[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        update(i, t);
    }
    cout << "Case " << cnt << ":" << endl;
    string tmp;
    while (cin >> tmp)
    {
        if (tmp == "End")
        {
            break;
        }
        int a, b;
        if (tmp == "Query")
        {
            cin >> a >> b;
            cout << add_range(a, b) << endl;
        }
        else if (tmp == "Add")
        {
            cin >> a >> b;
            update(a, b);
        }
        else
        {
            cin >> a >> b;
            update(a, -b);
        }
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
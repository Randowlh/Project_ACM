#include <bits/stdc++.h>
using namespace std;
int n, m;
int tree_arr[500100];
int lowbit(int x)
{
    return x & -x;
}
void update(int x, int v)
{
    while (x <= n)
    {
        tree_arr[x] += v;
        x += lowbit(x);
    }
    return;
}
long long qianzhui(int a)
{
    long long ans = 0;
    while (a != 0)
    {
        ans += tree_arr[a];
        a -= lowbit(a);
    }
    return ans;
}
long long quer(int l, int r)
{
    return qianzhui(r) - qianzhui(l - 1);
}
int main()
{
    cin >> n >> m;
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        update(i, t);
    }
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b, c);
        }
        else
            cout << quer(b, c) << endl;
    }
    return 0;
}
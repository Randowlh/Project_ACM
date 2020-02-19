#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tree[33000];
inline int lowbit(int x) { return x & -x; }
void update(int x, int v)
{
    x++;
    while (x < 33000)
    {
        tree[x] += v;
        x += lowbit(x);
    }
    return;
}
ll query(int x)
{
    x++;
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
    int n;
    while (cin >> n)
    {
        memset(tree, 0, sizeof(tree));
        int x, y;
        int arr[15100];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            int t = query(x);
            arr[t]++;
            update(x, 1);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}
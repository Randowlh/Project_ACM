#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x;
    ll v;
    bool operator<(node a)
    {
        return x < a.x;
    }
};
inline int lowbit(int x) { return x & -x; }
int n;
ll tree[210000][2];
node date[210000];
int ls[210000];
void update(int x, ll v)
{
    while (x <= n)
    {
        tree[x][0] += v;
        tree[x][1]++;
        x += lowbit(x);
    }
    return;
}
ll query(int x, int flag)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += tree[x][flag];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &date[i].x);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &date[i].v);
        ls[i + 1] = date[i].v;
    }
    sort(date, date + n);
    sort(ls + 1, ls + n + 1);
    int len = unique(ls + 1, ls + n + 1) - ls - 1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int lo = lower_bound(ls + 1, ls + 1 + len, date[i].v) - ls;
        ans += date[i].x * query(lo, 1) - query(lo, 0);
        update(lo, date[i].x);
    }
    cout << ans << endl;
    return 0;
}
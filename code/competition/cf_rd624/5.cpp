#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int x;
    int v;
    bool operator<(node a)
    {
        return v < a.v;
    }
};
int n;
ll tree[500000];
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
node x[200010];
void work()
{
    cin >> n;
    vector<node> z, f;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].v;
    }
    sort(x + 1, x + n + 1);
    vector<int> date;
    date.push_back(0);
    int pr = 0;
    for (int i = 1; i <= n; i++)
    {
        date.push_back(x[i].x - pr);
        pr = x[i].x;
    }
    for (int i = 1; i < n; i++)
    {
        update(i, date[i + 1]);
    }
    ll tol = 0;
    for (int i = 2; i <= n; i++)
    {

        tol += query(i - 1);
        // cout << query(i) << endl;
    }
    cout << tol << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
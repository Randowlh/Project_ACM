#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tree[1100][1100];
inline ll lowbit(ll x) { return x & -x; }
ll query(int x, int y)
{
    x++;
    y++;
    ll ans = 0;
    while (x > 0)
    {
        int nowy = y;
        while (nowy > 0)
        {
            ans += tree[x][nowy];
            nowy -= lowbit(nowy);
        }
        x -= lowbit(x);
    }
    return ans;
}
void update(int x, int y, int v)
{
    x++;
    y++;
    while (x <= 1010)
    {
        int nowy = y;
        while (nowy <= 1010)
        {
            tree[x][nowy] += v;
            nowy += lowbit(nowy);
        }
        x += lowbit(x);
    }
    return;
}
int cnt = 0;
void work()
{ //Case 1:
    cnt++;
    cout << "Case " << cnt << ":" << endl;
    for (int i = 0; i <= 1010; i++)
    {
        for (int j = 0; j <= 1010; j++)
        {
            tree[i][j] = lowbit(i) * lowbit(j);
        }
    }
    int n;
    cin >> n;
    char ts;
    ll a, b, c, d, e;
    for (int i = 0; i < n; i++)
    {
        cin >> ts;
        if (ts == 'S')
        {
            cin >> a >> b >> c >> d;
            if (a > c)
            {
                swap(a, c);
            }
            if (b > d)
            {
                swap(b, d);
            }
            cout << query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1) << endl;
        }
        else if (ts == 'A')
        {
            cin >> a >> b >> c;
            update(a, b, c);
        }
        else if (ts == 'D')
        {
            cin >> a >> b >> c;
            ll v = min(query(a, b) - query(a - 1, b) - query(a, b - 1) + query(a - 1, b - 1), c);
            update(a, b, -v);
        }
        else if (ts == 'M')
        {
            cin >> a >> b >> c >> d >> e;
            ll v = min(query(a, b) - query(a - 1, b) - query(a, b - 1) + query(a - 1, b - 1), e);
            update(a, b, -v);
            update(c, d, v);
        }
    }
    return;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
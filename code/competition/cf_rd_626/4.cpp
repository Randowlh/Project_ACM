#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10, maxc = (1 << 25) + 10;
int a[maxn], n, v;
bool c[maxc];
inline int lowbit(int x) { return x & (-x); }
void add(int x)
{
    while (x < v)
    {
        c[x] ^= 1;
        x += lowbit(x);
    }
}
bool query(int x)
{
    bool res = 0;
    while (x)
    {
        res ^= c[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int p = 0; p < 25; p++)
    {
        memset(c, 0, sizeof c);
        v = 1 << p;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >> p & 1)
                res++;
        }
        res = (res & 1) & ((n - res) & 1);
        for (int i = 1; i <= n; i++)
        {
            int pos = a[i] % v;
            if (pos)
            {
                res ^= query(v - 1) ^ query(v - pos - 1);
                add(pos);
            }
        }
        if (res)
            ans = ans | (1 << p);
    }
    cout << ans << "\n";
    return 0;
}
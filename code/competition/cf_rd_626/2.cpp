#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<ll> a, b;
    ll cnt = 0;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        if (tmp == 0)
        {
            if (cnt != 0)
            {
                a.push_back(cnt);
            }
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    if (cnt != 0)
    {
        a.push_back(cnt);
    }
    cnt = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &tmp);
        if (tmp == 0)
        {
            if (cnt != 0)
            {
                b.push_back(cnt);
            }
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    if (cnt != 0)
    {
        b.push_back(cnt);
    }
    cnt = 0;
    ll tk = k;
    vector<ll> yz;
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            yz.push_back(i);
            if (k / i != i)
            {
                yz.push_back(k / i);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < yz.size(); i++)
    {
        ll cnt1 = 0;
        ll cnt2 = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] >= yz[i])
            {
                cnt1 += (a[j] - yz[i] + 1);
            }
        }
        for (int j = 0; j < b.size(); j++)
        {
            if (b[j] >= k / yz[i])
            {
                cnt2 += (b[j] - k / yz[i] + 1);
            }
        }
        ans += cnt1 * cnt2;
    }
    printf("%lld\n", ans);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>> t;
    while (t--)
    {
        work();
    }
    return 0;
}
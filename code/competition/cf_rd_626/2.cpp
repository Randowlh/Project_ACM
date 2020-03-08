#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
ll ck(ll x, ll y, ll cx, ll cy)
{
    if (x < cx || y < cy)
    {
        return 0;
    }
    else
        return (x - cx + 1) * (y - cy + 1);
}
void work()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a, b;
    ll cnt = 0;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
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
        cin >> tmp;
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
    if (tk == 1)
    {
        yz.push_back(1);
    }
    else
    {
        for (ll i = 2; i * i <= tk; i++)
        {
            while (tk % i == 0)
            {
                yz.push_back(i);
                tk /= i;
            }
        }
        if (tk != 1)
        {
            yz.push_back(tk);
        }
    }
    vector<pair<ll, ll>> t;
    pair<ll, ll> x;
    tk = k;
    for (int i = 0; i < yz.size(); i++)
    {
        for (int j = i; j < yz.size(); j++)
        {
            ll now = 1;
            for (int q = i; q <= j; q++)
            {
                now *= yz[q];
                x.first = now;
                x.second = tk / now;
                if (x.first > x.second)
                {
                    swap(x.first, x.second);
                }
                t.push_back(x);
            }
        }
    }
    sort(t.begin(), t.end());
    ll len = unique(t.begin(), t.end()) - t.begin();
    ll ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int q = 0; q < len; q++)
            {
                ans += ck(a[i], b[j], t[q].first, t[q].second);
                if (t[q].first != t[q].second)
                    ans += ck(a[i], b[j], t[q].second, t[q].first);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
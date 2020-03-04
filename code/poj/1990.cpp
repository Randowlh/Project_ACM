#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n;
ll tree[20110][2];
inline ll lowbit(ll x) { return (x & -x); }
void update(ll x, ll v)
{
    while (x <= 20010)
    {
        tree[x][1]++;
        tree[x][0] += v;
        x += lowbit(x);
    }
    return;
}
ll getsum(ll x, ll flag)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += tree[x][flag];
        x -= lowbit(x);
    }
    return ans;
}
vector<pair<ll, ll>  > date;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> x;
        cin >> x.first >> x.second;
        date.push_back(x);
    }
    sort(date.begin(), date.end());
    ll ans = 0;
    ll now = 0;
    for (int i = 0; i < n; i++)
    {
        ll cnt = getsum(date[i].second, 1);
        ll dis = getsum(date[i].second, 0);
        ans += (cnt * date[i].second - dis) * date[i].first;
        dis = getsum(20010, 0) - dis;
        ans += (dis - (i - cnt) * date[i].second) * date[i].first;
        update(date[i].second, date[i].second);
    }
    cout << ans << endl;
    return 0;
}
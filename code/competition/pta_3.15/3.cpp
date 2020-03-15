#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    pair<ll, ll> x;
    for (int i = 0; i < n; i++)
    {
        cin >> x.first >> x.second;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    int f = 0;
    int i = 0;
    while (true)
    {
        ll tt = v[i].first + v[i].second;
        ll ma = v[i].first + v[i].second;
        int mix = 0;
        int t = 1;
        while (v[i + t].first <= tt)
        {
            //   cout << i << endl;
            if (i + t == v.size() - 1)
            {
                f = 1;
                break;
            }
            if (ma < v[i + t].first + v[i + t].second)
            {
                ma = v[i + t].first + v[i + t].second;
                mix = i + t;
            }
            t++;
        }
        // cout << i << endl;
        if (f)
            break;
        if (mix == 0)
        {
            break;
        }
        i = mix;
    }
    if (f)
    {
        int i = n - 1;
        while (true)
        {
            ll tt = v[i].first - v[i].second;
            ll ma = v[i].first - v[i].second;
            int mix = 0;
            int t = -1;
            while (v[i + t].first >= tt)
            {
                //   cout << i << endl;
                if (i + t <= 0)
                {
                    f = 2;
                    break;
                }
                if (ma > v[i + t].first - v[i + t].second)
                {
                    ma = v[i + t].first - v[i + t].second;
                    mix = i + t;
                }
                t--;
            }
            // cout << i << endl;
            if (f == 2)
                break;
            if (mix == 0)
            {
                break;
            }
            i = mix;
        }
    }
    if (f == 2)
    {
        cout << (v[v.size() - 1].first - v[0].first) * 3 << endl;
    }
    else
        cout << -1 << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
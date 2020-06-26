#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> v;
vector<int> mp[600000];
int nxt[600000];
int n, k;
int calc(int a, int b)
{
    if (abs(v[a].first - v[b].first) > k)
        return 0;
    if (abs(v[a].second - v[b].second) > k)
        return 0;
    return (k - abs(v[a].second - v[b].second)) * (k - abs(v[a].first - v[b].first));
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    pair<int, int> tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int now = n - 1;
    int pr = v[n - 1].first;
    for (int i = n - 1; i >= 0; i--)
    {
        if (pr != v[i].first)
        {
            nxt[i] = i;
            now = i;
            pr = v[i].first;
        }
        else
            nxt[i] = now;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = 0;
            if (abs(v[i].first - v[j].first) > k)
                break;
            if (abs(v[i].second - v[j].second) > k)
            {
                j = nxt[j];
                continue;
            }
            t = calc(i, j);
            if (t != 0)
            {
                for (int r = 0; r < mp[j].size(); r++)
                {
                    if (calc(mp[j][r], i))
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
                mp[j].push_back(i);
            }
            if (t)
                ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = 998244353;
const double eps = 1e-7;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int fct[300100];
int init()
{
    int now = 1;
    int cnt = 1;
    for (int i = 1; i < 300010; i++)
    {
        now = cnt * now % mod;
        fct[i] = now;
        cnt++;
    }
    return 0;
}
void work()
{
    init();
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    pair<int, int> x;
    for (int i = 0; i < n; i++)
    {
        cin >> x.first >> x.second;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> ct, ct2, ct3;
    int cnt = 1;
    int now = inf - 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == now)
        {
            cnt++;
            continue;
        }
        else
        {
            if (cnt > 1)
                ct.push_back(cnt);
            cnt = 1;
        }
        now = v[i].first;
    }
    if (cnt)
        ct.push_back(cnt);
    sort(v.begin(), v.end(), cmp);
    cnt = 1;
    int pr = 0;
    now = inf - 1;
    vector<pair<int, int>> k;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == now)
        {
            cnt++;
            continue;
        }
        else
        {
            if (cnt > 1)
            {
                k.push_back(make_pair(pr, i));
                ct2.push_back(cnt);
            }
            pr = i;
            cnt = 1;
        }
        now = v[i].second;
    }
    if (cnt)
        ct2.push_back(cnt);
    for (int i = 0; i < k.size(); i++)
    {
        sort(v.begin() + k[i].first, v.begin() + k[i].second);
    }
    cnt = 1;
    now = -99999999;
    int f = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first < now)
        {
            f = 0;
            break;
        }
        if (v[i].first == now)
        {
            cnt++;
            continue;
        }
        else
        {
            if (cnt > 1)
                ct3.push_back(cnt);
            cnt = 1;
        }
        now = v[i].first;
    }
    int jia = f;
    for (int i = 0; i < ct3.size(); i++)
    {
        jia = jia * fct[ct3[i]] % mod;
    }
    int ans = fct[n];
    int jian = 1;
    for (int i = 0; i < ct.size(); i++)
    {
        jian = jian * fct[ct[i]] % mod;
    }
    int jian2 = 1;
    for (int i = 0; i < ct2.size(); i++)
    {
        jian2 = jian2 * fct[ct2[i]] % mod;
    }
    ans = (ans + mod - jian - jian2 + mod + jia) % mod;
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
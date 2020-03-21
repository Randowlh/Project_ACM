#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = 998244353;
void work()
{
    int n, k;
    cin >> n >> k;
    vector<int> v, tt;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    tt = v;
    sort(tt.begin(), tt.end(), greater<int>());
    int jie = tt[k - 1];
    ll ans1 = 0;
    for (int i = 0; i < k; i++)
    {
        ans1 += tt[i];
    }
    cout << ans1 << ' ';
    vector<ll> dp;
    ll now = 1;
    int cnt = 0;
    int pr = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < jie)
        {
            cnt++;
        }
        else
        {
            if (pr == -1)
            {
                pr = i;
                cnt = 0;
                continue;
            }
            now = (now * (cnt + 1)) % mod;
            cnt = 0;
        }
    }
    cout << now << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
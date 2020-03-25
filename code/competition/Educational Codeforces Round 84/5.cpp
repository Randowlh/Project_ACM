#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
void work()
{
    int n;
    cin >> n;
    ll now = 10;
    vector<ll> ans;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(now);
        now = now * 9 % mod * (n - i) % mod;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
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
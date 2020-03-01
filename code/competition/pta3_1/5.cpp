#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
const int mod = 1000000007;
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int now = 0;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * (v[i] - now)) % mod;
        now++;
    }
    cout << ans << endl;
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
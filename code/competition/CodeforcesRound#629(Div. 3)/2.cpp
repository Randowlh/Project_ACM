#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
void work()
{
    ll n, k;
    string ans;
    cin >> n >> k;
    int cnt = 2;
    int now = 1;
    for (int i = 0; i < n; i++)
    {
        now += cnt;
        if (now > k)
        {
            now -= cnt;
            break;
        }
        cnt++;
    }
    int kk = cnt;
    int kkk = k - now + 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == kk || i == kkk)
        {
            ans.push_back('b');
        }
        else
            ans.push_back('a');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}

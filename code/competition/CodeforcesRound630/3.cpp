#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
string ck[200010];
void work()
{

    int book[200010];
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= k; i++)
    {
        book[i] = 0;
        ck[i].clear();
    }
    string tmp;
    cin >> tmp;
    for (int i = 0; i < n; i++)
    {
        ck[i % k].push_back(tmp[i]);
    }
    for (int i = n - 1; i >= n - k; i--)
    {
        if (book[i % k] == 0 && book[(n - 1 - i) % k] == 0)
            if (i % k != (n - 1 - i) % k)
            {
                ck[(n - 1 - i) % k] += ck[i % k];
                book[i % k] = 1;
            }
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (book[i])
            continue;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < ck[i].size(); j++)
        {
            cnt[ck[i][j] - 'a']++;
        }
        int ma = 0;
        for (int i = 0; i < 26; i++)
        {
            ma = max(ma, cnt[i]);
        }
        ans += ck[i].size() - ma;
    }

    cout << ans << endl;
}
signed main()
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
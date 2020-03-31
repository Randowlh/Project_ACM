#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void work()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v;
    int tmp;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    if ((v.size() + 1) * d + sum - v.size() >= n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
    int head = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        //  cout << "i=" << i << endl;
        if (cnt != d - 1)
        {
            cnt++;
            cout << 0 << ' ';
            continue;
        }
        else
        {
            i += v[head];
            for (int j = 0; j < v[head] && i + j <= n; j++)
            {
                cout << head + 1 << ' ';
            }
            i--;
            head++;
            cnt = 0;
        }
    }
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
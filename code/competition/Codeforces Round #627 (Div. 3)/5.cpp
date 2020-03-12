#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
ll dp[2100][2100];
void work()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int ls = v[0] + h;
    int rs = v[0] + h;
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(ls, rs));
    for (int i = 1; i < n; i++)
    {
        ls += h + v[i] - 1;
        rs += h + v[i];
        arr.push_back(make_pair(ls, rs));
    }
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = l; j <= r; j++)
            dp[i][j] = 1;
    }
    for (int i = n - 1; i > 0; i--)
        for (int j = arr[i].first; j <= arr[i].second; j++)
        {
            ll t = 0;
            if (j % h + 1 <= r && j % h + 1 >= l)
                t++;
            t = max(t, dp[(j + v[i] - 1) / h][(j + v[i] - 1) % h - 1]);
            t = max(t, dp[(j + v[i]) / h][(v[i] + j) % h + 1]);
            dp[j / h][j % h + 1] = max(t, dp[j / h][j % h + 1]);
        }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= h; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << dp[1][v[0]] << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
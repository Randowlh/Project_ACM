#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int date[51000][2];
int find(int x, int flag)
{
    if (date[x][flag] == x)
        return x;
    return date[x][flag] = find(date[x][flag], flag);
}
void merge(int a, int b, int flag)
{
    int l = find(a, flag);
    int r = find(b, flag);
    if (l != r)
        date[l][flag] = date[r][flag];
}
void work()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2; i++)
        {
            date[i][j] = i;
        }
    }
    int a, b;
    vector<pair<int, int>> arr[2];
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        arr[0].push_back(make_pair(a, i));
        arr[1].push_back(make_pair(b, i));
    }
    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());
    for (int j = 0; j < 2; j++)
        for (int i = 1; i < arr[0].size(); i++)
        {
            if (arr[j][i].first == arr[j][i - 1].first)
                merge(arr[j][i].second, arr[j][i - 1].second, j);
        }
    for (int i = 0; i < n; i++)
    {
    }
}
signed main()
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
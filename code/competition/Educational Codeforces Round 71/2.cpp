#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int A[100][100];
int B[100][100];
void work()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (A[i][j] == 1 && A[i + 1][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j + 1] == 1)
            {
                ans.push_back(make_pair(i + 1, j + 1));
                B[i][j] = 1;
                B[i][j + 1] = 1;
                B[i + 1][j] = 1;
                B[i + 1][j + 1] = 1;
            }
            if (A[i][j] == 0 && B[i][j] == 1)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] != B[i][j])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}
signed main()
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
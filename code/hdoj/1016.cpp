#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
int book[100];
vector<int> ans;
bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int step)
{

    for (int i = 1; i <= n; i++)
    {
        if (!book[i] && is_prime(ans[step - 1] + i))
        {
            book[i] = 1;
            ans.push_back(i);
            dfs(step + 1);
            ans.pop_back();
            book[i] = 0;
        }
    }
    if (step == n)
    {
        if (is_prime(ans[ans.size() - 1] + ans[0]))
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << ans[i] << ' ';
            }
            cout << ans[n - 1] << endl;
        }
        return;
    }
    return;
}
void work()
{
    int cnt = 0;
    int f = 0;
    while (cin >> n)
    {
        cnt++;
        cout << "Case " << cnt << ":" << endl;
        memset(book, 0, sizeof(book));
        ans.clear();
        ans.push_back(1);
        book[1] = 1;
        dfs(1);
        book[1] = 0;
        cout << endl;
    }
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
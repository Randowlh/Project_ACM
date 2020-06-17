#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
struct node
{
    int date;
    int ls, rs;
    void init()
    {
        date = llinf;
        ls = llinf;
        rs = llinf;
    }
} tree[110000];
vector<int> ans;
void dfs(int x)
{
    if (tree[x].ls != llinf)
        dfs(tree[x].ls);
    if (tree[x].rs != llinf)
        dfs(tree[x].rs);
    ans.push_back(tree[x].date);
}
void work()
{
    int n;
    while (cin >> n)
    {
        ans.clear();
        int tmp;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        for (int i = 0; i <= n; i++)
        {
            tree[i].init();
        }
        int tail = 1;
        for (int i = 0; i < v.size(); i++)
        {
            int now = 0;
            while (true)
            {
                if (tree[now].date == llinf)
                {
                    tree[now].date = v[i];
                    break;
                }
                if (tree[now].date > v[i])
                {
                    if (tree[now].ls == llinf)
                    {
                        tree[now].ls = tail;
                        tree[tail].init();
                        tree[tail].date = v[i];
                        tail++;
                        break;
                    }
                    else
                    {
                        now = tree[now].ls;
                        continue;
                    }
                }
                else
                {
                    if (tree[now].rs == llinf)
                    {
                        tree[now].rs = tail;
                        tree[tail].init();
                        tree[tail].date = v[i];
                        tail++;
                        break;
                    }
                    else
                    {
                        now = tree[now].rs;
                        continue;
                    }
                }
            }
        }
        dfs(0);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
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
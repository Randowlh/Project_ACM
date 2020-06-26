#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node
{
    int l, r;
    int v;
    void init() { l = llinf, r = llinf, v = llinf; }
} date[1100000];
vector<int> ans[1000];
int tail;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void dfs(int now, int step)
{
    if (date[now].l != llinf)
    {
        dfs(date[now].l, step + 1);
    }
    if (date[now].r != llinf)
    {
        dfs(date[now].r, step + 1);
    }
    ans[step].push_back(date[now].v);
}
void work()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < 900; i++)
            ans[i].clear();
        tail = 0;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            if (tail == 0)
            {
                date[tail].init();
                date[tail].v = tmp;
                tail++;
                continue;
            }
            int now = 0;
            while (true)
            {
                if (tmp < date[now].v)
                {
                    if (date[now].l == llinf)
                    {
                        date[now].l = tail;
                        date[tail].init();
                        date[tail].v = tmp;
                        tail++;
                        break;
                    }
                    now = date[now].l;
                    continue;
                }
                else
                {
                    if (date[now].r == llinf)
                    {
                        date[now].r = tail;
                        date[tail].init();
                        date[tail].v = tmp;
                        tail++;
                        break;
                    }
                    now = date[now].r;
                    continue;
                }
            }
        }
        dfs(0, 0);
        vector<int> aa;
        for (int i = 0; i < 200; i++)
        {
            if (ans[i].size() == 0)
                break;
            for (int j = 0; j < ans[i].size(); j++)
            {
                aa.push_back(ans[i][j]);
            }
        }
        for (int i = 0; i < aa.size(); i++)
        {
            cout << aa[i] << ' ';
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

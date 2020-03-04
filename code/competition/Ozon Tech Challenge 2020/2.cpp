#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    string tmp;
    cin >> tmp;
    int flag[1010];
    memset(flag, 0, sizeof(flag));
    vector<vector<int>> ans;
    while (true)
    {
        int f = 0;
        int ft = 0;
        vector<int> t;
        t.clear();
        vector<int> a, b;
        a.clear();
        b.clear();
        for (int i = 0; i < tmp.size(); i++)
        {
            if (flag[i])
                continue;
            if (tmp[i] == '(')
            {
                a.push_back(i);
            }
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            if (flag[i])
                continue;
            if (tmp[i] == ')')
            {
                b.push_back(i);
            }
        }

        if (a.empty() || b.empty())
            break;
        for (int i = 0; i < min(a.size(), b.size()); i++)
        {
            if (a[i] < b[i])
            {
                flag[a[i]] = 1;
                flag[b[i]] = 1;
                t.push_back(a[i]);
                t.push_back(b[i]);
            }
            else
            {
                break;
            }
        }
        if (t.empty())
            break;
        ans.push_back(t);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].size() << endl;
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] + 1 << ' ';
        }
        cout << endl;
    }
    return;
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
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, m;
    cin >> n >> m;
    set<string> s;
    vector<string> ans;
    string tmp;
    string mid;
    mid.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        string t = tmp;
        reverse(tmp.begin(), tmp.end());
        if (s.count(tmp) != 0)
        {
            ans.push_back(tmp);
        }
        else if (t == tmp)
        {
            if (mid.size() < t.size())
            {
                mid = t;
            }
        }
        else
        {
            reverse(tmp.begin(), tmp.end());
            s.insert(tmp);
        }
    }
    string a;
    for (int i = 0; i < ans.size(); i++)
    {
        a += ans[i];
    }
    if (!mid.empty())
    {
        a += mid;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        reverse(ans[i].begin(), ans[i].end());
        a += ans[i];
    }
    cout << a.size() << endl;
    if (!a.empty())
    {
        cout << a << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    map<int, int> M;
    set<int> sg;
    vector<int> mp[110000];
    map<pair<int, int>, int> ans;
    vector<pair<int, int>> arr;
    int n;
    cin >> n;
    int u, w;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> w;
        mp[u].push_back(w);
        mp[w].push_back(u);
        arr.push_back(make_pair(u, w));
        M[u]++;
        M[w]++;
    }
    if (n == 2)
    {
        cout << 0 << endl;
        return;
    }
    map<int, int>::iterator it = M.begin();
    while (it != M.end())
    {
        if (it->second == 1)
        {
            sg.insert(it->first);
        }
        it++;
    }
    int st = *sg.begin();
    int ed = *sg.rbegin();
    ans[make_pair(ed, mp[ed][0])] = 0;
    ans[make_pair(mp[ed][0], ed)] = 0;
    ans[make_pair(st, mp[st][0])] = 1;
    ans[make_pair(mp[st][0], st)] = 1;
    sg.erase(st);
    sg.erase(ed);
    int cnt;
    if (!sg.empty())
    {
        int tt = *sg.begin();
        ans[make_pair(tt, mp[tt][0])] = 2;
        ans[make_pair(mp[tt][0], tt)] = 2;
        cnt = 3;
    }
    else
        cnt = 2;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ans.count(make_pair(arr[i].first, arr[i].second)) == 0)
        {
            cout << cnt << endl;
            cnt++;
        }
        else
        {
            cout << ans[make_pair(arr[i].first, arr[i].second)] << endl;
        }
    }
    return;
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
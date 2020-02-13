#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    string tmp;
    cin >> tmp;
    set<char> mp[300];
    char pr = tmp[0];
    char s = tmp[0];
    for (int i = 1; i < tmp.size(); i++)
    {
        mp[pr].insert(tmp[i]);
        pr = tmp[i];
    }
    for (int i = 0; i < 300; i++)
    {
        if (s == i)
        {
            if (mp[i].size() > 2)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (mp[i].size() > 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout<<"e131"<<endl;
    set<char> a;
    for (char i = 'a'; i <= 'z'; i++)
    {
        a.insert(i);
    }
    if (mp[s].size() == 0)
    {
        cout << "YES" << endl;
        for (char i = 'a'; i <= 'z'; i++)
        {
            cout << i;
        }
        cout << endl;
    }
    else if (mp[s].size() == 1)
    {
        char now = s;
        set<char> ck;
        vector<char> ans;
        ans.push_back(s);
        ck.insert(s);
        a.erase(s);
        while (!mp[now].empty())
        {
            if (ck.count(*mp[now].rbegin()) != 0)
            {
                cout << "NO" << endl;
                return;
            }
            ck.insert(*mp[now].rbegin());
            ans.push_back(*mp[now].rbegin());
            now = *mp[now].rbegin();
            a.erase(*mp[now].rbegin());
        }
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        while (!a.empty())
        {
            cout << *a.rbegin();
            a.erase(*a.rbegin());
        }
        cout << endl;
    }
    else
    {
        char now = s;
        set<char> ck;
        vector<char> ans;
        ans.push_back(s);
        ck.insert(s);
        a.erase(s);
        while (!mp[now].empty())
        {
            if (ck.count(*mp[now].rbegin()) != 0)
            {
                cout << "NO" << endl;
                return;
            }
            ck.insert(*mp[now].rbegin());
            ans.push_back(*mp[now].rbegin());
            now = *mp[now].rbegin();
            a.erase(*mp[now].rbegin());
            mp[now].erase(*mp[now].rbegin());
        }
        now = s;
        while (!mp[now].empty())
        {
            if (ck.count(*mp[now].rbegin()) != 0)
            {
                cout << "NO" << endl;
                return;
            }
            ans.insert(ans.begin(), *mp[now].rbegin());
            now = *mp[now].rbegin();
            a.erase(*mp[now].rbegin());
            mp[now].erase(*mp[now].rbegin());
        }
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        while (!a.empty())
        {
            cout << *a.rbegin();
            a.erase(*a.rbegin());
        }
        cout << endl;
    }
    return;
}
int main()
{

    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
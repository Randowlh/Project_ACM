#include <bits/stdc++.h>
using namespace std;
map<string, vector<int>> team, cls;
map<int, string> person;
map<string, bool> cls_or_team;
vector<string> all_list;
int tail = 10000;
int main()
{
    //freopen("in.txt", "r", stdin);
    string tmp, tmp2;
    int tt;
    while (cin >> tmp)
    {
        if (tmp == "append")
        {
            cin >> tmp;
            person[tail] = tmp;
            tail++;
        }
        else if (tmp == "create")
        {
            cin >> tmp >> tmp2;
            if (tmp == "team")
                cls_or_team[tmp2] = 0;
            else
                cls_or_team[tmp2] = 1;
            all_list.push_back(tmp2);
        }
        else
        {
            cin >> tmp;
            cin >> tmp >> tt;
            // cout << cls_or_team[tmp] << "tmp=" << tmp << " tt=" << tt << endl;
            if (cls_or_team[tmp] == 0)
                team[tmp].push_back(tt);
            else
                cls[tmp].push_back(tt);
        }
    }
    cout << "student list:" << endl;
    for (int i = 10000; i < tail; i++)
    {
        cout << i << ' ' << person[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < (int)all_list.size(); i++)
    {
        if (cls_or_team[all_list[i]])
        {
            cout << "class " << all_list[i] << ':' << endl;
            for (int j = 0; j < (int)cls[all_list[i]].size(); j++)
            {
                cout << cls[all_list[i]][j] << ' ' << person[cls[all_list[i]][j]] << endl;
            }
        }
        else
        {
            cout << all_list[i] << " team:" << endl;
            for (int j = 0; j < (int)team[all_list[i]].size(); j++)
            {
                cout << team[all_list[i]][j] << ' ' << person[team[all_list[i]][j]] << endl;
            }
        }
        cout << endl;
    }
}
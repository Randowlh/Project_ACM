#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> M, M2;
map<string, string> lg;
bool cmp(string a, string b, string c)
{
    for (int i = 0; i < M2[a].size(); i++)
    {
        if (M2[a][i] == b)
        {
            return true;
        }
        if (M2[a][i] == c)
        {
            return false;
        }
    }
    return false;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n)
    {
        M.clear();
        M2.clear();
        lg.clear();
        queue<string> q;
        vector<string> ans;
        string tmp, tmp2;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            ans.push_back(tmp);

            vector<string> t;
            t.clear();
            for (int j = 0; j < n; j++)
            {
                cin >> tmp2;
                t.push_back(tmp2);
            }
            M2[tmp] = t;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            q.push(tmp);
            vector<string> t;
            t.clear();
            for (int j = 0; j < n; j++)
            {
                cin >> tmp2;
                t.push_back(tmp2);
            }
            M[tmp] = t;
        }
        while (!q.empty())
        {
            string t = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (lg.count(M[t][i]) == 0)
                {
                    lg[M[t][i]] = t;
                    break;
                }
                else if (cmp(M[t][i], t, lg[M[t][i]]))
                {
                    q.push(lg[M[t][i]]);
                    lg[M[t][i]] = t;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ' << lg[ans[i]] << endl;
        }
        cout << endl;
    }
}
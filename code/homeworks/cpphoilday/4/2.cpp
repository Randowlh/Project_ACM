#include <bits/stdc++.h>
using namespace std;
bool is_prime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> V;
    queue<int> Q;
    stack<int> S1, S2;
    int t;
    while (cin >> t)
    {
        if (t == 0)
            break;
        if (t < 0)
        {
            V.push_back(t);
            continue;
        }
        if (t < 1000000 && is_prime(t))
        {
            Q.push(t);
        }
        if (t % 2 == 0)
        {
            S1.push(t);
        }
        else
        {
            S2.push(t);
        }
    }
    vector<vector<int>> ans;
    ans.resize(4);
    t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            ans[i] = V;
        }
        if (i == 1)
        {
            while (!Q.empty())
            {
                ans[i].push_back(Q.front());
                Q.pop();
            }
        }
        if (i == 2)
        {
            while (!S1.empty())
            {
                ans[i].push_back(S1.top());
                S1.pop();
            }
        }
        if (i == 3)
        {
            while (!S2.empty())
            {
                ans[i].push_back(S2.top());
                S2.pop();
            }
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < (int)ans[j].size(); i++)
        {
            cout << ans[j][i] << '\t';
        }
        cout << endl;
    }
    return 0;
}
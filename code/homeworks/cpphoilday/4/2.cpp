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
    t = 0;
    while (true)
    {
        int flag = 0;
        vector<int> k;
        if ((int)V.size() > t)
        {
            flag = 1;
            k.push_back(V[t]);
            t++;
        }
        else
            k.push_back(0);
        if (!Q.empty())
        {
            k.push_back(Q.front());
            Q.pop();
            flag = 1;
        }
        else
        {
            k.push_back(0);
        }
        if (!S1.empty())
        {
            k.push_back(S1.top());
            S1.pop();
            flag = 1;
        }
        else
        {
            k.push_back(0);
        }
        if (!S2.empty())
        {
            k.push_back(S2.top());
            S2.pop();
            flag = 1;
        }
        else
        {
            k.push_back(0);
        }
        if (flag == 0)
        {
            break;
        }
        else
            ans.push_back(k);
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v;
    int tmp;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    int head = 0;
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n - sum; i++)
    {
        if (cnt < d - 1)
        {
            cnt++;
            ans.push_back(0);
        }
        else
        {
            if (head >= v.size())
            {
                cout << "NO" << endl;
                return 0;
            }
            sum -= v[head];
            i += v[head];
            for (int j = 0; j < v[head]; j++)
            {
                ans.push_back(head + 1);
            }
            head++;
            i--;
            cnt = 0;
        }
    }
    cout << "YES" << endl;
    for (int i = head; i < v.size(); i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            ans.push_back(i + 1);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
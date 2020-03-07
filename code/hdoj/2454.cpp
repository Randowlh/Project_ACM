#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
    {
        int n;
        cin >> n;
        vector<int> v;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < n; i++)
        {
            sort(v.begin() + i, v.end(), greater<int>());
            int t = v[i];
            if (t + i >= n)
            {
                break;
            }
            for (int j = 1; j <= t; j++)
            {
                v[i]--;
                v[j + i]--;
            }
        }
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != 0)
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << "yes" << endl;
        }
        else
            cout << "no" << endl;
    }
}
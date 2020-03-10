#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> date, v;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            date.push_back(tmp);
        }
        v.push_back(date[0]);
        for (int i = 1; i < n; i++)
        {
            int fl = 0;
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] > date[i])
                {
                    fl = 1;
                    v[j] = date[i];
                    break;
                }
            }
            if (!fl)
            {
                v.push_back(date[i]);
            }
        }
        cout << v.size() << endl;
    }
}
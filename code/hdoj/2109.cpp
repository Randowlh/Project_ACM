#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<int> a, b;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int s = 0;
        int o = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                s += 2;
            }
            else if (a[i] == b[i])
            {
                s++;
                o++;
            }
            else
            {
                o += 2;
            }
        }
        cout << s << " vs " << o << endl;
    }
    return 0;
}
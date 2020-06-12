#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        int tmp;
        vector<int> a, b;
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
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        int ans = 0;
        int tail1 = 0;
        int tail2 = 0;
        while (tail2 < n)
        {
            if (a[tail1] > b[tail2])
            {
                ans++;
                tail1++;
            }
            tail2++;
        }
        cout << ans << endl;
    }
}
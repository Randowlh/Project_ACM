#include <bits/stdc++.h>
using namespace std;
#define int long long
int c1[11000], c2[11000];
signed main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
        {
            c1[i] = 0;
            c2[i] = 0;
        }
        for (int i = 0; i <= n; i++)
            c1[i] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                for (int k = 0; j + k <= n; k += i)
                    c2[j + k] += c1[j];
            for (int i = 0; i <= n; i++)
            {
                c1[i] = c2[i];
                c2[i] = 0;
            }
        }
        cout << c1[n] << endl;
    }
}
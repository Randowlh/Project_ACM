#include <bits/stdc++.h>
using namespace std;
int c1[110000], c2[110000], v[100], cnt[100];
int main()
{
    //  freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n)
    {
        if (n < 0)
            break;
        int tol = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i] >> cnt[i];
            tol += v[i] * cnt[i];
        }
        for (int i = 0; i <= (tol >> 1); i++)
        {
            c1[i] = 0;
            c2[i] = 0;
        }
        for (int i = 0; i <= (tol >> 1); i += v[0])
            c1[i] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= (tol >> 1); j++)
            {
                for (int k = 0; k + j <= (tol >> 1) && k / v[i] <= cnt[i]; k += v[i])
                {
                    c2[j + k] += c1[j];
                }
            }
            for (int i = 0; i <= (tol >> 1); i++)
            {
                c1[i] = c2[i];
                c2[i] = 0;
            }
        }
        for (int i = (tol >> 1); i >= 0; i--)
        {
            if (c1[i])
            {
                cout << tol - i << ' ' << i << endl;
                break;
            }
        }
    }
    return 0;
}
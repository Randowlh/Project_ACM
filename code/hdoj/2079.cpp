#include <bits/stdc++.h>
using namespace std;
int c1[11000], c2[11000];
int v[100], cnt[100];
int main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n, k;
        while (cin >> n >> k)
        {
            for (int i = 0; i < k; i++)
                cin >> v[i] >> cnt[i];
            for (int i = 0; i <= n; i++)
            {
                c1[i] = 0;
                c2[i] = 0;
            }
            for (int i = 0; i / v[0] <= cnt[0]; i += v[0])
            {
                c1[i] = 1;
            }
            for (int i = 1; i < k; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    for (int tt = 0; j + tt <= n && tt / v[i] <= cnt[i]; tt += v[i])
                    {
                        c2[j + tt] += c1[j];
                    }
                }
                for (int j = 0; j <= n; j++)
                {
                    c1[j] = c2[j];
                    c2[j] = 0;
                }
            }
            cout << c1[n] << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int c1[11000], c2[11000];
int main()
{
    //freopen("in.txt", "r", stdin);
    int val[] = {1, 2, 5};
    int cnt[3];
    while (cin >> cnt[0] >> cnt[1] >> cnt[2])
    {
        if (!cnt[0] && !cnt[1] && !cnt[2])
            break;
        int n = 1;
        for (int i = 0; i < 3; i++)
            n += val[i] * cnt[i];
        for (int i = 0; i <= n + 100; i++)
        {
            c1[i] = 0;
            c2[i] = 0;
        }
        for (int i = 0; i <= cnt[0]; i++)
        {
            c1[i] = 1;
        }
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0, cntt = 0; j + k <= n && cntt <= cnt[i]; k += val[i], cntt++)
                    c2[j + k] += c1[j];
            }
            for (int j = 0; j <= n; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for (int i = 1; i <= n + 1; i++)
        {
            if (c1[i] == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
}
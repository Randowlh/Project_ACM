#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int f = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                f++;
                if (i * i != n)
                {
                    f++;
                }
            }
        }
        cout << (f & 1) << endl;
    }
}
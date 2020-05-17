#include <iostream>
using namespace std;
//#define 154  1000
int a[1000];
int t, n;
int main()
{
    cin >> t;
    if (t == 1)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int result = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (a[i] > a[j])
                {
                    result += (i ^ j);
                }
            }
        }
        cout << result << endl;
    }
    else
    {
    }
}

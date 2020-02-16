#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int k, n;
int ck[32];
bool check(int x)
{
    int m = n - x * k;
    int res = 0;
    if (m < x)
        return 0;
    for (int i = 0; i <= 31; i++)
        if (m & ck[i])
        {
            x--;
            if (x < 0)
                return 0;
        }
    return 1;
}
int main()
{
    ck[0] = 1;
    for (int i = 1; i <= 31; i++)
        ck[i] = ck[i - 1] << 1;
    cin >> n;
    cin >> k;
    for (int i = 1; i <= 100; i++)
        if (check(i))
        {
            cout << i << endl;
            return 0;
        }
    cout << -1 << endl;
    return 0;
}
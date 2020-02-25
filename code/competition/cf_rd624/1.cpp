#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << 0 << endl;
    else
    {
        if (a < b)
        {
            if ((b - a) % 2 == 0)
            {
                cout << 2 << endl;
            }
            else
                cout << 1 << endl;
        }
        else
        {
            if ((b - a) % 2 == 0)
            {
                cout << 1 << endl;
            }
            else
                cout << 2 << endl;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //reopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
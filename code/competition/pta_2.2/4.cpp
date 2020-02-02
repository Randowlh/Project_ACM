#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    int a;
    cin >> a;
    if (a < 2)
    {
        cout << "No" << endl;
        return;
    }
    else if (a == 2)
    {
        cout << "Yes" << endl;
        return;
    }
    else
        for (int i = 2; i <= sqrt(a); i++)
        {
            if (a % i == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    cout << "Yes" << endl;
    return;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
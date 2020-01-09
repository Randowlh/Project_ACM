#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int flag = 0;
void work()
{
    int n;
    int date[10000];
    while (cin >> n)
    {
        //cout<<endl;
        if (n == 0)
        {
            break;
        }
        if (flag == 0)
            ;
        else
            cout << endl;
        flag++;
        int tol = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> date[i];
            tol += date[i];
        }
        tol /= n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (date[i] > tol)
            {
                ans += date[i] - tol;
            }
        }
        cout << "Set #" << flag << endl;
        cout << "The minimum number of moves is " << ans << '.' << endl;
    }
    return;
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int t = 1;
    while (t--)
    {
        work();
    }
    return 0;
}
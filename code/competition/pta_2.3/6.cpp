#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    int tmp = 0;
    int cnt = 0;
    while (true)
    {
        if (tmp > n)
        {
            break;
        }
        tmp *= 10;
        tmp++;
        cnt++;
    }
    while (true)
    {
        if (tmp % n == 0)
        {
            cout << tmp / n << ' ' << cnt << endl;
            break;
        }
        cout<<tmp / n;
        tmp%=n;
        tmp=tmp*10+1;
        cnt++;
    }
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
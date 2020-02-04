#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void out(int a)
{
    if (a <= 3)
    {
        for (int i = 0; i < a; i++)
            cout << 6;
    }
    else if (a <= 9)
    {
        cout << 9;
    }
    else
        cout << 27;
    return;
}
void work()
{
    string tmp;
    getline(cin, tmp);
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '6')
        {
            cnt++;
        }
        else
        {
            out(cnt);
            cout << tmp[i];
            
            cnt = 0;
        }
    }
    out(cnt);
    cnt = 0;
    return;
}
int main()
{
 //   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
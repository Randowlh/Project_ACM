#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int a, b;
int mp[10010];
int mpp[10010];
int book[10010];
bool ispr(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int check(int i, int fl)
{
    if (book[i] == 987)
    {
        return mpp[i];
    }
    book[i] = 987;
    int tol = 0;
    int tmp = i;
    while (i > 0)
    {
        tol += (i % 10) * (i % 10);
        i /= 10;
    }
    //cout<<tol<<endl;
    i = tmp;
    if (mp[tol] == 2 || mp[tol] == 1)
    { //cout<<"??"<<endl;
        mp[tol] = 2;
        mp[i] = fl;
        mpp[i]=mpp[tol]+1;
        return mpp[i];
    }
    int t;
    if (check(tol, 2))
    {
        mpp[i] = check(tol, 2) + 1;
        mp[i] = fl;
        return t;
    }
    else
        return 0;
}
void work()
{
    cin >> a >> b;
    mp[1] = 1;
    mpp[1]=0;
    for (int i = a; i <= b; i++)
    { // cout<<i<<endl;
        check(i, 1);
    }
    for (int i = a; i <= b; i++)
    { // cout<<mp[i]<<endl;
        if (mp[i] == 1)
        {
            cout << i << ' ';
            if (ispr(i))
            {
                cout << mpp[i] * 2 << endl;
            }
            else
                cout << mpp[i] << endl;
        }
    }
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
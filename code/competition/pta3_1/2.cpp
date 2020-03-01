#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    string tmp;
    ll l = 0;
    ll r = 0;
    cin >> tmp;
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 'R')
        {
            flag1 = 1;
        }
        if (flag1 == 1 && tmp[i] == 'L')
        {
            l++;
        }
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'L')
        {
            flag2 = 1;
        }
        if (flag2 && tmp[i] == 'R')
        {
            r++;
        }
    }
    if (l && r)
        cout << tmp.size() - l - r + 1 << endl;
    else
        cout << tmp.size() - l - r << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
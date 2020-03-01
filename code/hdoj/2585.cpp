#include <bits/stdc++.h>
using namespace std;
string a;
string tmp;
int n;
int search(int ax, int tx)
{
    if (ax == a.size())
        return true;
    if (tx == tmp.size())
        return false;
    if (a[ax] == '*')
    {
        for (int i = tx; i < tmp.size(); i++)
        {
            if (search(ax + 1, i))
                return true;
        }
        return false;
    }
    else if (a[ax] == '?')
    {
        return search(ax + 1, tx + 1);
    }
    else if (a[ax] == tmp[tx])
    {
        return search(ax + 1, tx + 1);
    }
    else
    {
        return false;
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (cin >> a)
    {
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            if (search(0, 0))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
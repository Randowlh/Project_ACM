#include <bits/stdc++.h>
using namespace std;
int mp[2][100010];
int n, q,cnt;
bool check(int x, int y,int fl)
{
    if (y == 0)
    {
        if (mp[1][x] == 1)
            cnt+=fl;
        if (x - 1 >= 0 && mp[1][x - 1] == 1)
            cnt+=fl;
        if (x + 1 < n && mp[1][x + 1] == 1)
            cnt+=fl;
        return false;
    }
    else
    {
        if (mp[0][x] == 1)
            cnt+=fl;
        if (x - 1 >= 0 && mp[0][x - 1] == 1)
            cnt+=fl;
        if (x + 1 < n && mp[0][x + 1] == 1)
            cnt+=fl;
        return false;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> q;
     cnt = 0;
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> y >> x;
        x--;
        y--;
        if (x == 0 && y == 0)
        {
            if (mp[y][x] == 1)
            {
                cnt--;
                mp[y][x] = 0;
            }
            else
            {
                cnt++;
                mp[y][x] = 1;
            }
        }
        else if (x == n - 1 && y == 1)
        {
            if (mp[y][x] == 1)
            {
                cnt--;
                mp[y][x] = 0;
            }
            else
            {
                cnt++;
                mp[y][x] = 1;
            }
        }
        else if (mp[y][x] == 1)
        {
            check(x, y,-1);
            mp[y][x] = 0;
        }
        else
        {
            mp[y][x] = 1;
             check(x,y,1);
        }
        if (cnt == 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
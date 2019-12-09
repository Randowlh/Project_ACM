#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int chacheng(int x1, int y1, int x2, int y2)
{
    return x2 * y1 - x1 * y2;
}
int main()
{
    while (1)
    {
        int fx, fy;
        int n;
        cin >> n;
        int flag = 0;
        if (n == 0)
            break;
        cin >> fx >> fy;
        int tx, ty;
        int ttx, tty;
        int tttx, ttty;
        tx = fx;
        ty = fy;
        cin >> ttx >> tty;
        for (int i = 2; i < n; i++)
        {
            cin >> tttx >> ttty;
            if (chacheng(-tx + ttx, -ty + tty, -tx + tttx, -ty + ttty) > 0)
            {
                flag = 1;
            }
            tx = ttx;
            ty = tty;
            ttx = tttx;
            tty = ttty;
        }
        if (chacheng(-tx + ttx, -ty + tty, -tx + fx, -ty + fy) > 0)
            {
                flag = 1;
            }
        if (flag == 0)
        {
            cout << "convex" << endl;
        }
        else
            cout << "concave" << endl;
    }
}
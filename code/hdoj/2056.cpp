#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x1, x2, x3, x4, y1, y2, y3, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        if (x3 > x4)
            swap(x3, x4);
        if (y3 > y4)
            swap(y3, y4);
        if (x3 >= x2 || y3 >= y2)
        {
            printf("%.2f\n", 0.0);
            continue;
        }
        else
        {
            printf("%.2f\n", (x3 - x2) * (y3 - y2));
        }
    }
}

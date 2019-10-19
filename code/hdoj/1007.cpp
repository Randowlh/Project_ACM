#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    double x;
    double y;
    bool operator<(const struct node a)
    {
        if (this->x < a.x)
        {
            return true;
        }
        else if (this->x == a.x && this->y < a.y)
            return true;
        else
            return false;
    }
} date[100010];
double dis(int x, int y)
{
    return sqrt((date[x].x - date[y].x) * (date[x].x - date[y].x) + (date[x].y - date[y].y) * (date[x].y - date[y].y));
}
int k;
int n;
double fenzhi(int s, int e)
{
    if (s == e)
    {
        return 99999;
    }
    else if (s + 1 == e)
    {
        return dis(s, e);
    }
    int mid = (s + e) / 2;
    double dl = fenzhi(s, mid);
    double dr = fenzhi(mid + 1, e);
    double d = min(dl, dr);
    for (int i = mid; i >= s; i--)
    {
        if (date[mid].x - date[i].x >= d)
        {
            break;
        }
        for (int j = mid + 1; j <= e; j++)
            if (date[j].x - date[mid].x >= d)
            {
                break;
            }
            else
            {
                if (fabs(date[i].y - date[j].y < d) < d)
                    d = min(d, dis(i, j));
            }
    }

    return d;
}
int main()
{
    while (true)
    {

        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &date[i].x, &date[i].y);
        }
        sort(date, date + n);
        printf("%.2f\n", fenzhi(0, n - 1) / 2);
    }
    return 0;
}

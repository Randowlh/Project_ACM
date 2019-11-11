#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    double a;
    int mon;
    int ma;
    bool operator<(const struct node a) const
    {
        return this->a < a.a;
    }
} arr[1010];
int n, m;
int main()
{
    while (true)
    {
        scanf("%d%d", &m, &n);
        if (m == -1 && n == -1)
        {
            break;
        }
        double tol = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &arr[i].mon, &arr[i].ma);
            arr[i].a = (double)arr[i].ma / (double)arr[i].mon;
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (m >= arr[i].ma)
            {
                tol += arr[i].mon;
                m -= arr[i].ma;
            }
            else
            {
                tol += (double)m/arr[i].a ;
                break;
            }
        }
        printf("%.3f\n", tol);
    }
    return 0;
}
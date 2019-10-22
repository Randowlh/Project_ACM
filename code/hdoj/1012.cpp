#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int fac(int x)
{
    if (x == 1)
        return 1;
    else
        return x * fac(x - 1);
}
int main()
{
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
     double ans = 2.5;
    for (int i = 3; i <= 9; i++)
    {
        ans += 1 / (long double)fac(i);
        printf("%d %.9f\n",i,ans);
    }
    return 0;
}
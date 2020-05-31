#include <bits/stdc++.h>
using namespace std;
int main(int argc, char)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        double x;
        cin >> x;
        double ans = x * x + x * x / 4 * 3.14;
        printf("%.2f\n\n", ans);
    }
}
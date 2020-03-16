#include <bits/stdc++.h>
using namespace std;
int prize[100000]; //价格表
int cut_rod(int n)
{
    if (n == 0)
        return 0; //没有钢管可切
    int ans = -0x7FFFFFFF;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, prize[i] + cut_rod(n - i));
    }
    return ans;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct node
{
    int a, b, c, pt, num;
    bool operator<(node a) const
    {
        return this->c < a.c;
    }
} date[5010];
int bl[5050];
int dp[5050];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &date[i].a, &date[i].b, &date[i].c);
    }
    int now = k;
    for (int i = 1; i <= n; i++)
    {
        bl[i] = now;
        now += date[i].b;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << bl[i] << ' ';
    }
    cout << endl;
    for (int i = n; i >= 0; i--)
    {
        dp[i] = max(date[i + 1].a, dp[i + 1] - date[i + 1].b);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << bl[i]+date[i].b- dp[i] << ' ';
    }
}
/*
4 3 7
7 4 17
3 0 8
11 2 0
13 3 5
*/
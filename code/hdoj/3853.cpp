#include <bits/stdc++.h>
using namespace std;
struct node
{
    double self, right, down;
};
node points[1010][1010];
double dp[1010][1010];
const double eps = 1e-5;
int main()
{ //
    // freopen("in.txt", "r", stdin);
    int R, C;
    while (scanf("%d%d", &R, &C) != EOF)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                scanf("%lf%lf%lf", &points[i][j].self, &points[i][j].right, &points[i][j].down);
            }
        }
        dp[0][0] = 0;
        dp[R - 1][C - 1] = 0;
        for (int i = R - 1; i >= 0; i--)
        {
            for (int j = C - 1; j >= 0; j--)
            {
                if ((i == R - 1 && j == C - 1) || fabs(points[i][j].self - 1.0) <= eps)
                    continue;
                double ans = 0;
                if (i < R - 1)
                    ans += dp[i + 1][j] * points[i][j].down;
                if (j < C - 1)
                    ans += dp[i][j + 1] * points[i][j].right;
                dp[i][j] = (ans + 2) / (1 - points[i][j].self);
            }
        }
        printf("%.3f\n", dp[0][0]);
    }
    return 0;
}
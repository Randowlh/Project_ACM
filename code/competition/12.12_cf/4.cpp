#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long LL;
 struct node
{
    int total, ca, score, id;
    bool operator<(node a){
        if (this->score == a.score)
        return this->total >= a.total;
    return this->score < a.score;
    }
} ;
node s[10010];
LL mind(LL a, LL b)
{
    if (a >= b)
        return b;
    return a;
}
int maxzxl[200100];
int date[200080];
int dp[200100];
int zhe[200100];
int main()
{
    int n,m, d,T;
    int t = 0 ;
    int q = 0;
    int ch = 0;
    scanf("%d", &n);
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &date[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                dp[0] = 1;
            else if (date[i] > date[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                maxzxl[q++] = dp[i - 1];
                dp[i] = 1;
                if (date[i] > date[i - 2] || date[i + 1] > date[i - 1])
                {
                    zhe[t++] = q;
                }
            }
        }
        maxzxl[q] = dp[n - 1];
        q++;
        long long ans = 0;
        for (int i = 0; i < q; i++)
        {
            ans = max(ans, (long long)maxzxl[i]);
        }
        for (int i = 0; i < t; i++)
        {
            long long num = maxzxl[zhe[i] - 1] + maxzxl[zhe[i]] - 1;
            ans = max(ans, num);
        }
        printf("%d\n", ans);
    }
    return 0;
}
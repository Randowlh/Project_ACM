#include <map>
#include <set>
#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define ll rt << 1
#define rr rt << 1 | 1
#define LL long long
#define ULL unsigned long long
#define maxn 1050
#define maxnum 1000050
#define eps 1e-6
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)

/*
dp[len][0]:前len位不含49且第len位不是4
dp[len][1]:前len位不含49且第len位为9（在加高位的4就可以符合题意了）
dp[len][2]:前len位已有49
*/

__int64 n;
int digit[20];
__int64 dp[20][5];

__int64 dfs(int pos, int status, bool flag)
{
    if (pos == 0)
        return status == 2;
    //pos==0已经枚举完了
    //如果status为2，说明前len位已经有了49，就应该计数
    //写成if (status==2) return 1;
    //else return 0;更好理解吧
    if (flag && dp[pos][status] != -1)
        return dp[pos][status];
    //dp不是-1是基本记忆化套路
    //flag==true就是表示在高位的枚举中有某一位小于n的对应位了，所以这些数在【0，n】 区间内
    //需要计数
    int num = flag ? 9 : digit[pos];
    //如果flag=1，低位可以从0枚举到9
    //否则只能枚举到n的相应位的数值
    __int64 ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (status == 2 || (status == 1 && i == 9))
            ans += dfs(pos - 1, 2, flag || i < num);
        //如果前len位已经有了49
        //或者原来高位是4（用status==1表示前一位是4） ，且该位枚举的9，即构成了49这个串
        else if (i == 4)
            ans += dfs(pos - 1, 1, flag || i < num);
        //第len位枚举的是4，符合status=1
        else
            ans += dfs(pos - 1, 0, flag || i < num);
        //不是任何特殊情况，那就是status=0
    }
    if (flag)
        dp[pos][status] = ans;
    //flag=1，说明可以计数
    //否则，这个数会大于n，计数没有意义
    return ans;
}

__int64 calc(__int64 n)
{
    //标准格式
    //将n分解成各个数位，从高到低
    int pos = 0;
    while (n)
    {
        digit[++pos] = n % 10;
        n /= 10;
    }
    return dfs(pos, 0, 0);
}

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &n);
        memset(digit, 0, sizeof(digit));
        memset(dp, -1, sizeof(dp));
        printf("%I64d\n", calc(n));
    }
    return 0;
}

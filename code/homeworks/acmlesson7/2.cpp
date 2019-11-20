#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return a % b ? gcd(b, a % b) : b;
}

void printddd(int x)
{
    if (x & 1)
    {
        cout << "NO\n";
    }
    else
        cout << x - 1 << endl;
}

int main()
{
    int a, b, c;
    while ((cin >> a >> b >> c) && (a || b || c))
    {
        a /= gcd(b, c);
        printddd(a);
    }
}
/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    int a[3];
    int t;
} date[1000000];
int tail, head;
int dp[110][110][110];
int s, a, b;
int ar[3];
int main()
{
    while (cin >> s >> a >> b)
    {
        if (s == 0 && a == 0 && b == 0)
            break;
        if (s % 2 != 0)
        {
            printf("NO\n");
            continue;
        }
        head = 0;
        tail = 0;
        ar[0] = s;
        ar[1] = a;
        ar[2] = b;
        for (int i = 0; i <= s; i++)
        {
            for (int j = 0; j <= a; j++)
            {
                for (int k = 0; k <= b; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        //dp[s][0][0] = 0;
        date[tail].a[0] = s;
        date[tail].a[1] = 0;
        date[tail].a[2] = 0;
        date[tail].t = 0;
        tail++;
        int ans = 1 << 29;
        while (tail ^ head)
        {
            if (dp[s / 2][s / 2][0] != -1 && s / 2 <= ar[1])
                ans = dp[s / 2][s / 2][0];
            if (dp[s / 2][s / 2][0] != -1 && s / 2 <= ar[1] && s / 2 <= ar[2])
                ans = min(ans, dp[0][s / 2][s / 2]);
            if (dp[s / 2][0][s / 2] != -1 && s / 2 <= ar[2])
                ans = min(ans, dp[s / 2][0][s / 2]);
            if(date[head].t>=ans){
                head++;
                continue;
            }
            if (dp[date[head].a[0]][date[head].a[1]][date[head].a[2]] <= date[head].t && dp[date[head].a[0]][date[head].a[1]][date[head].a[2]] != -1)
            { //printf("%d %d %d\n",date[head].a[0],date[head].a[1],date[head].a[2]);
                head++;
                continue;
            }
            else
            { // printf("%d %d %d\n",date[head].a[0],date[head].a[1],date[head].a[2]);
                dp[date[head].a[0]][date[head].a[1]][date[head].a[2]] = date[head].t;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i != j)
                    {
                        if (date[head].a[i] != 0 && date[head].a[j] < ar[j])
                        {
                            if (date[head].a[i] < ar[j] - date[head].a[j])
                            {
                                date[tail].a[j] = date[head].a[i] + date[head].a[j];
                                date[tail].a[i] = 0;
                                date[tail].a[(3 - i - j)] = date[head].a[(3 - i - j)];
                                date[tail].t = date[head].t + 1;
                                tail++;
                            }
                            else
                            {
                                date[tail].a[i] = date[head].a[i] - ar[j] + date[head].a[j];
                                date[tail].a[j] = ar[j];
                                date[tail].a[(3 - i - j)] = date[head].a[(3 - i - j)];
                                date[tail].t = date[head].t + 1;
                                tail++;
                            }
                        }
                    }
                }
            }
            head++;
        }
        if (ans != 1 << 29)
            printf("%d\n", ans);
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
*/
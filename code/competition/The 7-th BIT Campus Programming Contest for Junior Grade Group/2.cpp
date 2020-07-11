#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int mem[20];
void work()
{
    char tmp[1000];
    scanf("%s", tmp);
    int a;
    scanf("%lld", &a);
    if (strcmp(tmp, "allocate") == 0)
    {
        int f = -1;
        int flag = 0;
        for (int i = 0; i < 11; i++)
        {
            if (mem[i] && (1 << i) == a)
            {
                flag = 1;
                mem[i]--;
                break;
            }
            if (mem[i] && (1 << i) > a)
            {
                f = i;
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < 11; i++)
            {
                printf("%d ", mem[i]);
            }
            printf("\n");
            return;
        }
        if (f == -1)
        {
            printf("ERROR!\n");
            return;
        }
        int mi = 0;
        for (int i = 0; i < 11; i++)
        {
            if (a & (1 << i))
            {
                mi = i;
                break;
            }
        }
        //cout << "f=" << f << endl;
        mem[mi] += 2;
        for (int i = mi + 1; i < f; i++)
        {
            mem[i]++;
        }
        int cnt = 0;
        while (a)
        {
            if (a & 1)
            {
                mem[cnt]--;
            }
            cnt++;
            a >>= 1;
        }
        mem[f]--;
        for (int i = 0; i < 11; i++)
        {
            printf("%d ", mem[i]);
        }
        printf("\n");
    }
    else
    {
        int cnt = 0;
        while (a)
        {
            if (a & 1)
            {
                mem[cnt]++;
            }
            a >>= 1;
            cnt++;
        }
        for (int i = 0; i < 11; i++)
        {
            printf("%d ", mem[i]);
        }
        printf("\n");
    }
}

signed main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    memset(mem, 0, sizeof(mem));
    while (t--)
    {
        work();
    }
    return 0;
}
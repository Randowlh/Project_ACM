#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int hard;
    int t;
    bool operator<(node a)
    {
        return this->t < a.t;
    }
} date[200010];
int head = 0;
ll dph[200010];
ll dpe[200010];
void work()
{
    int n, t, a, b;
    int cnte = 0;
    int cnth = 0;
    scanf("%d%d%d%d", &n, &t, &a, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i].hard);
        if (date[i].hard == 1)
        {
            cnth++;
        }
        else
            cnte++;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i].t);
    }
    sort(date, date + n);
    dph[0] = 0;
    dpe[0] = 0;
    ll ans = 0;
    for (int i = 1; i <= t; i++)
    {
        dpe[i] = dpe[i - 1];
        dph[i] = dph[i - 1];
        if (head < n && date[head].t <= t)
        {
            if (date[head].hard == 1)
            {
                dph[i]++;
            }
            else
            {
                dpe[i]++;
            }
            head++;
        }
        if (a * dpe[i] + b * dph[i] > t)
            continue;
        else
        {
            ll tm = t - a * dpe[i] - b * dph[i];
            ll tmp = dpe[i] + dph[i];
            if (tm > a && cnte - dpe[i] > 0)
            {
                if (tm < a * (cnte - dpe[i]))
                {
                    tmp += tm / a;
                    tm %= a;
                }
                else
                {
                    tmp += cnte - dpe[i];
                    tm -= a * (cnte - dpe[i]);
                }
            }
            if (tm > b && cnth - dph[i] > 0)
            {
                if (tm < b * (cnth - dph[i]))
                {
                    tmp += tm / b;
                    tm %= a;
                }
                else
                {
                    tmp += (cnth - dph[i]);
                    tm -= b * (cnth - dph[i]);
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
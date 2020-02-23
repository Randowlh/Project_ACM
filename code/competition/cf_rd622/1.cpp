#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
    sort(a, a + 3);
    if (a[0] > 0)
    {
        ans++;
        a[0]--;
    }
    if (a[1] > 0)
    {
        a[1]--;
        ans++;
    }
    if (a[2] > 0)
    {
        a[2]--;
        ans++;
    }
    if (a[2] > 2 && a[1] && a[0])
    {
        a[2] -= 2;
        a[1]--;
        a[0]--;
        ans += 2;
    }
    else
    {
        if (a[2] && a[1])
        {
            a[2]--;
            a[1]--;
            ans++;
        }
        if (a[2] && a[0])
        {
            a[2]--;
            a[0]--;
            ans++;
        }
    }
    if (a[1] && a[0])
    {
        a[1]--;
        a[0]--;
        ans++;
    }
    if (a[1] && a[0] && a[2])
    {
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
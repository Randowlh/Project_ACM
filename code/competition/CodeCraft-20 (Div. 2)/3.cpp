#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int a[1001000], b[1001000];
void work()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    int mixa;
    int mixb;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] % p)
        {
            mixa = i;
            break;
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (b[i] % p)
        {
            mixb = i;
            break;
        }
    }
    cout << mixb + mixa << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    cout << 2;
    for (int i = 0; i < n - 1; i++)
    {
        cout << 3;
    }
    cout << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int t)
{
    if (t > 10000000)
    {
        return;
    }
    if (t % 10000 == 0)
        cout << t << ' ';
    dfs(t + 1);
    return;
}
signed main()
{
    cout << "dadad" << endl;
    dfs(0);
}
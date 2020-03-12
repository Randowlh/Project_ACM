#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    string tmp;
    cin >> tmp;
    int ans = 0;
    int pr = -1;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 'R')
        {
            ans = max(ans, i - pr);
            pr = i;
        }
    }
    ans = max(ans, (int)tmp.size() - pr);
    cout << ans << endl;
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
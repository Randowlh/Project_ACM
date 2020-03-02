#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    int ans = 0;
    int flag[200];
    for (int i = 0; i < n; i++)
    {
        flag[i] = 1;
    }
    int cnt = 0;
    while (cnt < n)
    {
        int ma = 0;
        int maa = 0;
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 1 && tmp[i] >= ma)
            {
                ma = tmp[i];
                maa = i;
            }
        }
        if (ma == 'a')
            break;
        for (int i = maa + 1; i < n; i++)
        {
            if (flag[i] == 0)
            {
                continue;
            }
            else if (flag[i] == -1)
                break;
            else if (tmp[i] == ma - 1)
            {
                flag[maa] = 0;
                ans++;
                break;
            }
            else if (ma == tmp[i])
                continue;
            else
            {
                break;
            }
        }
        if (flag[maa] == 1)
            for (int i = maa - 1; i >= 0; i--)
            {
                if (flag[i] == 0)
                {
                    continue;
                }
                else if (flag[i] == -1)
                    break;
                else if (tmp[i] == ma - 1)
                {
                    flag[maa] = 0;
                    ans++;
                    break;
                }
                else if (tmp[i] == ma)
                    continue;
                else
                {
                    break;
                }
            }
        if (flag[maa] == 1)
        {
            flag[maa] = -1;
        }
        cnt++;
    }
    cout << ans << endl;
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
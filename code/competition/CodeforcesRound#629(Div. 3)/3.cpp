#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
void work()
{
    int n;
    string tmp;
    cin >> n >> tmp;
    int f = 0;
    string ans1;
    string ans2;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '2')
        {
            if (!f)
            {
                ans1.push_back('1');
                ans2.push_back('1');
                continue;
            }
            else
            {
                ans1.push_back('0');
                ans2.push_back('2');
                continue;
            }
        }
        if (tmp[i] == '1')
        {
            if (!f)
            {
                ans1.push_back('1');
                ans2.push_back('0');
                f = 1;
                continue;
            }
            else
            {
                ans1.push_back('0');
                ans2.push_back('1');
                continue;
            }
        }
        if (tmp[i] == '0')
        {
            ans1.push_back('0');
            ans2.push_back('0');
            continue;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
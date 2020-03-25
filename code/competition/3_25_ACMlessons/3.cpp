#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
int biao[] = {2, 5, 7, 3};
void work()
{
    int n;
    cin >> n;
    vector<int> yz;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            yz.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n != 1)
    {
        yz.push_back(n);
    }
    for (int i = 0; i < yz.size(); i++)
    {
        int f = 0;
        for (int j = 0; j < 4; j++)
        {
            if (biao[j] == yz[i])
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
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
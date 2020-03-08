#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    string tmp;
    cin >> tmp;
    int t = tmp.size();
    vector<ll> yz;
    for (int i = 1; i <= t; i++)
    {
        if (t % i == 0)
            yz.push_back(i);
    }
    sort(yz.begin(), yz.end());
    int len = unique(yz.begin(), yz.end()) - yz.begin();
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (yz[i] >= tmp.size())
        {
            len = i;
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        int fl = 1;
        for (int j = 0; j < yz[i]; j++)
        {
            for (int k = 1; k < (tmp.size() / yz[i]); k++)
            {
                if (tmp[k * yz[i] + j] != tmp[j])
                {
                    fl = 0;
                    break;
                }
            }
            if (fl == 0)
            {
                break;
            }
        }
        if (fl)
        {
            cout << tmp.substr(0, yz[i]) << endl;
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
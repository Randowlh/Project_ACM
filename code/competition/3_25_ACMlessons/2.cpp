#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
void work()
{
    string tmp;
    while (cin >> tmp)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            {
                tmp[i] -= 'A';
                tmp[i] += 'a';
            }
        }
        cout << tmp << endl;
    }
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
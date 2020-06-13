#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const int maxn = 1000010;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
vector<int> primes;
int he[1000100];
bool is_prime[1000100];
void euler()
{
    is_prime[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!is_prime[i])
        {
            primes.push_back(i);
            he[i] = i + 1;
        }
        for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
        {
            is_prime[i * primes[j]] = 1;
            if ((i % primes[j]) == 0)
                break;
        }
    }
}
void work()
{
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
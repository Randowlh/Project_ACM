#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200010;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
vector<int> primes;
bool is_prime[100000100];
void euler()
{
    is_prime[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!is_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
        {
            is_prime[i * primes[j]] = 1;
            if ((i % primes[j]) == 0)
                break;
        }
    }
}
int n;
void work()
{
    euler();
    cout << primes.size() << endl;
    for (int i = 0; i < primes.size();i++){
    //    cout<<primes[i]<<',';
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
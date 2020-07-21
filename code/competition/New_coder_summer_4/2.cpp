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
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
};
const int maxn = 200100;
vector<int> primes;
bool is_prime[210100];
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
//map<int, vector<int>> M;
bool fl[210100];
int now[210100];
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void work()
{
    vector<pair<int, int>> ans;
    int n;
     n=read();
    for (int i = 0; i <= n;i++){
        fl[i] = 0;
    }
    for (int i = primes.size() - 1; i >= 0; i--)
        {
            if (primes[i] * 2 > n)
            {
                continue;
            }
            int cnt = 0;
            now[cnt++] =primes[i];
            for (int j = 2; j <10000000;j++){
                if(primes[i]*j>n)
                    break;
                if (fl[primes[i]*j])
                continue;
                now[cnt++] = primes[i]*j;
            }
            if(cnt==1){
                continue;
            }
            if (cnt % 2 == 0)
                {
                    for (int j = 0; j < cnt; j += 2)
                    {
                        fl[now[j]] = fl[now[j+1]] = 1;
                        ans.push_back(make_pair(now[j],now[j+1]));
                    }
                }
                else
                {
                    fl[now[0]] = fl[now[2]] = 1;
                    ans.push_back(make_pair(now[0], now[2]));
                    for (int j = 3; j < cnt; j += 2)
                    {
                        fl[now[j]] = fl[now[j+1]] = 1;
                        ans.push_back(make_pair(now[j], now[j+1]));
                    }
                }
        }
    printf("%d\n",ans.size());
    for (int i = 0;i<ans.size();i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
}
signed main()
{   
    euler();
   // freopen("in.txt", "r", stdin);
    int t = 1;
    t = read();
    //cout << t << endl;
    while (t--)
    {
        work();
    }
    return 0;
}
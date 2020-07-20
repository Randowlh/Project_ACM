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
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void work()
{
    set<int> ard;
    vector<pair<int, int>> ans1,ans2;
    int n;
    n = read();
    //printf("%d\n", n);
    for(int i=0;i<primes.size();i++){
      //  printf("adasdas");
        if(primes[i]>n)
            break;
        for (int k = 1; k < 100000;k++){
            int now = primes[i]*k;
            if(now > n) break;
            if(ard.count(now))
            continue;
            while(primes[i]*(k+1)<=n){
                k++;
                if(ard.count(primes[i]*k)){
                    continue;
                }
                ans1.push_back(make_pair(now, primes[i] * k));
                ard.insert(now);
                ard.insert(primes[i] * k);
                break;
            }
        }
    }
    for(int i=primes.size();i>=0;i--){
      //  printf("adasdas");
        if(primes[i]>n)
            continue;
        for (int k = 1; k < 100000;k++){
            int now = primes[i]*k;
            if(now > n) break;
            if(ard.count(now))
            continue;
            while(primes[i]*(k+1)<=n){
                k++;
                if(ard.count(primes[i]*k)){
                    continue;
                }
                ans2.push_back(make_pair(now, primes[i] * k));
                ard.insert(now);
                ard.insert(primes[i] * k);
                break;
            }
        }
    }
    if(ans1.size()>ans2.size()){
    printf("%d\n", ans1.size());
    for(int i=0;i<ans1.size(); i++){
        printf("%d %d\n",ans1[i].first,ans1[i].second);
    }
    }else{
        for(int i=0;i<ans2.size(); i++){
        printf("%d %d\n",ans2[i].first,ans2[i].second);
    }
    }
}
signed main()
{
    euler();
    //freopen("in.txt", "r", stdin);
    int t = 1;
    t = read();
    //cout << t << endl;
    while (t--)
    {
        work();
    }
    return 0;
}
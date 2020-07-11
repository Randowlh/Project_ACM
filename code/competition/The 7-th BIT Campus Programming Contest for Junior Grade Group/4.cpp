#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
#define mst(x) memset(x, 0, sizeof(x));
#define yx_queue priority_queue
#define PI acos(-1)
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double db;
typedef long long ll;
const ll mod = 998244353;
//const ll mod=1000000007
const int N = 1e6 + 5;
const int inf = 1 << 30;
const ll llf = 9e18;
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
struct node
{
    ll no, w;
    //	friend bool operator<(const node &a,const node&b)
    //    {
    //    	return a.k>b.k;//小的在前
    //    }
};
bool cmp(node x, node y)
{
    return x.w < y.w;
}
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
//while(rp++)

ll a[1000100];
node b[1000100];
int main()
{
    //ios::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        rep(i, 1, m)
        {
            scanf("%d", &a[i]);
            b[i].w = a[i];
            b[i].no = i;
        }
        sort(b + 1, b + m + 1, cmp);
        b[0].w = 0;
        b[0].no = 0;
        b[m + 1].w = n + 1;
        b[m + 1].no = m + 1;
        ll ans = 0;
        if (k != 0)
            rep(i, 1, m - k + 1)
            {
                if (b[i].w == b[i - 1].w || b[i + k].w == b[i + k - 1].w)
                    continue;
                ans = (ans + (b[i].w - b[i - 1].w) * (b[i + k].w - b[i + k - 1].w) % mod + mod) % mod;
            }
        else
        {
            rep(i, 1, m + 1)
            {
                ll x = b[i].w - b[i - 1].w - 1;
                if (x < 0)
                    x = 0;
                ans = (ans + x * (x + 1) / 2) % mod;
            }
        }
        cout << (ans * powmod(n * (n + 1) / 2, mod - 2)) % mod;
    }
    return 0;
}

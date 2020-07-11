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
//const ll mod=1000000007;
const int N = 1e6 + 5;
const int inf = 1 << 30;
const ll llf = 9e18;
inline ll powmod(ll a, ll b)
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
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
struct node
{
    int no, w;
    //	friend bool operator<(const node &a,const node&b)
    //    {
    //    	return a.k>b.k;//小的在前
    //    }
};
bool cmp(node x, node y)
{
    return x.w > y.w;
}
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
//while(rp++)

int a[100010];
int f[100010];
int main()
{
    //ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        rep(i, 1, n)
        {
            scanf("%d", &a[i]);
            f[i] = 0;
        }
        rep(i, 1, n - 2)
        {
            if (f[i] != 0)
                continue;
            bool flag = false;
            int x = min(n, i + 41);
            rep(j, i + 2, x)
            {
                rep(k, i, j - 2)
                {
                    rep(p, k + 1, j - 1)
                    {
                        if (a[j] + a[k] > a[p] && a[j] + a[p] > a[k] && a[p] + a[k] > a[j])
                        {
                            rep(o, i, k)
                            {
                                f[o] = j;
                            }
                            flag = true;
                            i = k;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
            if (!flag)
                break;
        }
        int l, r;
        rep(i, 1, m)
        {
            scanf("%d%d", &l, &r);
            if (r >= f[l] && f[l] != 0)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
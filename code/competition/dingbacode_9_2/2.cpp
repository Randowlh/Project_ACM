#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template <class T>
inline void MAX(T &x, T y)
{
    if (y > x)
        x = y;
}
template <class T>
inline void MIN(T &x, T y)
{
    if (y < x)
        x = y;
}
template <class T>
inline void rd(T &x)
{
    x = 0;
    char o, f = 1;
    while (o = getchar(), o < 48)
        if (o == 45)
            f = -f;
    do
        x = (x << 3) + (x << 1) + (o ^ 48);
    while (o = getchar(), o > 47);
    x *= f;
}
template <class T>
void wt(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        wt(x / 10);
    putchar('0' + x % 10);
}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm = 1;
const int maxn = 510000;
mt19937 rnd(233);
int nxt[210000];
inline void cal_next(string &str)
{
    nxt[0] = -1;
    int k = -1;
    for (int q = 1; q < str.size(); q++)
    {
        while (k > -1 && str[k + 1] != str[q])
            k = nxt[k];
        if (str[k + 1] == str[q])
            k = k + 1;
        nxt[q] = k;
    }
}
int ans = 0;
void KMP(string &a, string &b)
{
    cal_next(b);
    int k = -1;
    for (int i = 0; i < a.size(); i++)
    {
        while (k > -1 && b[k + 1] != a[i])
            k = nxt[k];
        if (b[k + 1] == a[i])
            k = k + 1;
        if (k == b.size() - 1)
            ans++, k = nxt[k];
    }
    return;
}
int cnt[300];
void work()
{
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    string tmp;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        cnt[a[i]]++;
    for(int i=0;i<b.size();i++)
        cnt[b[i]]--;
    char key;
    for(int i=0;i<=300;i++)
        if(cnt[i]){
            key=i;
            break;
        }
     ans = 0;
    KMP(a, b);
    if (ans == 1)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]!=key)
            continue;
        if(i>=1&&a[i-1]==key)
            continue;
        tmp.clear();
        for (int j = 0; j < a.size(); j++)
            if (j != i)
                tmp.push_back(a[j]);
        tmp += tmp;
        ans = 0;
        KMP(tmp, b);
        if (ans == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
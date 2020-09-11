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
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr = 233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm = 1;
const int maxn = 510000;
#include <vector>
#include <iostream>
#include <string>
using namespace std;
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
int KMP(string &a, string &b)
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
            return i;
    }
    return -1;
}
string Manacher(string s) {
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}
string tt,tmp;
int flag[1100];
void work()
{
    cin>>tmp;
    int ans=0;
    while(!tmp.empty()){
        int r=tmp.size()-1;
        ans++;
        for(int i=0;i<tmp.size();i++)
        flag[i]=0;
        for(int i=0;i<tmp.size();i++){
            int f=0;
            flag[i]=1;
            for(int j=r;j>i;j--){
                if(tmp[i]==tmp[j]){
                    f=1;
                    r=j-1;
                    break;
                }
            }
            if(!f)
                break;
            flag[i]=flag[r+1]=1;
        }
        tt.clear();
        for(int i=0;i<tmp.size();i++){
            if(!flag[i])
                tt.push_back(tmp[i]);
        }
        tmp=tt;
    }
    cout<<ans<<endl;
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
    cin>>t;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
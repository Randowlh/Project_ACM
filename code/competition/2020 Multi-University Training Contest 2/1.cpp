#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
typedef long long ll
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const int mod = (0 ? 1000000007 : 998244353);
const int mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node{
    int a, b, c, d;
    node(int aa,int bb,int cc,int dd):a(aa),b(bb),c(cc),d(dd){}
};
int aa=100, bb=100, cc=100, dd=100;
int a[1 << 25], b[1 << 25], c[1 << 25], d[1 << 25];
int tg[51];
vector<node> arr[51];
node zy[51];
void work()
{
    int n, k;
    rd(n), rd(k);
    int tp, a, b, c, d;
    for (int i = 0; i < n;i++){
        rd(tp), rd(a), rd(b), rd(c),rd(d);
        arr[tp].push_back(node(a, b, c, d));
    }
    int tll = 0;
    for (int i = 1; i <= k;i++){
        if(!arr[i].size())
        continue;
        if(arr[i].size()==1){
            aa+=arr[i][0].a,bb+=arr[i][0].b,cc+=arr[i][0].c,dd+=arr[i][0].d;
            continue;
        }
        for (int j = 0; j < arr[i].size();j++){
            tg[tll] = i;
            zy[tll++] = arr[i][j];
        }
    }
    int ans = 0;
    a[0] = aa, b[0] = bb, c[0] = cc, d[0] = dd;
    for (int i = 1; i <= 1 << tll - 1;i++){
        int ti = i;
        int pr = 0;
        cnt = 1;
        int f = 0;
        while(1){
            if(ti&1){
                if(tg[pr]==tg[cnt])
                    f = 1, break;
                pr = cnt;
            }
            ti >>= 1;
            cnt++;
        }
        if(f)
        continue;
        for (int j = 0; j < tll;j++){
            if((1<<j)&i){
                aa[i] = aa[i ^ (1 << j)] + zy[i].a;
                bb[i] = bb[i ^ (1 << j)] + zy[i].b;
                cc[i] = cc[i^(1<<j)]+zy[i].c;
                dd[i] = dd
            }
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
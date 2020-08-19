#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 2e5+5;
int n;
struct Node
{
    int mi=0;
    int l,r;
    int val,key;
    int size;
    bool rs;
}fhq[maxn];
int cnt,root;
mt19937 rnd(233);
inline int newnode(int val)
{
    fhq[++cnt].val=val;
    fhq[cnt].mi=val;
    fhq[cnt].key=rnd();
    fhq[cnt].size=1;
    return cnt;
}
inline void update(int now)
{
    fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
    fhq[now].mi=min(fhq[now].mi,min(fhq[fhq[now].l].mi,fhq[fhq[now].r].mi));
}
inline void pushdown(int now)
{
    std::swap(fhq[now].l,fhq[now].r);
    fhq[fhq[now].l].rs^=1;
    fhq[fhq[now].r].rs^=1;
    fhq[now].rs=false;
}
void split(int now,int siz,int &x,int &y)
{
    if(!now) x=y=0;
    else 
    {
        if(fhq[now].rs) pushdown(now);
        if(fhq[fhq[now].l].size<siz)
        {
            x=now;
            split(fhq[now].r,siz-fhq[fhq[now].l].size-1,fhq[now].r,y);
        }
        else 
        {
            y=now;
            split(fhq[now].l,siz,x,fhq[now].l);
        }
        update(now);
    }
}
int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key)
    {
        if(fhq[x].rs) pushdown(x);
        fhq[x].r=merge(fhq[x].r,y);
        update(x);
        return x;
    }
    else 
    {
        if(fhq[y].rs) pushdown(y);
        fhq[y].l=merge(x,fhq[y].l);
        update(y);
        return y;
    }
}
void rs(int l,int r)
{
    int x,y,z;
    split(root,l-1,x,y);
    split(y,r-l+1,y,z);
    fhq[y].rs^=1;
    root=merge(merge(x,y),z);
}
int find (int now,int l,int r,int v){
    if(l==r)return now;
    int mid=(l+r)>>1;
    int x,y,t,res;
    if(fhq[now].rs) pushdown(now);
    update(now);
    split(now,mid-l+1,x,y);
    if(fhq[y].mi<v)res=find(y,mid+1,r,v);
    now=merge(x,y); return res;
}
inline int& getnum(int rank)
    {
        int now=root;
        while(now)
        {
            if(fhq[fhq[now].l].size+1==rank)
                break;
            else if(fhq[fhq[now].l].size>=rank)
                now=fhq[now].l;
            else
            {
                rank-=fhq[fhq[now].l].size+1;
                now=fhq[now].r;
            }  
        }
        return fhq[now].val;
    }
void work()
{
    int q;
    rd(n),rd(q);
    int tmp;
    for(int i=1;i<=n;i++){
        rd(tmp);
        root=merge(root,newnode(tmp));
    }
    int opt;
    int x,y;
    for(int i=0;i<q;i++){
        rd(opt);
        if(opt==1){
            rd(x),rd(y);
            int i;
            i=x;
            int tol=0;
            i=find(root,1,x,y);
            if(i==1){
                printf("0\n");
                continue;
            }
            printf("%lld\n",tol);
            int t=getnum(i);
            rs(i,x);
            rs(i,x-1);
            getnum(x)=y-1;
            getnum(i)=t;
        }else{
            rd(x);
            printf("%lld\n",x);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",getnum(i));
    printf("\n");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
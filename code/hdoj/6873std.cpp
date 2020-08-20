#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
using namespace std;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
#define int long long
#define ll long long
const int maxn = 2e5 + 100;
mt19937 rnd(114514);
class fhq_treap
{
public:
    struct node
    {
        int l, r;
        int val, mi, key;
        int size;
        ll tol;
        int lazy;
    } T[maxn];
    int cnt, root;
    inline void clear(){
        cnt=0;
        root=0;
    }
    inline int newnode(int val)
    {
        T[++cnt].val = val;
        T[cnt].mi=T[cnt].tol=val;
        T[cnt].key = rnd();
        T[cnt].l = T[cnt].r = T[cnt].lazy = 0;
        T[cnt].size = 1;
        return cnt;
    }
    inline void pushup(int pos)
    {
        T[pos].size = 1;
        T[pos].mi = T[pos].val;
        T[pos].tol=T[pos].val;
        if (T[pos].l){
            T[pos].size += T[T[pos].l].size;
            MIN(T[pos].mi,T[T[pos].l].mi);
            T[pos].tol+=T[T[pos].l].tol;
        }
        if (T[pos].r){
            T[pos].size += T[T[pos].r].size;
            MIN(T[pos].mi,T[T[pos].r].mi);
            T[pos].tol+=T[T[pos].r].tol;
        }
    }
    inline void pushdown(int pos)
    {
        if (!T[pos].lazy)
            return;
        T[pos].lazy = false;
        swap(T[pos].l, T[pos].r);
        T[T[pos].l].lazy ^= 1;
        T[T[pos].r].lazy ^= 1;
    }
    void split(int now, int sz, int &x, int &y)
    {
        if (!now)
        {
            x = y = 0;
            return;
        }
        pushdown(now);
        if (sz == 0)
        {
            x = 0;
            y = now;
            return;
        }
        if (T[T[now].l].size < sz)
        {
            x = now;
            split(T[now].r, sz - T[T[now].l].size - 1, T[now].r, y);
        }
        else
        {
            y = now;
            split(T[now].l, sz, x, T[now].l);
        }
        pushup(now);
    }
    int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (T[x].key < T[y].key)
        {
            pushdown(x);
            T[x].r = merge(T[x].r, y);
            pushup(x);
            return x;
        }
        else
        {
            pushdown(y);
            T[y].l = merge(x, T[y].l);
            pushup(y);
            return y;
        }
    }
    inline void reverse(int l, int r)
    {
        int x, y, z;
        split(root, l - 1, x, y);
        split(y, r - l + 1, y, z);
        T[y].lazy ^= 1;
        root = merge(x, merge(y, z));
    }
    inline int getnum(int rk)
    {
        int x, y, z;
        split(root, rk - 1, x, y);
        split(y, 1, y, z);
        int ans = y;
        root = merge(x, merge(y, z));
        return T[ans].val;
    }
    int findx(int &now,int l,int r,int v){
        if(l==r)
            return l;
        int mid=(l+r)>>1;
        int x,y;
        int ans=1;
        split(now,mid-l+1,x,y);
        if(T[y].mi<v)
            ans=findx(y,mid+1,r,v);
        else ans=findx(x,l,mid,v);
        now=merge(x,y);
        return ans; 
    }
    inline int find(int l,int r,int v){
        int x,y;
        split(root,r,x,y);
        int ans= findx(x,l,r,v);
        root=merge(x,y);
        return ans;
    }
    inline ll gettol(int l,int r){
        int x,y,z;
        ll ans;
        split(root,l-1,x,y);
        split(y,r-l+1,y,z);
        ans=T[y].tol;
        root=merge(x, merge(y, z));
        return ans;
    }
    inline void changeval(int rk,int v){
        int x,y,z;
        split(root,rk-1,x,y);
        split(y,1,y,z);
        T[y].val=T[y].mi=T[y].tol=v;
        root=merge(x, merge(y, z));
    }
    inline void zx(int pos){
        if(T[pos].l)
            zx(T[pos].l);
        printf("%lld ",T[pos].val);
        if(T[pos].r)
            zx(T[pos].r);
    }
} fhq;
void work()
{
    fhq.clear();
    int n,q;
    rd(n),rd(q);
    int tmp;
    register int i;
    for(i=1;i<=n;++i){
        rd(tmp);
        fhq.root=fhq.merge(fhq.root,fhq.newnode(tmp));
    }
    int opt,x,y;
    for(i=0;i<q;++i){
        rd(opt);
        if(opt==1){
            rd(x),rd(y);
            if(fhq.getnum(x)<y){
                printf("0\n");
                continue;
            }
            int lft=fhq.find(1,x,y);
            if(lft==1){
                printf("0\n");
                continue;
            }   
            printf("%lld\n",fhq.gettol(lft+1,x)-(y-1)*(x-lft));
            int lv=fhq.getnum(lft);
            lv+=fhq.getnum(lft+1)-y+1;
            fhq.reverse(lft,x);
            fhq.reverse(lft,x-1);
            fhq.changeval(lft,lv);
            fhq.changeval(x,y-1);
        }else
        {
            rd(y);
            printf("%lld\n",fhq.getnum(y));
        }
    }
    fhq.zx(fhq.root);
    printf("\n");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
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

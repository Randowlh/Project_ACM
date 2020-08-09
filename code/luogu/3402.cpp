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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxn=110000;
const int maxm= 210000;
vector<int> root;
int n,m;
struct chair_man_tree{
    struct node{
        int lson,rson;
    }tree[maxn<<5];
    int tail=0;
    int tail2=0;
    int fa[maxn<<2];
    int depth[maxn<<2];
    inline int getnew(int pos){
        tree[++tail]=tree[pos];
        return tail;
    }
    int build(int l,int r){
        
        if(l==r){
            fa[++tail2]=l;
            depth[tail2]=1;
            return tail2;
        }
        int now=tail++;
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int query(int pos,int l,int r,int qr){
        // cout<<l<<" dddd "<<r<<endl;
        // if(l>r)
        //     return 0;
        // cout<<"pos="<<pos<<endl;
        // cout<<"l"<<l<<" r"<<r<<endl;
        if(l==r)
            return pos;
        int mid=(l+r)>>1;
        if(qr<=mid)
            return query(tree[pos].lson,l,mid,qr);
        else return query(tree[pos].rson,mid+1,r,qr);
    }
    int update(int pos,int l,int r,int qr,int val){
        if(l==r){
            depth[++tail2]=depth[pos];
            fa[tail2]=val;
            return tail2;
        }
        int now=getnew(pos);
        int mid=(l+r)>>1;
        if(mid>=qr)
            tree[now].lson=update(tree[now].lson,l,mid,qr,val);
        else tree[now].rson=update(tree[now].rson,mid+1,r,qr,val);
        return now;
    }
    int add(int pos,int l,int r,int qr){
        if(l==r){
            depth[++tail2]=depth[pos]+1;
            fa[tail2]=fa[pos];
            return tail2;
        }
        int now=getnew(pos);
        int mid=(l+r)>>1;
        if(mid>=qr)
            tree[now].lson=add(tree[now].lson,l,mid,qr);
        else tree[now].rson=add(tree[now].rson,mid+1,r,qr);
        return now;
    }
    int getfa(int root,int qr){
        int t=fa[query(root,1,n,qr)];
        if(qr==t)
        return qr;
        else return getfa(root,t);
    }
}t;
void merge(int a,int b){
    int f1=t.getfa(root[root.size()-1],a);
            int f2=t.getfa(root[root.size()-1],b);
            if(f1==f2){
                root.push_back(root[root.size()-1]);
                return;
            }
            int d1=t.depth[t.query(root[root.size()-1],1,n,f1)];
            int d2=t.depth[t.query(root[root.size()-1],1,n,f2)];
            int tmp;
            if(d1>d2)
                swap(f1,f2);
            tmp=t.update(root[root.size()-1],1,n,f1,f2);
            if(d1==d2)
                tmp=t.add(tmp,1,n,f2);
            root.push_back(tmp);
}
void work()
{
    rd(n),rd(m);
    root.push_back(t.build(1,n));
    int opt,a,b;
    for(int i=1;i<=m;i++){
        rd(opt);
        if(opt==1){
            rd(a),rd(b);
            int f1=t.getfa(root[root.size()-1],a);
            int f2=t.getfa(root[root.size()-1],b);
            if(f1==f2){
                root.push_back(root[root.size()-1]);
                continue;
            }
            int d1=t.depth[t.query(root[root.size()-1],1,n,f1)];
            int d2=t.depth[t.query(root[root.size()-1],1,n,f2)];
            int tmp;
            if(d1>d2)
                swap(f1,f2);
            tmp=t.update(root[root.size()-1],1,n,f1,f2);
            if(d1==d2)
                tmp=t.add(tmp,1,n,f2);
            root.push_back(tmp);
        }else if(opt==2){
            rd(a);
            root.push_back(root[a]);
        }else if(opt==3){
            rd(a),rd(b);
            a=t.getfa(root[root.size()-1],a);
            b=t.getfa(root[root.size()-1],b);
            if(a==b)
                printf("1\n");
            else printf("0\n");
            root.push_back(root[root.size()-1]);
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
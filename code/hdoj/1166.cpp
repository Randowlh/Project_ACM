#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SegmentTree{
    #define lson (rt<<1)
    #define rson (rt<<1|1)
    #define mid  ((l+r)>>1)
    ll sum[500000],flag[500000];
    bool clr[500000];
    int n;
    void up(int l,int r,int rt,ll x){
        sum[rt]+=(r-l+1)*x;
        flag[rt]+=x;
    }
    void pushdown(int l,int r,int rt){
        if(clr[rt]==1){
            clr[lson]=clr[rson]=1;
            sum[lson]=sum[rson]=flag[lson]=flag[rson]=0;
            clr[rt]=0;
        }
        if(flag[rt]){
            up(l,mid,lson,flag[rt]);
            up(mid+1,r,rson,flag[rt]);
            flag[rt]=0;
        }
    }
    void pushup(int rt){
        sum[rt]=sum[lson]+sum[rson];
    }
    void build(int l,int r,int rt){
        flag[rt]=sum[rt]=clr[rt]=0;
        if(l==r)return;
        build(l,mid,lson);
        build(mid+1,r,rson);
        pushup(rt);
    }
    void init(int _n){
        build(1,n,1);
    }
    void update(int l,int r,int rt,int x,int y,int z){
        if(x<=l&&r<=y){
            up(l,r,rt,z);
            return;
        }
        pushdown(l,r,rt);
        if(x<=mid)update(l,mid,lson,x,y,z);
        if(y>mid)update(mid+1,r,rson,x,y,z);
        pushup(rt);
    }
    int query(int l,int r,int rt,ll x){
        if(l==r){
            sum[rt]-=x;
            return l;
        }
        pushdown(l,r,rt);
        int re;
        if(sum[lson]>=x)re=query(l,mid,lson,x);
        else {
            re=query(mid+1,r,rson,x-sum[lson]);
            clr[lson]=1;
            sum[lson]=flag[lson]=0;
        }
        pushup(rt);
        return re;
    }
    int query(ll x){
        if(sum[1]<x)return 0;
        else return query(1,n,1,x);
    }
    void update(int l,int r,int x){
        update(1,n,1,l,r,x);
    }
}st;
int main(){
    freopen("in.txt","r",stdin);
    
}
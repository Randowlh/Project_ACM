#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
const int M=1e5+5;
const int K=M<<2;
const int S=200;
int cas,n,m,q,mxde,de[M],A[M],B[M],tot,head[M],to[M<<1],nxt[M<<1];
inline void add_edge(int a,int b){
    to[++tot]=b;
    nxt[tot]=head[a];
    head[a]=tot;
}
int listid,ad[M],ans[M],L[K],R[K],cnt[K];
void update(int x,int v,int f){
    if(v>=de[x])return;
    int pos=ad[x]+v;
    cnt[pos]+=f;
    if(f==1&&cnt[pos]==1){
        R[L[pos]]=R[pos];
        L[R[pos]]=L[pos];
        if(ans[x]==v)ans[x]=R[pos]-ad[x];
    }
    else if(f==-1&&cnt[pos]==0){
        int l=pos-1,r=pos+1;
        while(cnt[l])l--;
        while(cnt[r])r++;
        R[l]=pos,L[r]=pos;
        L[pos]=l,R[pos]=r;
        MIN(ans[x],v);
    }
}
int query(int x){
    return ans[x];
}
vector<int>vi[M];
void UPDATE(int x,int v){
    if(A[x]!=-1&&de[x]<S)
        for(int i=head[x];i;i=nxt[i])
            update(to[i],A[x],-1);
    A[x]=(v<=mxde)?v:-1;
    if(A[x]!=-1&&de[x]<S)
        for(int i=head[x];i;i=nxt[i])
            update(to[i],A[x],1);
}
int QUERY(int x){
    int sz=vi[x].size(),res=-1;
    for(int i=0;i<sz;i++)update(x,A[vi[x][i]],1);
    res=query(x);
    for(int i=0;i<sz;i++)update(x,A[vi[x][i]],-1);
    return res;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("jiedai.in","r",stdin);
    freopen("jiedai.out","w",stdout);
#endif
    rd(cas);
    while(cas--){
        mxde=tot=0,listid=1;
        memset(head,0,sizeof(head));
        memset(A,-1,sizeof(A));
        memset(de,0,sizeof(de));
        rd(n),rd(m);
        for(int i=1;i<=n;i++)rd(B[i]);
        for(int i=1;i<=m;i++){
            int a,b;
            rd(a),rd(b);
            add_edge(a,b),add_edge(b,a);
            MAX(mxde,++de[a]),MAX(mxde,++de[b]);
        }
        for(int x=1;x<=n;x++){
            vi[x].clear();
            for(int i=head[x];i;i=nxt[i])
                if(de[to[i]]>=S)vi[x].push_back(to[i]);
        }
        for(int i=1;i<=n;i++)ans[i]=0,ad[i]=listid,listid+=de[i]+1;
        for(int i=0;i<=listid;i++)L[i]=i-1,R[i]=i+1,cnt[i]=0;
        for(int i=1;i<=n;i++)UPDATE(i,B[i]);
        rd(q);
        while(q--){
            int op,x,y;
            rd(op),rd(x);
            if(op==1){
                rd(y);
                UPDATE(x,y);
            }
            else printf("%d\n",QUERY(x));
        }
    }
    return 0;
}

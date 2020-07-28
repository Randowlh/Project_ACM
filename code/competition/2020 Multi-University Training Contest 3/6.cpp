#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")    
#include <bits/stdc++.h>
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
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node{
    int date[10];
    bool operator<(const node a)const {
        for(int i=0;i<10;i++){
            if(date[i]!=a.date[i])
            return date[i]<a.date[i];
        }
        return false;
    }
};
map<node,int> M[20][10];
int disg[20];
int dfs(int pos,int d,node a,int flag,int flag2){
    if(!pos){
        int mx=0, mix=-1;
        for(int i=0;i<10;i++){
            if(mx==a.date[i])
            mix=-1;
            else
            if(mx<a.date[i]){
                mx=a.date[i];
                mix=i;
            }
          //  cout<<a.date[i]<<' ';
        }
        //cout<<"mix="<<mix<<' '<<mx<<endl;
        return mix==d;
    }
    if(!flag&&M[pos][d].count(a))
        return M[pos][d][a];
    int num=flag?9: disg[pos];
    int ans=0;
    for(int i=0;i<=num;i++){
        if(i!=0||flag2)
        a.date[i]++;
        ans+=dfs(pos-1,d,a,flag||i< num,flag2||i);
         if(i!=0||flag2)
        a.date[i]--;
    }   
    if(flag)
    M[pos][d][a]=ans;
    return ans;
}

int work(int x,int d)
{
    int cnt=1;
    while(x){
        disg[cnt]=x%10;
        x/=10;
        cnt++;
    }
   // cout<<"cnt="<<cnt<<endl;
    cnt--;
    node t;
    memset(t.date, 0, sizeof(t.date));
    return dfs(cnt,d,t,0,0);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    rd(t);
    //cin>>t;
    while (t--)
    {
        int l,r,d;
        rd(l),rd(r),rd(d);
        printf("%lld\n",work(r,d)-work(l-1,d));
    }
    return 0;
}
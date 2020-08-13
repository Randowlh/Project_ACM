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
//const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
pair<int,int> eg[610000];
int date[610000];
int depth[610000];
multiset<int> cnt[610000];
int ans[610000];
int find(int x){
    while(date[x]^x)
        x=date[x];
    return x;
}
void discn(int x,int y){
    if(find(x)!=find(y))
    return;
    if(date[x]==y){
        date[x]=x;
        int now=depth[x];
        int f=1;
        while(f){
            if(date[y]==y)
                f=0;
            cnt[y].erase(now);
            cnt[y].insert(depth[x]-now);
            depth[y]=*(cnt[y].rbegin())+1;
            y=date[y];
            now++;
        }
    }else{
        date[y]=y;
        int f=1;
        int now=depth[y];
        while(f){
            if(date[x]==x)
                f=0;
            cnt[x].erase(now);
            cnt[x].insert(depth[y]-now);
            depth[x]=*(cnt[x].rbegin())+1;
            x=date[x];
            now++;
        }
    }
}
void merge(int x,int y){
    int f1=find(x),f2=find(y);
    if(depth[f1]>=depth[f2]){
        date[f2]=f1;
        if(depth[f1]==depth[f2])
            depth[f1]++;
        cnt[f1].insert(depth[f2]);
    }else{
        date[f1]=f2;
        cnt[f2].insert(depth[f1]);
    }
}
void work()
{
    int n,m,q;
    scanf("%lld%lld%lld", &n, &m, &q);
    for(int i=0;i<=max(n+100,m+100);i++)
        depth[i]=1,date[i]=i,ans[i]=llinf,cnt[i].clear(),cnt[i].insert(0);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld",&eg[i].first,&eg[i].second);
    int now=1;
    int i=1;
    while(i<m&&now<=m){
        while(find(eg[now].first)==find(eg[now].second)&&i<now){
            ans[i]=now;
            discn(eg[i].first,eg[i].second);
            i++;
        }
        merge(eg[now].first,eg[now].second);
        now++;
    }
    ans[0]=ans[1];
    int u,v;
    int lastans=0;
    for(int i=0;i<q;i++){
        scanf("%lld%lld",&u,&v);
        u=(u^lastans)%(m+1);
        v=(v^lastans)%(m+1);
        if(u>v)
        swap(u,v);
        if(ans[u]<=v){
            lastans=1;
            printf("Yes\n");
        }else{ 
            printf("No\n");
            lastans=0;
        }
    }
}
signed main()
{
    //freopen("in.txt","r",stdin);
    int t = 1;
    scanf("%lld",&t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
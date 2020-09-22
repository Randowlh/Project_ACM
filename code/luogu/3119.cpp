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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define fst first
#define snd second
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
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
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 110000;
int n,m;
vector<int> mp[maxn],mp2[maxn],mpf[maxn];
int low[maxn],belong[maxn],dfn[maxn],sz[maxn];
bool instack[maxn];
int du1[maxn],du2[maxn];
pair<int,int>  depth[maxn];
int cnt1=0,cnt2=0;
stack<int> s;
vector<pair<int,int>> eg;
void pre(){
    queue<int> q;
    q.push(belong[1]);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<mp2[t].size();i++){
            int to=mp2[t][i];
            du1[to]++;
            if(du1[to]==1)
                q.push(to);
        }
    }
    q.push(belong[1]);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<mpf[t].size();i++){
            int to=mpf[t][i];
            du2[to]++;
            if(du2[to]==1)
                q.push(to);
        }
    }
}
void tarjan(int x){
    cnt1++;
    dfn[x]=low[x]=cnt1;
    instack[x]=true;
    s.push(x);
    for(int i=0;i<mp[x].size();i++){
        int to=mp[x][i];
        if(!dfn[to]){
            tarjan(to);
            MIN(low[x],low[to]);
        }else if(instack[to])
            MIN(low[x],dfn[to]);
    }
    if(low[x]==dfn[x]){
        belong[x]=++cnt2;
        sz[cnt2]=1;
        while(s.top()!=x){
            instack[s.top()]=false;
            belong[s.top()]=cnt2;
            s.pop();
            sz[cnt2]++;
        }
        instack[x]=false;
        s.pop();
    }
}
void work()
{
    rd(n),rd(m);
    int u,v;
    for(int i=1;i<=m;i++){
        rd(u),rd(v);
        mp[u].push_back(v);
        eg.pb(MP(u,v));
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<eg.size();i++)
        if(belong[eg[i].fst]^belong[eg[i].snd]){
            mp2[belong[eg[i].fst]].push_back(belong[eg[i].snd]);
            mpf[belong[eg[i].snd]].push_back(belong[eg[i].fst]);
        }
    pre();
    queue<pair<int,int>> q;
    q.push(MP(belong[1],sz[belong[1]]));
    depth[belong[1]]=MP(sz[belong[1]],0);
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        for(int i=0;i<mp2[t.fst].size();i++){
            int to=mp2[t.fst][i];
            MAX(depth[to].fst,t.snd);
            du1[to]--;
            if(!du1[to]){
                depth[to].fst+=sz[to];
                q.push(MP(to,depth[to].fst));
            }
        }
    }
    q.push(MP(belong[1],0));
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        for(int i=0;i<mpf[t.fst].size();i++){
            int to=mpf[t.fst][i];
            MAX(depth[to].snd,t.snd);
            du2[to]--;
            if(!du2[to]){
                depth[to].snd+=sz[to];
                q.push(MP(to,depth[to].snd));
            }
        }
    }
    int ans=0;
    for(int i=0;i<eg.size();i++)
        if(belong[eg[i].fst]^belong[eg[i].snd])
            MAX(ans,depth[belong[eg[i].fst]].snd+depth[belong[eg[i].snd]].fst);
    for(int i=1;i<=cnt2;i++){
        if(depth[i].snd&&depth[i].fst){
            cout<<"YES"<<endl;
        }
    }
    wt(ans),pt('\n');
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
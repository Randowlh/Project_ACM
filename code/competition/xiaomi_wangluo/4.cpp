#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-st-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 610000;
const int maxn = 610000;
const int N=300010;
const int M=300020;
int fa[N];
int find(int x){
    if(fa[x]==x)
        return x;
    else return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    fa[l]=r;
}
// const int maxn=1e5+5;
// const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],sz;
int n,t,bcccnt;
//n点数，t是dfs的时间轴，bcccnt是双连通分量个数
int stx[maxn],low[maxn],bcc[maxn],cut[maxn];
//stx是节点在dfs时间轴的位置，low是该点能够通过后继节点到达的最远祖先，bcc是某个点所属的双连通分量编号（割点的编号无效），cut是是否为割点
vector<int>bccs[maxn];
//双连通分量内的节点
stack<int>S;

void init(){
    memset(head,-1,sizeof(head));
    sz=0;
}

void add(int a,int b){
    point[sz]=b;
    nxt[sz]=head[a];
    head[a]=sz++;
    point[sz]=a;
    nxt[sz]=head[b];
    head[b]=sz++;
}

void dfs(int s,int pre){
    stx[s]=low[s]=++t;        //记录点的时间轴标号，初始化能访问到的最远祖先节点是自己
    S.push(s);
    int son=0;                //为了判定根节点是否是割点
    for(int i=head[s];~i;i=nxt[i]){
        int j=point[i];
        if(!stx[j]){
            son++;
            dfs(j,s);
            low[s]=min(low[s],low[j]);    //用子节点的low值更新自己
            if(low[j]>=stx[s]){            //如果子节点最远只能访问自己或后继节点，则出现双连通分量
                cut[s]=1;                //自己是割点
                bcccnt++;
                bccs[bcccnt].clear();
                while(1){
                    int u=S.top();S.pop();
                    bcc[u]=bcccnt;
                    bccs[bcccnt].push_back(u);
                    if(u==j)break;
                }
                bcc[s]=bcccnt;
                bccs[bcccnt].push_back(s);
            }
        }
        else if(j!=pre)low[s]=min(stx[j],low[s]);
    }
    if(pre==-1&&son==1)cut[s]=0;        //若根节点只有一个子节点，则不是割点
}

void setbcc(){
    memset(cut,0,sizeof(cut));
    memset(stx,0,sizeof(stx));
    memset(bcc,0,sizeof(bcc));
    t=bcccnt=0;
    for(int i=1;i<=n;++i)if(!stx[i])dfs(i,-1);
}

void work()
{
    int m;
    init();
    rd(n),rd(m);
    int u,v;
    for(int i=1;i<=n;i++)
        fa[i]=i; 
    for(int i=1;i<=m;i++){
        rd(u),rd(v);
        merge(u,v);
        add(u,v);
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(find(i));
    }
    int ji=s.size();
    setbcc();
    for(int i=1;i<=n;i++){
        if(!cut[i]&&head[i]!=-1){
            printf("%lld ",ji);
            continue;
        }
        set<int> cnt;
        for(int j=head[i];j!=-1;j=nxt[j]){
            cnt.insert(bcc[point[j]]);
        }
        printf("%lld ",(ll)cnt.size()+ji-1);
    }
    printf("\n");
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}
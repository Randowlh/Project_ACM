#include<bits/stdc++.h>
using namespace std;
#define int long long
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
struct node{
    int to,next;
}edge[110000],edge2[110000];
int ecnt=0,ecnt2=0,head[11000],head2[11000];
int dp[11000];
int belong[11000],low[11000],dfn[11000],flag[11000];
int cnt=0,cnt2=0;
int vl[11000],vl2[11000];
int du[11000];
int s[11000];
int tail;
void tarjan(int x){
    dfn[x]=low[x]=++cnt;
    flag[x]=1;
    s[tail++]=x;
    for(int i=head[x];i;i=edge[i].next){
        if(!dfn[edge[i].to]){
            tarjan(edge[i].to);
            low[x]=min(low[x],low[edge[i].to]);
        }else if(flag[edge[i].to])
            low[x]=min(low[x],dfn[edge[i].to]);
    }
    if(dfn[x]==low[x]){
        belong[x]=++cnt2;
        flag[x]=0;
        vl2[cnt2]=vl[x];
        while(s[tail]!=x){
            belong[s[tail]]=cnt2;
            vl2[cnt2]+=vl[s[tail]];
            flag[s[tail]]=0;
            tail--;
        }
        tail--;
    }
}
void add(int u,int v){
    edge[ecnt++].next=head[u];
    edge[ecnt].to=v;
    head[u]=ecnt;
}
void add2(int u,int v){
    edge2[ecnt2++].next=head2[u];
    edge2[ecnt2].to=v;
    head2[u]=ecnt2;
}
int dfs(int x){
    if(dp[x]!=-1)
        return dp[x];
    int ans=0;
    for(int j=head2[x];j;j=edge2[j].next)
        ans=max(ans,dfs(edge2[j].to));
    ans+=vl2[x];
    return dp[x]=ans;
}
signed main(){
    freopen("in.txt", "r", stdin);
    int n,m;
    rd(n),rd(m);
    cnt=cnt2=ecnt2=ecnt=0;
    for(int i=1;i<=n;i++)
        rd(vl[i]);
    for(int i=0;i<=n;i++)
        head[i]=0,head2[i]=0;
    int u,v,w;
    for(int i=0;i<m;i++){
        rd(u),rd(v),add(u,v);
        cout<<u<<' '<<v<<endl;
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);      
    for(int i=1;i<=n;i++)
        cout<<"belong"<<i<<' '<<belong[i]<<endl;
    memset(dp,-1, sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=edge[j].next)
            if(belong[i]^belong[edge[j].to])
                add2(belong[i],belong[edge[j].to]),du[belong[edge[j].to]]++;
    int ans=0;
    for(int i=1;i<=cnt2;i++){
        if(!du[i])
            ans=max(ans,dfs(i));
    }
    printf("%lld\n",ans);
}
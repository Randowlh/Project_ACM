#include<bits/stdc++.h>
  
using namespace std;

#define rep(a,b,c) for(int a=(b);a<(c);++a)
#define dep(a,b,c) for(int a=(b);a>=(c);--a)
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int MAXN = 201000;//点数的最大值
const int MAXM = 1200010;//边数的最大值

int t,n,x[100007],y[100007];

struct Edge{
    int to,next,cap,flow;
}edge[MAXM];//注意是 MAXM

int tol;
int head[MAXN];

void init(){
    tol = 2;
    memset(head,-1,2*n*sizeof(int));
}
void add_edge(int u,int v,int w,int rw = 0){
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}
int Q[MAXN];
int dep[MAXN],cur[MAXN],sta[MAXN];
bool bfs(int s,int t,int n){
    int front = 0,tail = 0;
    memset(dep,-1,sizeof(dep[0])*(n+1));
    dep[s] = 0;
    Q[tail++] = s;
    while(front < tail){
        int u = Q[front++];
        for(int i = head[u]; i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dep[v] == -1){
                dep[v] = dep[u] + 1;
                if(v == t)return true;
                Q[tail++] = v;
            }
        }
    }
    return false;
}
int dinic(int s,int t,int n){
    int maxflow = 0;
    while(bfs(s,t,n)){
        for(int i = 0;i < n;i++)cur[i] = head[i];
        int u = s, tail = 0;
        while(cur[s] != -1){
            if(u == t){
                int tp = inf;
                for(int i = tail-1;i >= 0;i--)
                tp = min(tp,edge[sta[i]].cap-edge[sta[i]].flow);
                maxflow += tp;
                for(int i = tail-1;i >= 0;i--){
                    edge[sta[i]].flow += tp;
                    edge[sta[i]^1].flow -= tp;
                    if(edge[sta[i]].cap-edge[sta[i]].flow == 0)
                    tail = i;
                }
                u = edge[sta[tail]^1].to;
            }   
            else if(cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow && dep[u] + 1 == dep[edge[cur[u]].to]){
                sta[tail++] = cur[u];
                u = edge[cur[u]].to;
            }
            else{
                while(u != s && cur[u] == -1)
                u = edge[sta[--tail]^1].to;
                cur[u] = edge[cur[u]].next;
            }
        }
    }
    return maxflow;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        init();
        unordered_map<int,int> M1,M2;
        int cnt1=1,cnt2=1;
        for(int i=0;i<n;++i){
            cin>>x[i]>>y[i];
            int nx=x[i]-y[i],ny=x[i]+y[i];
            if(M1[nx]==0){
                M1[nx]=cnt1;
                cnt1++;

            }
            if(M2[ny]==0){
                M2[ny]=cnt2;
                cnt2++;
            }
        }
        //cout<<cnt1<<' '<<cnt2<<endl;
        for(int i=1;i<cnt1;++i){
            add_edge(0,i,1);
        }
        for(int i=1;i<cnt2;++i){
            add_edge(i+cnt1,cnt1+cnt2,1);
        }
        for(int i=0;i<n;++i){
            add_edge(M1[x[i]-y[i]],M2[x[i]+y[i]]+cnt1,inf);
        }
        cout<<dinic(0,cnt1+cnt2,cnt1+cnt2-2+n)<<endl;
    }
    return 0;
}

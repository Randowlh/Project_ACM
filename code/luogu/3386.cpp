#include <bits/stdc++.h>
using namespace std;
class DC
{
public:
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    int book[1010];
    int cur[1010];
    int depth[1010];
    int n, t, s;
    int cnt = 0;
    vector<Edge> edge;
    vector<int> mp[1010];
    int bfs(int s, int t)
    {
        memset(book, 0, sizeof(book));
        queue<int> q;
        q.push(s);
        book[s] = 1;
        depth[s] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < mp[now].size(); i++)
            {
                Edge &e = edge[mp[now][i]];
                if (!book[e.to] && e.cap > e.flow)
                {
                    depth[e.to] = depth[e.from] + 1;
                    book[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return book[t];
    }
    int dfs(int now, int a)
    {
        if (now == t || a == 0)
            return a;
        int flow = 0;
        int f;
        for (int &i = cur[now]; i < mp[now].size(); i++)
        {
            Edge &e = edge[mp[now][i]];
            if (depth[now] + 1 == depth[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                flow += f;
                edge[mp[now][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int Dinic()
    {
        int ans = 0;
        while (bfs(s, t))
        {
            for(int i=0;i<=n;i++)
            cur[i]=0;
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
    void init(int nn,int ss,int tt){
        n=nn,s=ss,t=tt;
        for(int i=0;i<=n;i++)
        mp[i].clear();
        edge.clear();
    }
} fl;
int main(){
    int n,m,e;
    cin>>n>>m>>e;   
    fl.init(n+m+10,0,n+m+5);
    for(int i=1;i<=n;i++){
        fl.add_edge(0,i,1);
    }
    for(int i=n+1;i<=n+m;i++)
    {
        fl.add_edge(i,n+m+5,1);
    }
    int w,v;
    for(int i=0;i<e;i++){
        cin>>w>>v;
        fl.add_edge(w,v+n,1);
    }
    cout<<fl.Dinic()<<endl;
}
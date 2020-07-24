const int maxn = 110000;
struct node
{
    int v, nxt;
    node(int a, int b) : v(a), nxt(b){}
} g[maxn << 1];
int head[maxn], tot;
void add_edge(int u,int v){
    g[++tot] = node(v, head[u]);
    head[u] = tot;
}
void dfs(int u){
    for (int i = head[u]; i; i = g[i].nxt){ 
        
    }
}
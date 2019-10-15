namespace CF{
	#define ad(x) ((x - 1 ^ 1) + 1)
	#define INF 0x7f7f7f7f
	struct edge{
		int u, v, c, f;
		edge (int u0 = 0, int v0 = 0, int c0 = 0, int f0 = 0): u(u0), v(v0), c(c0), f(f0) {}
	}e[M];

	int V, E, si = 1, ti = 2, flow, cost;
	int first[N], next[M];
	int dep[N], cur[N], que[M << 1];
	char in_que[N], used[N];

	inline void addedge(int u, int v, int c, int f){
		e[++E] = edge(u, v, c, f); next[E] = first[u]; first[u] = E;
		e[++E] = edge(v, u, -c); next[E] = first[v]; first[v] = E;
	}

	bool bfs(){
		int h = M, t = h + 1, i, x, y;
		memset(dep, 127, sizeof dep);
		que[h] = ti; dep[ti] = 0; in_que[ti] = 1;
		for(; h < t; ){
			x = que[h++]; in_que[x] = 0;
			for(i = first[x]; i; i = next[i])
				if(dep[y = e[i].v] > dep[x] - e[i].c && e[ad(i)].f){
					dep[y] = dep[x] - e[i].c;
					if(!in_que[y]){
						in_que[y] = 1;
						(dep[y] >= dep[que[h]] ? que[t++] : que[--h]) = y;
					}
				}
		}
		return dep[si] < INF;
	}

	int dfs(int x, int lim){
		int a, c, f = 0;
		if(x == ti || !lim) return lim;
		used[x] = 1;
		for(int &i = cur[x]; i; i = next[i])
			if(dep[e[i].v] == dep[x] - e[i].c && e[i].f && !used[e[i].v]){
				a = min(lim - f, e[i].f);
				c = dfs(e[i].v, a);
				e[i].f -= c; e[ad(i)].f += c;
				if((f += c) == lim) return f;
			}
		return f;
	}

	void Dinic(){
		int f;
		for(cost = flow = 0; bfs(); ){
			memcpy(cur, first, sizeof cur);
			memset(used, 0, sizeof used);
			flow += f = dfs(si, INF);
			cost += dep[si] * f;
		}
	}
}
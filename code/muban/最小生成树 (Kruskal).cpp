struct edge{
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0): u(u0), v(v0), w(w0) {}
	bool operator < (const edge &b) const {return w < b.w;}
};

void Kruskal(){
	uf.resize(V);
	sort(e + 1, e + (E + 1));
	for(i = 1; i <= E; i++)
		if(!uf.test(e[i].u, e[i].v, true)){
			// e is an edge of minimum spanning tree
			if(++Es >= V - 1) return;
		}
}
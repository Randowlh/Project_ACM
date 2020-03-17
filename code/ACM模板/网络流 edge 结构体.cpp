struct edge{
	int u, v, f; // f is remaining flow
	edge(int u0 = 0, int v0 = 0, int f0 = 0): u(u0), v(v0), f(f0) {}
};
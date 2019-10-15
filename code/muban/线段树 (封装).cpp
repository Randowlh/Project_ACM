struct ST{
	#define segc int M = L + R - 1 >> 1, lc = id << 1, rc = lc | 1
	int sz;
	struct node {int v, f; bool zero;} *x;
	ST (): sz(0) {x = NULL;}
	~ST () {if(x) delete [] (x);}
	void resize(int size) {sz = size; int sz0 = sz << 3; if(x) delete [] (x);
		x = new node[sz0]; memset(x, 0, sz0 * sizeof(node));}

	void add(int h, int v) {add(1, 1, sz, h, v);}
	int range(int l, int r) {return query(1, 1, sz, l, r);}

	void add(int id, int L, int R, int h, int v){
		if(L == R) return void(x[id].v += v);
		segc; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v);
		x[id].v = x[lc].v + x[rc].v;
	}

	int query(int id, int L, int R, int ql, int qr){
		if(ql <= L && R <= qr) return x[id].v;
		segc, s = 0;
		if(ql <= M) s += query(lc, L, M, ql, min(qr, M));
		if(qr > M) s += query(rc, M + 1, R, max(ql, M + 1), qr);
		return s;
	}
};
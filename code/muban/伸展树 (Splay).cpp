#define pa p[nd]
#define root nd[0].c[0]
struct node {int v, sz, p, c[2]; ll sum;} nd[N];

inline int dir(int x) {return x == x[nd].pa.c[1];}

inline void update(int x){
	x[nd].sz = x[nd].c[0][nd].sz + x[nd].c[1][nd].sz + 1;
	x[nd].sum = x[nd].c[0][nd].sum + x[nd].c[1][nd].sum + x[nd].v;
}

void rotate(int x){
	int y = x[nd].p, d = !dir(x);
	nd[y[nd].c[!d] = x[nd].c[d]].p = y;
	x[nd].p = y[nd].p;
	y[nd].pa.c[dir(y)] = x;
	nd[x[nd].c[d] = y].p = x;
	update(y);
}

void splay(int x, int g = 0){
	for(; x[nd].p != g; rotate(x))
		if(x[nd].pa.p != g) rotate(dir(x) ^ dir(x[nd].p) ? x : x[nd].p);
	update(x);
}

void insert(int x){
	int y = 0, d = 0;
	if(root) for(y = root; d = (val[x] < y[nd].v), y[nd].c[d]; y = y[nd].c[d]);
	y[nd].c[d] = x;
	nd[x].v = nd[x].sum = val[x]; nd[x].sz = 1; nd[x].p = y; nd[x].c[0] = nd[x].c[1] = 0;
	splay(x);
}

void erase(int x){
	if(x[nd].p) splay(x);
	if(!(x[nd].c[0] && x[nd].c[1])){
		int d = (x[nd].c[1] > 0);
		x[nd].c[d][nd].p = 0;
		root = x[nd].c[d];
	}else{
		int y;
		for(y = x[nd].c[1]; y[nd].c[0]; y = y[nd].c[0]);
		splay(y, x);
		nd[y[nd].c[0] = x[nd].c[0]].p = y;
		y[nd].p = 0; root = y;
		update(y);
	}
}

int kth(int x, int v){
	if(x[nd].sz < v) return -1;
	for(int j; ; ){
		j = x[nd].c[0][nd].sz;
		if(v == j + 1) return x;
		x = x[nd].c[v > j]; v > j ? (v -= j + 1) : v;
	}
}
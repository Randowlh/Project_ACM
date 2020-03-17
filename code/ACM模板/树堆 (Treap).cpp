struct random_t{
	ull seed;
	static const ull multiplier = 0x5deece66dll;;
	static const ull addend = 0xbll;
	static const ull mask = 0xffffffffffffll;

	random_t () {char *x = new char; seed = (ull)x; delete x;}

	unsigned int next(){
		seed = (seed * multiplier + addend) & mask;
		return seed >> 16;
	}

	unsigned int next(unsigned int n){
		return n * (ull)next() >> 32;
	}
}rnd;

#define pa p[nd]
#define C(x) c[x][nd]
#define root nd[0].c[0]

struct node {int v, sz, pt; int c[2], p; unsigned priority;} nd[N];
int cnt = 0;

inline int dir(int x) {return x == nd[x].pa.c[1];}

inline void update(int x){
	nd[x].sz = nd[x].C(0).sz + nd[x].C(1).sz + nd[x].pt;
}

void rotate(int x){
	int y = nd[x].p, d = !dir(x);
	nd[nd[y].c[!d] = nd[x].c[d]].p = y;
	nd[x].p = nd[y].p;
	nd[y].pa.c[dir(y)] = x;
	nd[nd[x].c[d] = y].p = x;
	update(y); update(x);
}

void push_up(int x) {for(; x; x = nd[x].p) update(x);}

void rotation(int x) {for(; nd[x].p && nd[x].priority < nd[x].pa.priority; ) rotate(x);}

void insert(int v){
	int x = 0, y = 0, d = 0;
	if(root) for(y = root; nd[y].v != v && nd[y].c[d = v > nd[y].v]; y = nd[y].c[d]);
	if(nd[y].v == v) {++nd[y].pt; push_up(y); return;}
	nd[y].c[d] = x = ++cnt;
	nd[x].v = v; nd[x].sz = nd[x].pt = 1; nd[x].p = y; nd[x].c[0] = nd[x].c[1] = 0;
	nd[x].priority = rnd.next(); push_up(y);
	rotation(x);
}

void erase(int v){
	int x = 0, y = 0, d = 0;
	if(root) for(x = root; nd[x].v != v && nd[x].c[d = v > nd[x].v]; x = nd[x].c[d]);
	if(nd[x].v != v) return;
	if(nd[x].pt > 1) {--nd[x].pt; push_up(x); return;}
	for(; nd[x].c[0] && nd[x].c[1]; rotate(nd[x].c[d]))
		d = nd[x].C(0).priority > nd[x].C(1).priority;
	d = nd[x].c[1] > 0; y = nd[x].c[d];
	nd[y].p = nd[x].p; nd[x].pa.c[dir(x)] = y; push_up(nd[y].p);
}

int rank(int v){
	int x = 0, d = 0, k = 0;
	if(root) for(x = root; nd[x].v != v && nd[x].c[d = v > nd[x].v]; x = nd[x].c[d])
		if(d) k += nd[x].C(0).sz + nd[x].pt;
	if(nd[x].v != v) return -1;
	return k + nd[x].C(0).sz;
}

int kth(int k){
	int x = root;
	if(nd[x].sz < k) return -1;
	for(int j, z; ; ){
		j = nd[x].C(0).sz; z = nd[x].pt;
		if(j <= k && k < j + z) return x;
		x = nd[x].c[k > j]; k > j ? (k -= j + z) : k;
	}
}

int prev(int v){
	int x = 0, r = -1, d = 0;
	if(root) for(x = root; x; x = nd[x].c[d]) if(d = v > x[nd].v) up(r, nd[x].v); // too little
	return r;
}

int succ(int v){
	int x = 0, r = INT_MAX, d = 0;
	if(root) for(x = root; x; x = nd[x].c[d]) if(!(d = v >= x[nd].v)) down(r, nd[x].v); // too large
	return r;
}
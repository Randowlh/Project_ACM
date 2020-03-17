namespace LCT {
	#define pa p[nd]
	struct node {bool rev; int v, p, c[2];} nd[N];
	inline int dir(int x) {return !nd[x].p ? -1 : x == nd[x].pa.c[0] ? 0 : x == nd[x].pa.c[1] ? 1 : -1;}
	inline void reverse(int x) {x && (std::swap(nd[x].c[0], nd[x].c[1]), nd[x].rev = !nd[x].rev);}
	void push_down(int x) {if (nd[x].rev) reverse(nd[x].c[0]), reverse(nd[x].c[1]), nd[x].rev = false;}
	void pull_down(int x) {if (~dir(x)) pull_down(nd[x].p); push_down(x);}
	inline void update(int x) {const int l = nd[x].c[0], r = nd[x].c[1]; nd[x].v = (l ? nd[l].v : 0) + (r ? nd[r].v : 0);}
	void rotate(int x) {
		int y = nd[x].p, d = !dir(x);
		nd[nd[y].c[!d] = nd[x].c[d]].p = y;
		nd[x].p = nd[y].p;
		if (~dir(y)) nd[y].pa.c[dir(y)] = x;
		nd[nd[x].c[d] = y].p = x;
		update(y);
	}
	void splay(int x) {for (pull_down(x); ~dir(x); rotate(x)) if (~dir(nd[x].p)) rotate(dir(x) ^ dir(nd[x].p) ? x : nd[x].p); update(x);}
	void access(int x) {for (int y = 0; x; y = x, x = nd[x].p) splay(x), nd[x].c[1] = y, update(x);}
	void make_root(int x) {access(x), splay(x), reverse(x);}
	int find_root(int x) {for (access(x), splay(x); push_down(x), nd[x].c[0]; x = nd[x].c[0]); return splay(x), x;}
	int split(int x, int y) {return make_root(x), access(y), splay(y), y;}
	void link(int x, int y) {make_root(x), nd[x].p = y;}
	void cut(int x, int y) {split(x, y), nd[x].p = nd[y].c[0] = 0, update(y);}
	void trylink(int x, int y) {x == y || (split(x, y), ~dir(x)) || (nd[x].p = y);}
	void trycut(int x, int y) {split(x, y), nd[y].c[0] == x && !nd[x].c[1] && (nd[x].p = nd[y].c[0] = 0, update(y), 0);}
}
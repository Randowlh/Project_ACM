#define lowbit(x) (x & -x)

struct BIT{
	int sz, *x;
	BIT (): sz(0) {x = NULL;}
	~BIT () {if(x) delete [] (x);}
	void resize(int size) {sz = size; if(x) delete [] (x); x = new int[sz + 5]; memset(x, 0, sz + 5 << 2);}
	int sum(int h) {int s = 0; if(h <= 0) return s; while(h) {s += x[h]; h -= lowbit(h);} return s;}
	int range(int l, int r) {return sum(r) - sum(l - 1);} 
	void add(int h, int v) {while(h <= sz) {x[h] += v; h += lowbit(h);}}
};
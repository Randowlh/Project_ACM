#define segc int M = L + R - 1 >> 1, lc = id << 1, rc = lc | 1

void add(int id, int L, int R, int h, int v){
	if(L == R) return void(st[id] += v);
	segc; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v);
	x[id].v = x[lc].v + x[rc].v;
}

int range(int id, int L, int R, int ql, int qr){
	if(ql <= L && qr >= R) return st[id];
	segc, s = 0;
	if(ql <= M) s += range(lc, L, M, ql, min(qr, M));
	if(qr > M) s += range(rc, M + 1, R, max(ql, M + 1), qr);
	return s;
}
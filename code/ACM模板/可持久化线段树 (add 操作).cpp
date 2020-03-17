int add(int _id, int L, int R, int h, int v){
	int id = ++cnt; x[id] = x[_id]; x[id].v += v;
	if(L == R) return id;
	int M = L + R - 1 >> 1;
	if(h <= M) x[id].lc = add(x[id].lc, L, M, h, v);
	else x[id].rc = add(x[id].rc, M + 1, R, h, v);
	return id;
}
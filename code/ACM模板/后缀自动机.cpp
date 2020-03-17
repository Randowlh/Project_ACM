#define q d[p][x]
int extend(int x) {
	for (p = np, val[np = ++cnt] = val[p] + 1; p && !q; q = np, p = pa[p]);
	if (!p) pa[np] = 1;
	else if (val[p] + 1 == val[q]) pa[np] = q;
	else {
		int nq = ++cnt;
		val[nq] = val[p] + 1, memcpy(d[nq], d[q], 104);
		pa[nq] = pa[q], pa[np] = pa[q] = nq;
		for (int Q = q; p && q == Q; q = nq, p = pa[p]);
	}
	return f[np] = 1, np;
}
#undef q
int get_fail(int x) {for (; ptr[~val[x]] != *ptr; x = fail[x]); return x;}

int extend(int x) {
	int &q = d[p = get_fail(p)][x];
	if (!q) fail[++cnt] = d[get_fail(fail[p])][x], val[q = cnt] = val[p] + 2;
	return p = q;
}
val[1] = -1, p = 0, *fail = cnt = 1;
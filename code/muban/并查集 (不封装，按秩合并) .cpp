int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

bool test(int x, int y, bool un = false) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	if (un) size[x] > size[y] ? std::swap(x, y) : (void)0, p[x] = y, size[y] += size[x];
	return false;
}
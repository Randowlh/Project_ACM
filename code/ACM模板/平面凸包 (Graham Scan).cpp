int graham(int n, vec2 *p, vec2 *dest) {
	int i; vec2 *ret = dest;
	std::iter_swap(p, std::min_element(p, p + n));
	std::sort(p + 1, p + n, [p] (const vec2 A, const vec2 B) {double r = cross(*p, A, B); return gt(r, 0) || (ge(r, 0) && lt(A.norm2(), B.norm2()));});
	for (i = 0; i < 2 && i < n; ++i) *ret++ = p[i];
	for (; i < n; *ret++ = p[i++])
		for (; ret != dest + 1 && ge(cross(ret[-2], p[i], ret[-1]), 0); --ret);
	return *ret = *p, ret - dest;
}
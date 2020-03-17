double convDiameter(int n, vec2 *poly) {
	int l = std::min_element(poly, poly + n) - poly, r = std::max_element(poly, poly + n) - poly, i = l, j = r;
	double diam = (poly[l] - poly[r]).norm2();
	do {
		(ge(poly[(i + 1) % n] - poly[i] ^ poly[(j + 1) % n] - poly[j], 0) ? ++j : ++i) %= n;
		up(diam, (poly[i] - poly[j]).norm2());
	} while (i != l || j != r);
	return diam;
}
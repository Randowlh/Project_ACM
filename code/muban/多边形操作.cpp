// Relation of 3 points. (2 inside, 1 outside, 0 not collinear)
inline int collinear(const vec2 u, const vec2 v, const vec2 P) {double p = cross(P, u, v); return eq(p, 0) ? 1 + le(dot(P, u, v), 0) : 0;}

// Perimeter of a polygon
double perimeter(int n, vec2 *poly) {
	double ret = (poly[n - 1] - *poly).norm();
	for (int i = 1; i < n; ++i) ret += (poly[i - 1] - poly[i]).norm();
	return ret;
}

// Directed area of a polygon (positive if CCW)
double area(int n, vec2 *poly) {
	double ret = poly[n - 1] ^ *poly;
	for (int i = 1; i < n; ++i) ret += poly[i - 1] ^ poly[i];
	return ret * 0.5;
}

// Point in polygon (2 on boundary, 1 inside, 0 outside)
int contain(int n, vec2 *poly, const vec2 P) {
	int in = 0; vec2 *r = poly + (n - 1), *u, *v;
	for (int i = 0; i < n; r = poly, ++poly, ++i) {
		if (collinear(*r, *poly, P) == 2) return 2;
		gt(r->y, poly->y) ? (u = poly, v = r) : (u = r, v = poly);
		if (ge(P.y, v->y) || lt(P.y, u->y)) continue;
		in ^= gt(cross(P, *u, *v), 0);
	}
	return in;
}
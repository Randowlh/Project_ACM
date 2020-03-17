inline double angle(const vec2 u, const vec2 v) {return atan2(u ^ v, u * v);}

// intersection of circle and line
void intersection(double r2, const vec2 O, const line l, vec2 *ret) {
	double d2 = dis2(O, l); vec2 j = l.normVec();
	if (gt(d2, r2)) {ret[0] = ret[1] = vec2(INFINITY, INFINITY); return;}
	if (ge(d2, r2)) {ret[0] = ret[1] = projection(O, l); return;}
	if (le(d2, 0)) {
		j = j * sqrt(r2 / j.norm2());
		ret[0] = O + j.trans(0, -1, 1, 0);
		ret[1] = O + j.trans(0, 1, -1, 0);
	} else {
		double T = copysign(sqrt((r2 - d2) / d2), l(O)); j = j * (-l(O) / j.norm2());
		ret[0] = O + j.trans(1, T, -T, 1);
		ret[1] = O + j.trans(1, -T, T, 1);
	}
}

// area of intersection(x^2 + y^2 = r^2, triangle OBC)
double interArea(double r2, const vec2 B, const vec2 C) {
	if (eq(B ^ C, 0)) return 0;
	vec2 is[2]; intersection(r2, vec2(), line(B, C), is);
	if (!std::isfinite(is->x)) return 0.5 * r2 * angle(B, C);
	bool b = gt(B.norm2(), r2), c = gt(C.norm2(), r2);
	if (b && c) return 0.5 * (lt(dot(*is, B, C), 0) ? r2 * (angle(B, *is) + angle(is[1], C)) + (is[0] ^ is[1]) : r2 * angle(B, C));
	else if (b) return 0.5 * (r2 * angle(B, *is) + (*is ^ C));
	else if (c) return 0.5 * ((B ^ is[1]) + r2 * angle(is[1], C));
	else return 0.5 * (B ^ C);
}
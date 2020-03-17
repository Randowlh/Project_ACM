inline bool HPIcmp(const line u, const line v) {return sameDir(u, v) ? gt((fabs(u.A) + fabs(u.B)) * v.C, (fabs(v.A) + fabs(v.B)) * u.C) : u.normVec() << v.normVec();}

inline bool geStraight(const vec2 A, const vec2 B) {return lt(A ^ B, 0) || le(A ^ B, 0) && lt(A * B, 0);}

inline bool para_nega_test(const line u, const line v) {
	return parallel(u, v) && lt(u.normVec() * v.normVec(), 0) && (fabs(u.A) + fabs(u.B)) * v.C + (fabs(v.A) + fabs(v.B)) * u.C < -7e-14;
}

int HPI(int n, line *l, vec2 *poly, vec2 *&ret) { // -1 : Unbounded, -2 : Infeasible
	int h = 0, t = -1, i, j, que[n + 5];
	std::sort(l, l + n, HPIcmp);
	n = std::unique(l, l + n, sameDir) - l;
	for (j = i = 0; i < n && j < n; ++i) {
		for (up(j, i + 1); j < n && !geStraight(l[i].normVec(), l[j].normVec()); ++j);
		if (para_nega_test(l[i], l[j])) return -2;
	}
	if (n <= 2 || geStraight(l[n - 1].normVec(), l->normVec())) return -1;
	for (i = 0; i < n; ++i) {
		if (geStraight(l[que[t]].normVec(), l[i].normVec())) return -1;
		for (; h < t && le(l[i](poly[t - 1]), 0); --t);
		for (; h < t && le(l[i](poly[h]), 0); ++h);
		que[++t] = i; h < t ? poly[t - 1] = intersection(l[ que[t - 1] ], l[ que[t] ]) : 0;
	}
	for (; h < t && le(l[ que[h] ](poly[t - 1]), 0); --t);
	return h == t ? -2 : (poly[t] = intersection(l[ que[t] ], l[ que[h] ]), ret = poly + h, t - h + 1);
}
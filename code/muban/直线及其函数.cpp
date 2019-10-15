struct line {
	double A, B, C; // Ax + By + C = 0, > 0 if it represents halfplane.
	line (double A0 = 0.0, double B0 = 0.0, double C0 = 0.0) : A(A0), B(B0), C(C0) {}
	line (const vec2 &u, const vec2 &v) : A(u.y - v.y), B(v.x - u.x), C(u ^ v) {} // left > 0
	inline vec2 normVec() const {return vec2(A, B);}
	inline double norm2() const {return A * A + B * B;}
	inline double operator () (const vec2 &P) const {return A * P.x + B * P.y + C;}
};

inline vec2 intersection(const line u, const line v) {
	double Det = 1.0 / (u.A * v.B - u.B * v.A);
	return vec2(u.B * v.C - u.C * v.B, u.C * v.A - u.A * v.C) * Det;
}

inline bool parallel(const line u, const line v) {double p = u.normVec() ^ v.normVec(); return eq(p, 0);}

inline bool perpendicular(const line u, const line v) {double p = u.normVec() * v.normVec(); return eq(p, 0);}

inline bool sameDir(const line u, const line v) {return parallel(u, v) && gt(u.normVec() * v.normVec(), 0);}

inline line bisector(const vec2 u, const vec2 v) {return line(v.x - u.x, v.y - u.y, 0.5 * (u.norm2() - v.norm2()));}

inline double dis2(const vec2 P, const line l) {return l(P) * l(P) / l.norm2();}

inline vec2 projection(const vec2 P, const line l) {return P - l.normVec() * (l(P) / l.norm2());}

inline vec2 symmetry(const vec2 P, const line l) {return P - l.normVec() * (2 * l(P) / l.norm2());}
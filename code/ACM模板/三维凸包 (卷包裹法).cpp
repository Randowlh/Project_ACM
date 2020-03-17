namespace CH3D {
	typedef std::pair <int, int> pr;
	typedef std::set <pr> set;

	struct triangle {vec3 A, B, C;} tr[N];

	vec3 p[N], q[N], r[N];
	set E;
	int n, cnt;

	inline vec3 randvec3() {return vec3((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);}

	void wrap(int u, int v) {
		if (E.find({u, v}) == E.end()) {
			int i, w = -1;
			for (i = 0; i < n; ++i)
				if (i != u && i != v && (!~w || ge(volume(q[w], q[u], q[v], q[i]), 0))) w = i;
			if (~w) {
				tr[cnt++] = (triangle){p[u], p[v], p[w]};
				E.emplace(u, v); E.emplace(v, w); E.emplace(w, u);
				wrap(w, v); wrap(u, w);
			}
		}
	}

	void main(int _n, vec3 *_p) {
		int i;
		n = _n; cnt = 0; E.clear();
		memcpy(p, _p, n * sizeof(vec3));
		std::iter_swap(p, std::min_element(p, p + n));
		for (i = 0; i < n; ++i) q[i] = p[i] + randvec3() * 1e-6;
		for (i = 2; i < n; ++i)
			if (ge(cross(q[0], q[i], q[1]).z, 0)) std::swap(p[1], p[i]), std::swap(q[1], q[i]);
		wrap(0, 1);
	}
}
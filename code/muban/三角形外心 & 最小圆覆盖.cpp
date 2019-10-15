inline vec2 circumCenter(const vec2 A, const vec2 B, const vec2 C) {
	vec2 a = B - A, b = C - A, AO;
	double det = 0.5 / (a ^ b), na = a.norm2(), nb = b.norm2();
	AO = vec2((na * b.y - nb * a.y) * det, (nb * a.x - na * b.x) * det);
	return A + AO;
}

double minCircleCover(int n, vec2 *p, vec2 *ret = NULL) {
	int i, j, k; double r2 = 0.0;
	std::random_shuffle(p + 1, p + (n + 1));
	vec2 C = p[1];
	for (i = 2; i <= n; ++i)
		if (gt((p[i] - C).norm2(), r2))
			for (C = p[i], r2 = 0, j = 1; j < i; ++j)
				if (gt((p[j] - C).norm2(), r2))
					for (C = (p[i] + p[j]) * 0.5, r2 = (p[j] - C).norm2(), k = 1; k < j; ++k)
						if (gt((p[k] - C).norm2(), r2))
							C = circumCenter(p[i], p[j], p[k]), r2 = (p[k] - C).norm2();
	return ret ? *ret = C : 0, r2;
}
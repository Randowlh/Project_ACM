// 'Fast Number Theory Transform' is in memos/12.html.
namespace Poly {
	typedef std::complex <double> C;

	const int N = 530000;
	int l, n, rev[N];
	C x[N], y[N], B1[N], B2[N], B3[N];

	void FFT_init(int len) {
		if (l == len) return; n = 1 << (l = len);
		int i; double angle = M_PI;
		for (i = l - 1; i >= 0; angle *= .5, --i) x[1 << i] = C(cos(angle), sin(angle));
		for (i = 3; i < n; ++i) if (i & (i - 1)) x[i] = x[i & -i] * x[i ^ (i & -i)];
		*x = C(1.), *rev = 0;
		for (i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DFT(C *d, C *t) {
		int i, len = 1, delta = n; C *j, *k, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = y[k - j] * k[len], k[len] = *k - R, *k += R;
			len <<= 1;
		}
	}

	void Mul(int degA, int degB, double *a, double *b, double *c) {
		if (!(degA || degB)) {*c = *a * *b; return;}
		FFT_init(lg2(degA + degB) + 1);
		int i; double iv = 1.0 / n;
		for (i = 0; i <= degA; ++i) B1[i] = C(a[i]); std::fill(B1 + i, B1 + n, C());
		for (i = 0; i <= degB; ++i) B2[i] = C(b[i]); std::fill(B2 + i, B2 + n, C());
		DFT(B1, B3), DFT(B2, B1);
		for (i = 0; i < n; ++i) B1[i] *= B3[i];
		DFT(B1, B3), std::reverse(B3 + 1, B3 + n);
		for (i = 0; i <= degA + degB; ++i) c[i] = B3[i].real() * iv;
	}
}
double Simpson(double L, double M, double R, double fL, double fM, double fR, double eps) {
	double LM = (L + M) * 0.5, fLM = f(LM), MR = (M + R) * 0.5, fMR = f(MR);
	double A = (fL + fM * 4.0 + fR) * (R - L) * sixth,
		   AL = (fL + fLM * 4.0 + fM) * (M - L) * sixth,
		   AR = (fM + fMR * 4.0 + fR) * (R - M) * sixth;
	if (fabs(AL + AR - A) < eps) return (2.0 * (AL + AR) + A) * third;
	return Simpson(L, LM, M, fL, fLM, fM, eps * 0.6) + Simpson(M, MR, R, fM, fMR, fR, eps * 0.6);
}
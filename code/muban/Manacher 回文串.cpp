void Manacher() {
	int n = 2, i, Max = 0, M = 0;
	t[0] = 2, t[1] = 1;
	for (i = 0; i < S; ++i) t[n++] = s[i], t[n++] = 1; t[n++] = 3;
	for (i = 0; i < n; ++i){
		f[i] = (i < Max ? std::min(f[M * 2 - i], Max - i) : 1);
		for(; t[i + f[i]] == t[i - f[i]]; ++f[i]);
		if (i + f[i] > Max) Max = i + f[i], M = i;
	}
}
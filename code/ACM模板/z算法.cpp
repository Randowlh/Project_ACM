void Z() {
	int i, Max = 0, M = 0;
	for (i = 1; i < n; ++i) {
		z[i] = (i < Max ? std::min(z[i - M], Max - i) : 0);
		for (; s[z[i]] == s[i + z[i]]; ++z[i]);
		if (i + z[i] > Max) Max = i + z[i], M = i; 
	}
}
// pretreatment (border) 
for(i = 1; i < s_n; ){
	while(j >= 0 && s[j] != s[i]) j = f[j];
	f[++i] = ++j;
}

// KMP
for(i = 0; i < m_n; i++){
	while(j >= 0 && s[j] != m[i]) j = f[j];
	if(++j == s_n) printf("%d ", i - s_n + 2);
}
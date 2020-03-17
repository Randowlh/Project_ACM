// definitions
int n, i, j, p, m;
char s[MAX];
int sa[MAX], r1[MAX], r2[MAX], wv[MAX], wt[MAX];
int Ht[MAX];

// s is the original string, n is the length of s
x = r1; y = r2; m = 27; // the size of char-set + 1
for(i = 0; i < n; i++) {sa[i] = i; x[i] = s[i] - '`';}
x[n] = 0;
sort(sa, sa + n, cmp);
for(j = 1; j < n; j <<= 1, m = ++p){
	p = 0;
	for(i = n - j; i < n; i++) y[p++] = i;
	for(i = 0; i < n; i++)
		if(sa[i] >= j)
			y[p++] = sa[i] - j;
	memset(wt, 0, m << 2);
	for(i = 0; i < n; i++) {wv[i] = x[y[i]]; ++wt[wv[i]];}
	for(i = 1; i < m; i++) wt[i] += wt[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wt[wv[i]]] = y[i];
	swap(x, y);
	x[sa[0]] = p = 1;
	for(i = 1; i < n; i++)
		x[sa[i]] = cmp2(y, sa[i - 1], sa[i], j) ? p : ++p;
	x[n] = 0;
}
// now the sa[] is the suffix array, number from 0. (0 ~ n-1)
// and the x[] is the ranking array, number from 1. (1 ~ n)
Ht[0] = p = 0;
for(i = 0; i < n; i++){
	p ? --p : 0;
	if(x[i] == 1) continue;
	for(j = sa[x[i] - 2]; s[i + p] == s[j + p]; p++);	
	Ht[x[i] - 1] = p;
}
// now Ht[i] is the longest common prefix of sa[i-1] and sa[i]
// the first line of extend(x) will be:
for(p = np, val[np = ++cnt] = val[p] + 1, key[np] = Key; p && !q; q = np, p = pa[p]);

// and then
void child_init(){
	int i, j, pos;
	for(used[1] = 1, i = 2; i <= cnt; i++)
		if(~key[i])
			for(pos = n, j = i; !used[j]; j = pa[j]){
				pos += val[pa[j]] - val[j];
				child[pa[j]][s[pos] - 'a'] = j;
				used[j] = 1;
			}
}

void dfs(int x){
	if(~key[x]) sa[sat++] = key[x];
	for(int i = 0; i < 26; i++)
		if(child[x][i])
			dfs(child[x][i]);
}

// and ranking array [0..n-1]
for(i = 0; i < n; i++) rk[sa[i]] = i;

// and lcps
for(i = 0; i < n; i++){
	p ? --p : 0;
	if(!rk[i]) continue;
	for(j = sa[rk[i] - 1]; s[i + p] == s[j + p]; ++p);
	ht[rk[i] - 1] = p;
}
// ht[i] is the lcp of sa[i] and sa[i+1]
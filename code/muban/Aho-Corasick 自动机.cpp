void build(){
	int h, ta = 1, i, t, id;
	que[0] = 1;
	f[1] = 0;
	for(h = 0; h < ta; ++h)
		for(i = que[h], id = 0; id < 26; ++id){ // 26 is the size of char-set
			t = (f[i] ? d[f[i]][id] : 1); // 1 or 0 depend on the root of trie
			int &u = d[i][id];
			if(!u) {u = t; continue;}
			f[u] = t; val[u] |= val[t]; que[ta++] = u;
			la[u] = (v[t] ? t : la[t]);
		}
}
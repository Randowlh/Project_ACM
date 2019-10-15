// implementation 1
void dfs(int x){
	int i, y;
	// do something
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != p[x]){
			p[y] = x;
			// do something
			dfs(y);
			// do something
		}
	// do something
}

// implementation 2
void dfs(int x, int px){
	int i, y;
	// do something
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != px){
			// do something
			dfs(y, x);
			// do something
		}
	// do something
}
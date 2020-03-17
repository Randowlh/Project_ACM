struct UFind{
	int sz, *p;
	UFind (): sz(0) {p = NULL;}
	~UFind () {if(p) delete [] (p);}
	void resize(int size){
		if(p) delete [] (p); p = new int[(sz = size) + 1];
		for(int i = 0; i <= sz; i++) p[i] = i;
	}
	int ancestor(int x) {return x == p[x] ? x : p[x] = ancestor(p[x]);}
	bool test(int x, int y, bool un = false){
		if((x = ancestor(x)) == (y = ancestor(y))) return true;
		if(un) p[x] = y; return false;
	}
};
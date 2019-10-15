#define lowbit(x) (x & -x)

int sum(int h){
	int s = 0;
	while(h){
		s += a[h];
		h -= lowbit(h);
	}
	return s;
}

int add(int h, int v){
	while(h <= n){
		a[h] += v;
		h += lowbit(h);
	}
	return v;
}
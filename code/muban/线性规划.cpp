const double eps = 1e-8;

int id[N + E];

double m[E][N], b[E], *c = m[0], ans[N + E];

void pivot(int toFree, int toBasic); // basic(1,m) -> free, free(1,n) -> basic

void pivot(int r, int c){
	int i, j; double coe = 1.0 / m[r][c];
	swap(id[n + r], id[c]);
	m[r][c] = 1.0;
	for(j = 1; j <= n; ++j)
		m[r][j] *= coe;
	b[r] *= coe;
	for(i = 0; i <= e; ++i){
		if(i == r) continue;
		coe = m[i][c]; m[i][c] = 0.0;
		for(j = 1; j <= n; ++j)
			m[i][j] -= coe * m[r][j];
		b[i] -= coe * b[r];
	}
}

bool simplex(){
	int i, j, basic, free; double G;
	for(; ; ){
		basic = free = 0; G = INFINITY;
		for(i = 1; i <= n; ++i) // free (nonbasic) variable
			if(c[i] > c[free]) free = i;
		if(!free) return true;
		for(j = 1; j <= e; ++j) // basic variable
			if(m[j][free] > eps && b[j] < G * m[j][free]){
				G = b[j] / m[j][free]; basic = j;
			}
		if(!basic) return puts("Unbounded"), false;
		pivot(basic, free);
	}
}

// initialize :
for(j = 1; j <= n + e; ++j) id[j] = j;
c[0] = eps;

// output:
if(simplex()){
	printf("%.8lg\n", -*b);
	for(i = 1; i <= e; ++i) ans[id[n + i]] = b[i];
	for(j = 1; j <= n; ++j) printf("%.8lg%c", ans[j], j == n ? 10 : 32);
}
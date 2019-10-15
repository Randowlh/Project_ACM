// Gauss elimination with type 'double'
struct LnEqn{
	int sz;
	double **m, *b;
	LnEqn (): sz(0) {m = NULL; b = NULL;}
	void resize(int size){
		sz = size; m = new double *[sz];
		for(int i = 0; i < sz; i++){
			m[i] = new double[sz];
			memset(m[i], 0, sz << 3);
		}
		b = new double[sz];
		memset(b, 0, sz << 3);
	}
	~LnEqn (){
		if(m) {for(int i = 0; i < sz; i++) delete [] (m[i]); delete [] (m);}
		if(b) delete [] (b);
	}
	bool solve(){
		int i, j, k, maxi; double coe;
		for(k = 0; k < sz; k++){
			maxi = k;
			for(i = k + 1; i < sz; i++)
				if(fabs(m[i][k]) > fabs(m[maxi][k]))
					maxi = i;
			if(fabs(m[maxi][k]) < 1e-8) return false;
			if(maxi != k){
				swap(m[maxi], m[k]);
				swap(b[maxi], b[k]);
			}
			coe = 1.0 / m[k][k];
			for(j = 0; j < sz; j++)
				m[k][j] *= coe;
			m[k][k] = 1.0;
			b[k] *= coe;
			for(i = 0; i < sz; i++){
				if(i == k) continue;
				coe = m[i][k];
				for(j = 0; j < sz; j++)
					m[i][j] -= coe * m[k][j];
				m[i][k] = 0.0;
				b[i] -= coe * b[k];
			}
		}
		return true;
	}
};
namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}
Hash Map [#ed06]:
class hash_map{
public:
	static const int HASH_MAX = 0xffffff, N = 8000000;
	int cnt, first[HASH_MAX + 2], next[N]; data z[N];
	inline int getHash(int key) {return (key ^ key << 3 ^ key >> 2) & HASH_MAX;}

	void clear() {for(; cnt > 0; --cnt) first[z[cnt].hash] = 0;}

	data * find(int key, bool inserted){
		int x = getHash(key), i;
		for(i = first[x]; i; i = next[i]) if(z[i].key == key) return z + i;
		if(!inserted) return NULL;
		z[++cnt] = data(key, 0, x); next[cnt] = first[x]; first[x] = cnt;
		return z + cnt;
	}
};
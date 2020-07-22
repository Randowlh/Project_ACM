#include <bits/stdc++.h>
using namespace std;
#define int long long

#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Flush FastIO::Fflush()

namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	double D[] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.0000000001};
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}

	bool read(long long& x) {
		int n = read(str), bf;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
	
	void write(long long x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			if (x < 0) obuf[opt++] = '-', x = -x;
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(unsigned long long x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(char x) {
		obuf[opt++] = x;
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt = 0;}
};
int mod;
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
struct node{
    int l, r, v;
    int lzc, lzj;
} tree[100100];
int date[100100];
inline void pushup(int pos){
    tree[pos].v = (tree[pos].r + tree[pos].l) % mod;
}
inline void pushdown(int pos){
    if(tree[pos].lzc){
        tree[lson(pos)].lzc = tree[rson(pos)].lzc= tree[pos].lzc;
        tree[lson(pos)].v *= tree[pos].lzc, tree[lson(pos)].v %= mod;
        tree[rson(pos)].v *= tree[pos].lzc, tree[rson(pos)].v %= mod;
        tree[pos].lzc = 0;
    }
    if(tree[pos].lzj){
        //tree[pos].lzc = 0;
        tree[lson(pos)].lzj = tree[lson(pos)].lzj = tree[pos].lzj;
        tree[lson(pos)].v += tree[pos].lzc * (tree[lson(pos)].r - tree[lson(pos)].l + 1) % mod;
        tree[rson(pos)].v += tree[pos].lzc * (tree[rson(pos)].r - tree[rson(pos)].l + 1) % mod;
        tree[pos].lzj = 0;
    }
}
void build(int pos,int l,int r){
    if(l==r){
        tree[pos].l = tree[pos].r = l, tree[pos].lzc = tree[pos].lzj = 0, tree[pos].v = date[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    pushup(pos);
}
void update(int pos,int l,int r,int flag,int v){ 
    if(tree[pos].l==tree[pos].r){
        if(flag)
            tree[pos].v += v, tree[pos].v %= mod;
        else tree[pos].v*=v,tree[pos].v %= mod;
        return;
    }
    pushdown(pos);
    if(tree[pos].l>=l&&tree[pos].r<=r){
        if(flag)
            tree[pos].v += v * (tree[pos].r - tree[pos].l + 1), tree[pos].v %= mod, tree[pos].lzj += v,tree[pos].lzj%=mod;
        else tree[pos].v*=v,tree[pos].v %= mod,tree[pos].lzc += v, tree[pos].lzc %= mod;
        return;
    }
    int mid = (tree[pos].l+ tree[pos].r)>>1;
    if(l<=mid)
        update(lson(pos), l, r, flag, v);
    if(r>=mid+1)
        update(rson(pos), l, r, flag, v);
    pushup(pos);
}
int query(int pos,int l,int r){
    if (tree[pos].l >= l&&tree[pos].r<=r){
        return tree[pos].v;
    }
    int ans = 0;
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if(l<= mid)
        ans += query(lson(pos), l, r);
    if(r<=mid)
        ans += query(rson(pos), l, r);
    ans %= mod;
    return ans;
}
int n, m;
signed main(){
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> mod;
    for (int i = 1; i <= n;i++){
        cin >> date[i];
    }
    build(1, 1, n);
    int opt, a, b,c;
    for (int i = 0; i < m;i++){
        cin >> opt >> a >> b;
        if(opt==1){
            FI(c);
            update(1, a, b, 1, c);
        }else if(opt==2){
            FI(c);
            update(1, a, b, 0, c);
        }else{
            cout << query(1, a, b) << endl;
        }
    }
}
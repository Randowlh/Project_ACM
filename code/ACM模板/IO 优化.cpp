#define ID isdigit(c = *next++)
#define IS isspace(c = *next++)

struct Istream {
	int size; char *next, buf[20030731];
	Istream & init(FILE *f = stdin) {fread(buf, 1, sizeof buf, f); next = buf; return *this;}
	Istream & operator >> (int &x) {
		int c; x = 0;
		for (; !ID; ) if (!~c) return *this;
		for (x = c & 15; ID; x = x * 10 + (c & 15));
		return *this;
	}
	Istream & operator >> (char *x) {
		int c;
		for (; IS; ) if (!~c) return *this;
		for (*x++ = c; !IS; *x++ = c) if (!~c) break;
		return *x = 0, *this;
	}
	char get() {return *next++;}
} cin;

struct Ostream {
	char *next, buf[20030731], _buf[34];
	Ostream () {next = buf;}
	void flush(FILE *f = stdout) {fwrite(buf, 1, next - buf, f); next = buf;}
	Ostream & operator << (int x) {
		if (!x) return put(48), *this;
		int i;
		for (i = 0; x; x /= 10) _buf[++i] = x % 10 | 48;
		for (; i; --i) put(_buf[i]);
		return *this;
	}
	Ostream & operator << (char c) {return put(c), *this;}
	Ostream & operator << (const char *s) {for (char *p = (char*)s; *p; ++p) put(*p); return *this;}
	void put(char c) {*next++ = c;}
} cout;
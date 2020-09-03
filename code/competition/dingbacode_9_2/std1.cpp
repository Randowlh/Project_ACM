#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define dep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
#define CL clear
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 2e6 + 10;
const int inf = 1e9;
const int m1 = 998244353;
const int m2 = 1000001011;
const int K = 233;
inline int rd()
{
	char ch = getchar();
	int p = 0;
	int f = 1;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		p = p * 10 + ch - '0';
		ch = getchar();
	}
	return p * f;
}

int m, h1[N], h2[N], g1[N], g2[N], p1[N], p2[N];

int get11(int l, int r) { return (ll)(h1[r] - (ll)h1[l - 1] * p1[r - l + 1] % m1 + m1) % m1; }
int get12(int l, int r) { return (ll)(h2[r] - (ll)h2[l - 1] * p2[r - l + 1] % m2 + m2) % m2; }

int get21(int l, int r) { return (ll)(g1[r] - (ll)g1[l - 1] * p1[r - l + 1] % m1 + m1) % m1; }
int get22(int l, int r) { return (ll)(g2[r] - (ll)g2[l - 1] * p2[r - l + 1] % m2 + m2) % m2; }

map<pii, bool> mp;

char a[N], b[N];
int nex[N], p[N];

signed main()
{
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);

		p1[0] = p2[0] = 1;
		for (int i = 1; i <= 100; ++i)
		{
			p1[i] = (ll)p1[i - 1] * K % m1;
			p2[i] = (ll)p2[i - 1] * K % m2;
			//cout<<"p1[i]="<<p1[i]<<endl;
		}
		int t = rd();
		while (t--)
		{
			mp.CL();
			int n = rd();
			scanf("%s", a + 1);
			scanf("%s", b + 1);
			rep(i, 1, n) b[i + n] = b[i];

			rep(i, 1, n + 1)
			{
				h1[i] = ((ll)h1[i - 1] * K + a[i]) % m1;
				h2[i] = ((ll)h2[i - 1] * K + a[i]) % m2;
				cout<<"H"<<h1[i]<<endl;
			}

			rep(i, 1, 2 * n)
			{
				g1[i] = ((ll)g1[i - 1] * K + b[i]) % m1;
				g2[i] = ((ll)g2[i - 1] * K + b[i]) % m2;
			}

			bool bk = 0;
			rep(i, 1, n)
			{
				mp[MP(get21(i, i + n - 1), get22(i, i + n - 1))] = 1;
			}
			rep(i, 1, n + 1)
			{
				int g1, g2, x, y;
				x = get11(1, i - 1);
				y = get11(i + 1, n + 1);
				g1 = ((ll)x * p1[n + 1 - i] + y % m1) % m1;
				x = get12(1, i - 1);
				y = get12(i + 1, n + 1);
				g2 = ((ll)x * p2[n + 1 - i] + y % m2) % m2;
				if (mp.find(MP(g1, g2)) != mp.end())
					bk = 1;
			}
			if (bk)
				puts("YES");
			else
				puts("NO");
			rep(i, 1, 2 * n) h1[i] = h2[i] = g1[i] = g2[i] = 0;
		}
	return 0;
}

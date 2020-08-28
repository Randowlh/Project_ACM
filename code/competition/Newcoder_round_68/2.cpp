#include<cstdio>
#include<cctype>
#include<algorithm>
#define pprint(x) ::print(x),putchar(' ')
#define fprint(x) ::print(x),putchar('\n')
using namespace std;
inline long long read()
{
	long long x = 0;int f = 1;
	char ch = getchar();
	for(;!isdigit(ch);ch = getchar())
		if(ch == '-')
			f = -1;
	for(;isdigit(ch);ch = getchar())
		x = x * 10 + (ch ^ 48);
	return x * f;
}
void print(long long x)
{
	if(x < 0)
		x = -x,putchar('-');
	if(x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int N = 200010;

struct tree
{
	int ls,rs;
	int minn;
}t[N << 5];
int cnt,root[N];
void update(int &now,int pre,int l,int r,int pos,int val)
{
	now = ++cnt;
	t[now] = t[pre];
	if(l == r)
	{
		t[now].minn = val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(t[now].ls,t[pre].ls,l,mid,pos,val);
	else
		update(t[now].rs,t[pre].rs,mid + 1,r,pos,val);
	t[now].minn = min(t[t[now].ls].minn,t[t[now].rs].minn);
}
int query(int now,int l,int r,int val)
{
	if(l == r)
		return l;
	int mid = l + r >> 1;
	if(t[t[now].ls].minn < val)
		return query(t[now].ls,l,mid,val);
	else
		return query(t[now].rs,mid + 1,r,val);
}

int n,m;

int main()
{
	n = read(),m = read();
 	for(int i = 1;i <= n;i++)
	{
		int a = read() + 1;
		if(a > n)
		{
			root[i] = root[i - 1];
			continue;
		}
		update(root[i],root[i - 1],1,n + 1,a,i);
	}
	while(m--)
	{
		int l = read(),r = read();
		fprint(query(root[r],1,n + 1,l) - 1);
	}
}
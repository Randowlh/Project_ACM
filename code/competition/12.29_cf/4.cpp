#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	int root = a[0];
	int last = -1;
	vector<int> used(n, 0);
	printf("%d\n", root + 1);
	int cur = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		used[a[i]] = 1;
		while (used[cur])
			cur--;
		if (i == n - 2 || used[a[i + 1]])
		{
			printf("%d %d\n", a[i] + 1, cur + 1);
			used[cur] = 1;
		}
		else
			printf("%d %d\n", a[i + 1] + 1, a[i] + 1);
	}
	return 0;
}
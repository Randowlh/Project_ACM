#include <cstdio>
int main()
{
  int ans = 1;
  int tmp = 0;
  int a = 0;
  int n;
  int b = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a);
    if (a > b)
    {
      tmp++;
    }
    else
    {
      if (ans < tmp)
        ans = tmp;
      tmp = 1;
    }
    b = a;
  }
  printf("%d\n", ans);
  return 0;
}

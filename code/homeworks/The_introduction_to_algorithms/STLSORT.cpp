#include <bits/stdc++.h>
using namespace std;
int date[110000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i]);
    }
    sort(date, date + n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", date[i]);
    }
    printf("\n");
    return 0;
}
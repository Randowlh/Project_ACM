#include <bits/stdc++.h>
using namespace std;
int arr[11000];
int ans[11000];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = j + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
}
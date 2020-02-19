#include <bits/stdc++.h>
using namespace std;
vector<int> date;
void insert_sort()
{
    for (int i = 1; i < date.size(); i++)
    {
        int k = date[i];
        int j = i - 1;
        while (j >= 0 && date[j] > k)
        {
            date[j + 1] = date[j];
            j--;
        }
        date[j + 1] = k;
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        date.push_back(tmp);
    }
    insert_sort();
    for (int i = 0; i < n; i++)
    {
        printf("%d ", date[i]);
    }
    printf("\n");
    return 0;
}
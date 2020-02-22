#include <bits/stdc++.h>
using namespace std;
vector<int> date;
int partition(int left, int right)
{
    int x = date[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++)
    {
        if (date[j] <= x)
        {
            i++;
            swap(date[i], date[j]);
        }
    }
    swap(date[i + 1], date[right]);
    return i + 1;
}
int random_partition(int left, int right)
{
    int i = rand() % (right - left) + left;
    swap(date[i], date[right]);
    return partition(left, right);
}
void quicksort(int left, int right)
{
    if (left < right)
    {
        int mid = random_partition(left, right);
        quicksort(left, mid - 1);
        quicksort(mid + 1, right);
    }
}
int main()
{
    srand(time(0));
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        date.push_back(tmp);
    }
    quicksort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", date[i]);
    }
    printf("\n");
}
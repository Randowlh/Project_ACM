#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int date[101000];
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int left, int right)
{
    int x = date[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++)
    {
        if (date[j] <= x)
        {
            i++;
            swap(&date[i], &date[j]);
        }
    }
    swap(&date[i + 1], &date[right]);
    return i + 1;
}
int random_partition(int left, int right)
{
    int i = rand() % (right - left) + left;
    swap(&date[i], &date[right]);
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
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i]);
    }
    quicksort(0, n - 1);
    int tag = 0;
    scanf("%d", &tag);
    int b = 0;
    int e = n - 1;
    while (b != e)
    {
        int mid = (b + e) >> 1;
        if (date[mid] < tag)
            b = mid + 1;
        else
            e = mid;
    }
    if (date[b] != tag)
        printf("not found.\n");
    else
        printf("No.%d\n", n - b);
}
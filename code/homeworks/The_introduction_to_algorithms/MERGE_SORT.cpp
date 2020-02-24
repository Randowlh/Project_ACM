#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
vector<int> date;
void merge(int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int l2 = right - mid;
    vector<int> l, r;
    for (int i = 1; i <= l1; i++)
        l.push_back(date[left + i - 1]);
    for (int i = 1; i <= l2; i++)
        r.push_back(date[mid + i]);
    l.push_back(inf);
    r.push_back(inf);
    int i = 0;
    int j = 0;
    for (int k = left; k <= right; k++)
    {
        if (l[i] <= r[j])
        {
            date[k] = l[i];
            i++;
        }
        else
        {
            date[k] = r[j];
            j++;
        }
    }
    return;
}
void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) >> 1;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
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
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", date[i]);
    }
    printf("\n");
    return 0;
}
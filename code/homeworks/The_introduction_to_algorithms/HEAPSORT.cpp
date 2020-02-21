#include <bits/stdc++.h>
using namespace std;
int heap[110000];
int heap_size;
int n;
void max_heapify(int i)
{
    int largest = i;
    if (i * 2 <= heap_size && heap[i * 2] > heap[i])
    {
        largest = i * 2;
    }
    if (i * 2 + 1 <= heap_size && heap[i * 2 + 1] > heap[largest])
    {
        largest = i * 2 + 1;
    }
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        max_heapify(largest);
    }
}
void build_max_heap()
{
    heap_size = n;
    for (int i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(i);
    }
}
void heap_sort()
{
    build_max_heap();
    for (int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        heap_size--;
        max_heapify(1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &heap[i]);
    }
    heap_sort();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return 0;
}
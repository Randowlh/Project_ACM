#include <bits/stdc++.h>
using namespace std;
vector<int> date;
vector<int> out;
vector<int> C;
void count_sort()
{
    for (int i = 0; i < C.size(); i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < date.size(); i++)
    {
        C[date[i]]++;
    }
    for (int i = 1; i < C.size(); i++)
    {
        C[i] += C[i - 1];
    }
    out.resize(date.size() + 1);
    for (int i = date.size() - 1; i >= 0; i--)
    {
        out[C[date[i]]] = date[i];
        C[date[i]]--;
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    date.resize(n);
    int mi = 99999999;  //数组最小值
    int ma = -99999999; //数组最大值
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i]);
        mi = min(date[i], mi);
        ma = max(date[i], ma);
    }
    int add = -mi;
    for (int i = 0; i < n; i++)
    {
        date[i] += add;
    }
    C.resize(add + ma + 100);
    count_sort();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", out[i] - add);
    }
    printf("\n");
    return 0;
}
/* 
5
4 2 4 5 1
 */

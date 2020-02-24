#include <bits/stdc++.h>
using namespace std;
vector<int> date;
int get_max()
{
    int ma = date[0];
    for (int i = 1; i < date.size(); i++)
    {
        ma = max(date[i], ma);
    }
    int t = 1;
    while (ma > 0)
    {
        t++;
        ma /= 10;
    }
    return t;
}
void radix_sort()
{
    int d = get_max();
    // cout << d << endl;
    vector<int> tmp[10];
    int chu = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < date.size(); j++)
        {
            tmp[date[j] / chu % 10].push_back(date[j]);
        }
        date.clear();
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < tmp[j].size(); k++)
            {
                date.push_back(tmp[j][k]);
            }
        }
        for (int j = 0; j < 10; j++)
        {
            tmp[j].clear();
        }
        chu *= 10;
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
    radix_sort();
    for (int i = 0; i < n; i++)
    {
        printf("%d ", date[i]);
    }
    printf("\n");
    return 0;
}
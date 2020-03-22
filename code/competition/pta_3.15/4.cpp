#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int n, a, b, q;
vector<int> date;
int find(int x)
{
    if (date[x] == x)
    {
        return x;
    }
    else
    {
        date[x] = find(date[x]);
        return date[x];
    }
}
void merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        date[x] = y;
    }
    return;
}
void work()
{
    cin >> n >> a >> b >> q;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.push_back('?');
    }
    for (int i = 0; i <= n; i++)
    {
        date.push_back(i);
    }
    int t;
    char c;
    for (int i = 0; i < a; i++)
    {
        cin >> t >> c;
        tmp[t - 1] = c;
    }
    int t2;
    vector<int> y, h;
    for (int i = 0; i < b; i++)
    {
        cin >> t >> t2;
        y.push_back(t);
        h.push_back(t2);
    }
    for (int i = 0; i < b - 1; i++)
    {
        if (h[i] != 0 && y[i] < y[i + 1])
        {
            for (int j = y[i]; j < y[i + 1]; j++)
            {
                merge(j - 1, j + h[i] - y[i] - 1);
            }
        }
    }
    if (h[b - 1] != 0)
    {
        for (int j = y[b - 1]; j < n; j++)
        {
            merge(j - 1, j + h[b - 1] - y[b - 1] - 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] != '?')
        {
            tmp[find(i)] = tmp[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (tmp[find(i)] != '?')
        {
            tmp[i] = tmp[find(i)];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t - 1 < n && t - 1 >= 0)
            cout << tmp[t - 1];
        else
            cout << '?';
    }
    cout << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
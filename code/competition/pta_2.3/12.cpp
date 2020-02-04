#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int date[10010];
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

int strcmp(char a[], char b[])
{
    int la = strlen(a);
    int lb = strlen(b);
    for (int i = 0; i < min(la, lb); i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
                return 1;
            else
                return -1;
        }
    }
    if (la == lb)
        return 0;
    if (la > lb)
    {
        return -1;
    }
    if (la < lb)
        return 1;
}
void merge(int a, int b)
{
    int l = find(a);
    int r = find(b);
    if (l == r)
    {
        return;
    }
    else
        date[l] = r;
}
void work()
{
    for (int i = 0; i <= 10000; i++)
    {
        date[i] = i;
    }
    set<int> s;
    vector<int> v;
    int t;
    int n;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> n;
        int ktmp;
        int tmp;
        cin >> ktmp;
        if (s.count(ktmp) == 0)
        {
            s.insert(ktmp);
            v.push_back(ktmp);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> tmp;
            merge(ktmp, tmp);
            if (s.count(tmp) == 0)
            {
                s.insert(tmp);
                v.push_back(tmp);
            }
        }
    }
    cout << v.size() << ' ';
    set<int> tj;
    tj.clear();
    for (int i = 0; i < v.size(); i++)
    {
        tj.insert(find(v[i]));
    }
    cout << tj.size() << endl;
    int u;
    cin >> u;
    for (int i = 0; i < u; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt","r",stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
unordered_map<int, int> M;
unordered_map<int, int> date;
int find(int x)
{
    if (x == date[x])
    {
        return x;
    }
    else
    {
        date[x] = find(date[x]);
        return date[x];
    }
}
void merge(int x, int y)
{
    int l = find(x);
    int r = find(y);
    if (l != r)
    {
        date[l] = r;
    }
    return;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int cnt = 0;
    while (true)
    {
        cnt++;
        int a, b;
        v.clear();
        date.clear();
        M.clear();
        while (cin >> a >> b)
        {
            if (a < 0 || b < 0)
                exit(0);
            if (a == 0 && b == 0)
                break;
            if (date.count(a) == 0)
                date[a] = a;
            date[b] = find(a);
            v.push_back(a);
            v.push_back(b);
            M[b]++;
        }
        sort(v.begin(), v.end());
        int len = unique(v.begin(), v.end()) - v.begin();
        v.resize(len);
        int f = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (M[v[i]] > 1)
            {
                f = 1;
                cout << "Case " << cnt << " is not a tree." << endl;
                break;
            }
        }
        int tmp = find(v[0]);
        if (!f)
            for (int i = 0; i < v.size(); i++)
            {
                if (find(v[i]) != tmp)
                {
                    f = 1;
                    cout << "Case " << cnt << " is not a tree." << endl;
                    break;
                }
            }
        if (!f)
        {
            cout << "Case " << cnt << " is a tree." << endl;
        }
    }
}
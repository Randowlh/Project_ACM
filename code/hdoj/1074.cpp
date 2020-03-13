#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int pr = 0;
    int now = 0;
    int cost = 0;
    inline void init() { pr = -1; }
    inline void mx(int j, int c, int n)
    {
        if (pr == -1)
        {
            pr = j;
            cost = c;
            now = n;
        }
        else
        {
            if (c < cost)
            {
                        }
        }
    }
} dp[70000];
struct nodes
{
    int ddl;
    int c;
    string name;
    bool operator<(nodes a)
    {
        return name < a.name;
    }
};
inline bool check(int a, int b)
{
    a >>= b;
    return a & 1;
}
map<int, string> lk;
void work()
{
    lk.clear();
    int n;
    cin >> n;
    string tmp;
    int a, b;
    vector<nodes> v;
    nodes x;
    for (int i = 0; i < n; i++)
    {
        cin >> x.name >> x.ddl >> x.c;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        lk[i] = v[i].name;
    }
    for (int i = 0; i < 1 << v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (check(i, j))
            {
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
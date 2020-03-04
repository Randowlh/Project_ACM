#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//using namespace std::tr1;
const long long mod = 1e9 + 7;
typedef long long ll;
int real_map[129][129];
vector<int> mp[129], tmp;
static int hash_id = 0;
int ans = 0;
int flag = 0;
vector<int> getIntersection_v_neighbor(vector<int> x, int v)
{
    /* hashmap.clear();
    for(int i=0; i<mp[v].size(); i++)
        hashmap[mp[v][i]]=++hash_id;
    tmp.clear();
    for(int i=0; i<x.size(); i++)
        if (hashmap.count(x[i]))
            tmp.push_back(x[i]);
    x.clear();
    for(int i=0; i<tmp.size(); i++)
        x.push_back(tmp[i]);
    return x;*/
    tmp.clear();
    for (int i = 0; i < x.size(); i++)
        if (real_map[v][x[i]])
            tmp.push_back(x[i]);
    return tmp;
}
vector<int> getUnion(vector<int> x, int v)
{
    vector<int>::iterator it = find(x.begin(), x.end(), v);
    if (it == x.end())
        x.push_back(v);
    return x;
}

void BronKerbosch(vector<int> all, vector<int> some, vector<int> none)
{
    if (flag)
        return;
    if (some.empty() && none.empty())
    {
        ans++;
        if (ans > 1000)
            flag = 1;
        return;
    }
    if (some.empty())
        return;
    int pivot = some[0];
    for (int i = some.size() - 1; i >= 0; i--)
    {
        int v = some[i];
        if (real_map[pivot][v])
            continue;
        BronKerbosch(getUnion(all, v), getIntersection_v_neighbor(some, v),
                     getIntersection_v_neighbor(none, v));
        if (flag)
            return;
        none = getUnion(none, v);
        some.erase(find(some.begin(), some.end(), v));
    }
}
void init()
{
    flag = ans = 0;
    memset(real_map, 0, sizeof real_map);
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        int a, b;
        vector<int> some;
        vector<int> all;
        vector<int> none;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a, &b);
            real_map[a][b] = real_map[b][a] = 1;
        }
        for (int i = 1; i <= n; i++)
            some.push_back(i);

        BronKerbosch(all, some, none);

        if (flag)
            printf("Too many maximal sets of friends.\n");
        else
            printf("%d\n", ans);
    }

    //cout<<"耗时"<<GetTickCount()-dwStartTime<<"ms"<<endl;

    return 0;
}

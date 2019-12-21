#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x7FFFFFFF;
struct node
{
    int next;
    long long date;
};
vector<node> zheng[100010];
vector<node> fu[100010];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, w, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &w, &v);
        node a;
        a.date = v;
        a.next = w;
        fu[u].push_back(a);
        a.next = u;
        zheng[w].push_back(a);
    }
    for (int i = 0; i <= n; i++)
    {
        if ((!fu[i].empty()) && (!zheng[i].empty()))
        {
            while (!zheng[i].empty())
            {
                long long tmp = zheng[i][zheng[i].size() - 1].date;
                zheng[i].pop_back();
                while (!fu[i].empty())
                {
                    if (tmp == 0)
                        break;
                    if (tmp >= fu[i][fu[i].size() - 1].date)
                    {
                        tmp -= fu[i][fu[i].size() - 1].date;
                        fu[i].pop_back();
                        continue;
                    }
                    else
                    {
                        fu[i][fu[i].size() - 1].date -= tmp;
                        break;
                    }
                }
            }
        }
    }
        
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!fu[i].empty())
        {
            cnt+=fu[i].size();
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<n;i++){
        if(!fu[i].empty()){
            for(int j=0;j<fu[i].size();j++)
            printf("%d %d %d\n",i,fu[i][j].next,fu[i][j].date);
        }
    }
    return 0;
}
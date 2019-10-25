
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
 
using namespace std;
struct cmp1
{
    bool operator()(int x, int y)
    {
        return x > y;//小的优先级高
    }
};
 
struct node
{
    int x;
    int y;
    friend bool operator <(const node &a, const node &b)
    {
        return a.x > b.x;//小的优先级高
    }
};
priority_queue<int, vector<int>,cmp1>q2;
priority_queue<node>q3;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        {
            node a;
            cin>>a.x>>a.y;
            q3.push(a);
        }
        cout<<endl;
    while(!q3.empty())
    {
        cout<<q3.top().x<<"  "<<q3.top().y<<endl;
        q3.pop();
    }
 
    return 0;
}

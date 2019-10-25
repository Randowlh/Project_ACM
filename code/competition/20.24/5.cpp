#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct node
{
    int q, m;
    friend bool operator<(const node &a, const node &b)
    {
        if(a.q==b.q){
            return a.m<b.m;
        }else{
            return a.q<b.q;
        }
    }
};
priority_queue<node> qp;
int main()
{
    int r;
    int n;
    node tmp1;
    cin >> r;
    for (int q = 0; q < r; q++)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp1.m >> tmp1.q;
        qp.push(tmp1);
        }
        int now = 0;
        while (!qp.empty())
        {
            if (now >= qp.top().m)
            {
                now++;
                qp.pop();
                continue;
            }
            else
            {
                ans += qp.top().q;
                now++;
                qp.pop();
            }
        }
        printf("%d66666666\n",ans);
    }
    return 0;
}

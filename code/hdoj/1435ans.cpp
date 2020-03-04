#include "bits/stdc++.h"

using namespace std;

int C;

struct Node
{
    double w, x, y, z;
    Node(double w = 0, double x = 0, double y = 0, double z = 0) : w(w), x(x), y(y), z(z) {}
} A[201], B[201]; //分别用来存放发射点和接收点的数据

struct P
{
    int to;
    double w, d;
    bool operator<(const P &rhs) const
    {
        if (d == rhs.d)
            return w > rhs.w;
        return d < rhs.d;
    }
    P(int a = 0, double b = 0, double c = 0) : to(a), w(b), d(c) {}
}; //用于所有的接收点在每一个发射点中的排序

bool vis[201];  //接收点是否已经匹配
int pr[201];    //接收点所匹配的发射点
P lj[201][201]; //用于排序的邻接矩阵

inline double dis(int a, int b)
{
    return sqrt((A[a].x - B[b].x) * (A[a].x - B[b].x) + (A[a].y - B[b].y) * (A[a].y - B[b].y) + (A[a].z - B[b].z) * (A[a].z - B[b].z));
} //求发射点与接收点距离的函数

void presolve()
{ //输入及预处理
    memset(vis, 0, sizeof(vis));
    cin >> C;
    for (int i = 0; i < C; ++i)
    {
        int a;
        double w, x, y, z;
        cin >> a >> w >> x >> y >> z;
        A[a - 1] = Node(w, x, y, z); //把所有的点的编号-1， 输出时+1
    }
    for (int i = 0; i < C; ++i)
    {
        int a;
        double w, x, y, z;
        cin >> a >> w >> x >> y >> z;
        B[a - 1] = Node(w, x, y, z);
    }
    for (int i = 0; i < C; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            lj[i][j] = P(j, B[j].w, dis(i, j)); //求所有发射点与所有接收点的距离
        }
    }
    for (int i = 0; i < C; ++i)
        sort(lj[i], lj[i] + C); //把接收点进行排序
}

inline bool cmp(int a, int b, int v)
{
    if ((dis(a, v) < dis(b, v)) || (dis(a, v) == dis(b, v) && A[a].w > A[b].w))
        return 1;
    return 0;
} //用于比较是否发射点a比发射点b更适合接收点v

int main()
{
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    while (N--)
    {
        presolve();
        queue<int> q;
        for (int i = 0; i < C; ++i)
            q.push(i); //先把所有的发射点放进队列
        int f;
        while (q.size())
        {
            int now = q.front();
            q.pop();
            f = 0;
            for (int i = 0; i < C; ++i)
            {
                int v = lj[now][i].to;
                if (!vis[v])
                { //如果接收点还未匹配
                    vis[v] = 1, pr[v] = now, f = 1;
                    break;
                }
                else if (vis[v] && cmp(now, pr[v], v))
                { //如果接收点已经匹配但是now比之前的匹配点pr[v]更适合
                    q.push(pr[v]);
                    pr[v] = now;
                    f = 1;
                    break;
                }
            }
            if (!f)
                break; //如果一个发射点now无法与任何一个接收点匹配，则表明Impossible
        }
        if (!f)
            printf("Impossible\n\n");
        else
        {
            for (int i = 0; i < C; ++i)
                printf("%d %d\n", pr[i] + 1, i + 1); //输入时-1，勿忘输出时+1
            puts("");
        }
        for (int i = 0; i < C; i++)
        {
            for (int j = 0; j < C; j = +)
            {
                cout << lj[i][j].<< endl;
            }
        }
    }
}
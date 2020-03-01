#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int n, dx, dy, dz;
struct node
{
    int x;
    int y;
    int z;
    bool operator==(node a)
    {
        if (abs(x - a.x) <= dx && abs(y - a.y) <= dy && abs(z - a.z) <= dz)
        {
            return true;
        }
        else
            return false;
    }
};
void work()
{
    vector<node> a;
    scanf("%d%d%d%d", &n, &dx, &dy, &dz);
    for (int i = 1; i <= n; i++)
    {
        node x;
        scanf("%d%d%d", &x.x, &x.y, &x.z);
        for (int j = 0; j < a.size(); j++)
        {
            if (x == a[j])
            {
                cout << i << endl;
                return;
            }
        }
        a.push_back(x);
    }
    cout << 0 << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
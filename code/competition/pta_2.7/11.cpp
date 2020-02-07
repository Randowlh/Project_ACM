#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
vector<int> a, b;
struct node
{
    int v;
    int r;
    int l;
    /* data */
} tree[100100];
int cnt = 0;
vector<int> ans;
int build_tree(int la, int ra, int lb, int rb)
{ 
    if (la > ra)
        return -1;
    int root = b[lb];
   int i = 0;
   while(a[la+i] != root) i++;
    tree[root].v = root;
    tree[root].r = build_tree(la+i+1,ra,lb+i+1,rb);
    tree[root].l = build_tree(la,la+i-1,lb+1,lb+i);
    return  root;
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        ans.push_back(tree[q.front()].v);
        if (tree[q.front()].r != -1)
        {
            q.push(tree[q.front()].r);
        }
        if (tree[q.front()].l != -1)
        {
            q.push(tree[q.front()].l);
        }
        q.pop();
    }
    return;
}
void work()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
  int s = build_tree(0, n - 1, 0, n - 1);
    // cout<<"dsad"<<endl;
    bfs(s);
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << ans[n - 1] << endl;
    return;
}
int main()
{
 //   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
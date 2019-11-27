#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    long long date;
    int left;
    int right;
    int lazy;
} st[400010];
int a[100010];
int n, m;
//int lz[100010];
long long quer(int pos, int l, int r);
void build(int x, int left, int right)
{
    if (left == right)
    {
        st[x].date = a[left];
        st[x].left = left;
        st[x].right = right;
        st[x].lazy = 0;
        return;
    }
    int mid = (left + right) / 2;
    build(x * 2, left, mid);
    build(x * 2 + 1, mid + 1, right);
    st[x].date = st[x * 2].date + st[x * 2 + 1].date;
    st[x].left = left;
    st[x].right = right;
    st[x].lazy = 0;
    return;
}
void updater(int pos, int l, int r, int x)
{
    if (st[pos].left == st[pos].right)
    {
        st[pos].date += x;
        return;
    }
    if (l == st[pos].left && st[pos].right == r)
    {
        st[pos].lazy += x;
        return;
    }
    int mid = (st[pos].right + st[pos].left) / 2;
    if (r <= mid)
    {
        updater(pos * 2, l, r, x);
    }
    else if (l > mid)
    {
        updater(pos * 2 + 1, l, r, x);
    }
    else
    {
        updater(pos * 2, l, mid, x);
        updater(pos * 2 + 1, mid + 1, r, x);
    }
   //st[pos].date = st[pos * 2].date + st[pos * 2 + 1].date;
    st[pos].date = quer(pos*2,st[pos].left,mid)+quer(pos*2+1,mid+1,st[pos].right);
    return;
}
long long quer(int pos, int l, int r)
{
    if (l == st[pos].left && r == st[pos].right)
    {
        return st[pos].date + st[pos].lazy * (r - l + 1);
    }
    int mid = (st[pos].left + st[pos].right) / 2;
    if (st[pos].lazy != 0)
    { //cout<<"loloo";
        /*
        updater(pos * 2 + 1, mid + 1, st[pos].right, st[pos].lazy);
        updater(pos * 2, st[pos].left, mid, st[pos].lazy);
        */
       st[pos*2].date+=st[pos].lazy*(st[pos*2].right-st[pos*2].left+1);
        st[pos*2+1].date+=st[pos].lazy*(st[pos*2+1].right-st[pos*2+1].left+1);
        st[pos*2].lazy+=st[pos].lazy;
        st[pos*2+1].lazy+=st[pos].lazy;
        //st[pos].add=0;
        st[pos].lazy = 0;
    }
    if (r <= mid)
    {
        return quer(pos * 2, l, r);
    }
    else if (l > mid)
    {
        return quer(pos * 2 + 1, l, r);
    }
    else
        return quer(pos * 2, l, mid) + quer(pos * 2 + 1, mid + 1, r);
}
int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    /*
    for(int i=1;i<n*4;i++){
        cout<<st[i].left<<' '<<st[i].date<<' '<<st[i].right<<endl;
    }
    */
    int a, b, c, d;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d%d%d", &b, &c, &d);
            // cout<<quer(1,b,c)<<'f'<<endl;
            updater(1, b, c, d);
            // cout<<quer(1,b,c)<<'l'<<endl;
        }
        if (a == 2)
        {
            scanf("%d%d", &b, &c);
            cout << quer(1, b, c) << endl;
        }
    }
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct stree
{
    int date;
    int left;
    int right;
} st[700010];
char cmd[100];
int a[50010];
int n,m;
void build(int x, int left, int right)
{
    st[x].left = left;
    st[x].right = right;
    if (left == right)
    {
        st[x].date = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(2 * x, left, mid);
    build(2 * x + 1, mid + 1, right);
    st[x].date = st[2 * x].date + st[2 * x + 1].date;
}
void update(int x, int pos, int val)
{
    if (st[x].left == st[x].right)
    {
        st[x].date = val;
        return;
    }
    int mid = (st[x].left + st[x].right) >> 1;
    if (pos <= mid)
        update(2 * x, pos, val);
    else
        update(2 * x + 1, pos, val);
    st[x].date = st[2 * x].date + st[2 * x + 1].date;
    return;
}
int quer(int x, int l, int r)
{
    if (st[x].left == l && st[x].right == r)
    {
        return st[x].date;
    }
    int mid = (st[x].left + st[x].right) / 2;
    if (r <= mid)
    {
        return quer(x * 2, l, r);
    }
    else if (l > mid)
    {
        return quer(x * 2 + 1, l, r);
    }
    else
        return quer(x * 2, l, mid) + quer(x * 2 + 1, mid + 1, r);
}
int main()
{

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        //  st[i].left = i - n + 1;
        // st[i].right = i - n + 1;
    }
    build(1, 1, n);
    //getchar();
    //for (int i = 1; i < n * 2; i++)
    /*{
            cout << st[i].left << ' ' << st[i].date << ' ' << st[i].right << endl;
        }*/

    int t;
    for(int i=0;i<m;i++){
        cin>>t;
        //scanf("%s", cmd);
        if (t==1)
        {
            int l;
            int r;
            cin >> l >> r;
            cout << quer(1, l, r) << endl;
        }
        if (cmd[0] == 'A')
        {
            int k;
            int l;
            cin >> l >> k;
            //l+=n-1;

            // l = find(l, 1);
            k += a[l];
            //cout<<k<<endl;
            update(1, l, k);
        }
        if (cmd[0] == 'S')
        {
            int k;
            int l;
            cin >> l >> k;
            //l+=n-1;
            //l = find(l, 1);
            k = a[l] - k;
            //cout<<k<<endl;
            update(1, l, k);
        }
    }
}
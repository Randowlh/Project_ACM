#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct stree
{
    long long date;
    int left;
    int right;
} st[700010];
char cmd[100];
int a[50010];
int n;
/*
int find(int x, int now)
{
    if (st[now].left == x && st[now].right == x)
    {
        return now;
    }
    int mid = (st[now].left + st[now].right) / 2;
    if (mid >= x)
    {
        return find(x, now * 2);
    }
    else
        return find(x, now * 2 + 1);
}*/
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
void update(int x, int pos,int val)
{   
    if(st[x].left==st[x].right)
	{
		st[x].date=val;
		return;
	}
	int mid=(st[x].left+st[x].right)>>1;
	if(pos<=mid)
		update(2*x,pos,val);
	else
		update(2*x+1,pos,val);
	st[x].date=st[2*x].date+st[2*x+1].date;
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
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            //  st[i].left = i - n + 1;
            // st[i].right = i - n + 1;
        }
        build(1, 1, n);
        //getchar();
        //for (int i = 1; i < n * 2; i++)
            /*{
            cout << st[i].left << ' ' << st[i].date << ' ' << st[i].right << endl;
        }*/
            cout << "Case " << q + 1 << ':' << endl;
        while (true)
        {
            scanf("%s",cmd);
            if (cmd[0] == 'E')
                break;
            if (cmd[0] == 'Q')
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
                update(1,l, k);
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
                update(1,l, k);
            }
        }
    }
}
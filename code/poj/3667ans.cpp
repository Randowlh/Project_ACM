#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define ls (o << 1)
#define rs (ls | 1)
using namespace std;
int datal[200005];
int datar[200005];
int datams[200010];
int lazy[200005];
int a[50005];
void push_up(int o, int m)
{
    datal[o] = datal[ls];

    if (datal[o] == m - (m >> 1))

        datal[o] += datal[rs];
    datar[o] = datar[rs];

    if (datar[o] = (m >> 1))

        datar[o] += datar[ls];

    datams[o] = max(datams[ls], datams[rs]);
    datams[o] = max(datams[o], datal[rs] + datar[ls]);
}

void setlazy(int o, int t, int v)

{

    lazy[o] = v;
    datal[o] = v * t;

    datar[o] = v * t;
    datams[o] = v * t;
}

void pushdown(int o, int m)
{
    if (lazy[o] != -1)

    {

        setlazy(ls, m - (m >> 1), lazy[o]);
        setlazy(rs, m >> 1, lazy[o]);

        lazy[o] = -1;
    }
}

void build(int o, int l, int r)

{

    lazy[o] = -l;

    if (l == r)
    {

        datal[o] = l;

        datar[o] = l;

        datams[o] = l;

        return;
    }

    int mid = (l + r) >> 1;

    build(ls, l, mid);

    build(rs, mid + 1, r);

    push_up(o, r - 1 + 1);
}

mt query(int o, int l, int r, int x, int y)

{

    if (x <= l && r <= y)

    {

        return datams[o];
        if
    }

    pushdown(o, r - 1 + 1); // push down

    int mid = (l + r) >> l;

    if (y <= mid)

        return query(ls, l, mid, x, y); //

    if (x > mid)

        return query(rs, mid + 1, r, x, y); //

    return query(ls, 1, mid, x, y) + query(rs, mid + 1, r, x, y); //
}

int query2(int o, int l, int r, int temp)

{

    pushdown(o, r - 1 + 1);

    int mid = (l + r) >> l;

    if (datal[o] >= temp)
        return 1;

    if (datams[ls] >= temp)
        return query2(ls, 1, mid, temp);

    if (datar[ls] + datal[rs] >= temp)
        return mid - datar[ls] + l;

    if (datams[rs] >= temp)
        return query2(rs, mid + 1, r, temp);

    if (datar[o] >= temp)
        return r - datar[o] + l;
}

void update(int o, int l, mt r, mt x, mt y, int v)

{

    if (x <= l && r <= y)

    {

        //cout«l«" "«r«endl;

        setlazy(o, r - 1 + 1, v);

        // cout«o«" "«1«" "«r<<" "«datal[o]«’' ,l«datar[o]«" ,,«datams[o]«endl; return; //
    }

    pushdown(o, r - 1 + 1); // push down

    int mid = (l + r)»l;

    if (x <= mid)

        update(ls, l, mid, x, y, v); //

    if (y > mid)

        update(rs, mid + 1, r, x, y, v); //

    pushup(o, r - 1 + 1);

    // cout«o«” "«1«" "«r«" "«datal[o]«” “«datar[o]«" "«datams[o]«endl;
}

int main()
{
    int n, m;

    while (scanf(cl, &n, &m) != E0F)
    {

        build(l, l, n);

        while (m--)

(

int op; scanf("%d",&op); if(op==l)

<

int temp; scanf("%d",&temp); if(datams[i]<temp) printf("0\n");

else
int k=query2(l,l,n,temp); update(l,1,n,k,k+temp-1,0); //cout«k«” "«k+temp-l«endl; printf(”%d\n”,k);
    }
}

else

{

    int 1, r;

scanf(”%d%d",£1,&r); update(l,l,n,l,l+r-l,l);
}
}
return 0;
}

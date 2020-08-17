struct fhq_treap
{
    struct node
    {
        int l, r;
        int val, key;
        int size;
    } fhq[maxn];
    int cnt, root;
    inline int newnode(int val)
    {
        fhq[++cnt].val = val;
        fhq[cnt].key = rnd();
        fhq[cnt].size = 1;
        fhq[cnt].l = fhq[cnt].r = 0;
        return cnt;
    }
    inline void pushup(int now)
    {
        fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
    }
    void split(int now, int val, int &x, int &y)
    {
        if (!now)
        {
            x = y = 0;
            return;
        }
        else if (fhq[now].val <= val)
        {
            x = now;
            split(fhq[now].r, val, fhq[now].r, y);
        }
        else
        {
            y = now;
            split(fhq[now].l, val, x, fhq[now].l);
        }
        pushup(now);
    }
    int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (fhq[x].key > fhq[y].key)
        {
            fhq[x].r = merge(fhq[x].r, y);
            pushup(x);
            return x;
        }
        else
        {
            fhq[y].l = merge(x, fhq[y].l);
            pushup(y);
            return y;
        }
    }
    inline void insert(int val)
    {
        int x, y;
        split(root, val, x, y);
        root = merge(merge(x, newnode(val)), y);
    }
    inline void del(int val)
    {
        int x, y, z;
        split(root, val - 1, x, y);
        split(y, val, y, z);
        y = merge(fhq[y].l, fhq[y].r);
        root = merge(merge(x, y), z);
    }
    inline int getrk(int num)
    {
        int x, y;
        split(root, num - 1, x, y);
        int ans = fhq[x].size + 1;
        root = merge(x, y);
        return ans;
    }
    inline int getnum(int rank)
    {
        int now=root;
        while(now)
        {
            if(fhq[fhq[now].l].size+1==rank)
                break;
            else if(fhq[fhq[now].l].size>=rank)
                now=fhq[now].l;
            else
            {
                rank-=fhq[fhq[now].l].size+1;
                now=fhq[now].r;
            }  
        }
        return fhq[now].val;
    }
    inline int pre(int val)
    {
        int x, y, ans;
        split(root, val - 1, x, y);
        int t = x;
        while (fhq[t].r)
            t = fhq[t].r;
        ans = fhq[t].val;
        root = merge(x, y);
        return ans;
    }
    inline int aft(int val)
    {
        int x, y, ans;
        split(root, val, x, y);
        int t = y;
        while (fhq[t].l)
            t = fhq[t].l;
        ans = fhq[t].val;
        root = merge(x, y);
        return ans;
    }
} tree;
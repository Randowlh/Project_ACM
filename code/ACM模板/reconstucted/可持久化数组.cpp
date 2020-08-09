int date[1100000];
vector<int> root;
struct chair_man_tree{
    struct node{
        int v;
        int lson,rson;
    }tree[20100000];
    int tail=0;
    int addnew(int now){
        tail++;
        tree[tail]=tree[now];
        return  tail;
    }
    int build(int l,int r){
        int now=tail++;
        if(l==r){
            tree[now].v=date[l];
            tree[now].lson=tree[now].rson=-1;
            return now;
        }
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int update(int pos,int l,int r,int x,int val){
        int now=addnew(pos);
        if(l==r){
            tree[now].v=val;
            return now;
        }
        int mid=(l+r)>>1;
        if(x<=mid)
            tree[now].lson=update(tree[now].lson,l,mid,x,val);
        if(x>mid)
            tree[now].rson=update(tree[now].rson,mid+1,r,x,val);
        return now;
    }
    int query(int pos,int l,int r,int x){
        if(l==r)
            return tree[pos].v;
        int  mid=(l+r)>>1;
        if(x<=mid)
            return query(tree[pos].lson,l,mid,x);
        else return query(tree[pos].rson,mid+1,r,x);
    }
} a;
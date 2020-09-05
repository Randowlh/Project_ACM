#include <bits/stdc++.h>
using namespace std;
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
const int maxn = 1e5 + 100;
mt19937 rnd(114514);
class fhq_treap
{
public:
    struct node
    {
        int l, r;
        int val, key;
        int size;
        int lazy;
    } T[maxn];
    int cnt, root;
    inline int newnode(int val)
    {
        T[++cnt].val = val;
        T[cnt].key = rnd();
        T[cnt].l = T[cnt].r = T[cnt].lazy = 0;
        T[cnt].size = 1;
        return cnt;
    }
    inline void pushup(int pos)
    {
        T[pos].size=1;
        if(T[pos].l)
            T[pos].size+=T[T[pos].l].size;
        if(T[pos].r)
            T[pos].size+=T[T[pos].r].size;
        //T[pos].size = 1 + T[T[pos].l].size + T[T[pos].r].size;
        // T[pos].size = min(T[pos].val, min(T[T[pos].l].val, T[T[pos].r].val));
    }
    inline void pushdown(int pos)
    {
        if (!T[pos].lazy)
            return;
        T[pos].lazy = false;
        swap(T[pos].l, T[pos].r);
        if (T[pos].l)
            T[T[pos].l].lazy ^= 1;
        if (T[pos].r)
            T[T[pos].r].lazy ^= 1;
    }
    void split(int now, int sz, int &x, int &y)
    {
        if (!now)
        {
            x = y = 0;
            return;
        }
        pushdown(now);
        if (sz == 0)
        {
            x = 0;
            y = now;
            return;
        }
        if (T[T[now].l].size < sz){
            x = now;
            split(T[now].r, sz - T[T[now].l].size - 1, T[now].r, y);
        }
        else{
            y = now;
            split(T[now].l, sz, x, T[now].l);
        }
        pushup(now);
    }
    int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (T[x].key < T[y].key){
            pushdown(x);
            T[x].r=merge(T[x].r,y);
            pushup(x);
            return x;
        }else{
            pushdown(y);
            T[y].l=merge(x,T[y].l);
            pushup(y);
            return y;
        }

    }
    inline void reverse(int l,int r){
        int x,y,z;
        split(root,l-1,x,y);
        split(y,r-l+1,y,z);
        T[y].lazy^=1;
        root=merge(x,merge(y,z));
    }
    inline int& getnum(int rk){
        int x,y,z;
        split(root,rk-1,x,y);
        split(y,1,y,z);
        int ans=y;
        root=merge(x,merge(y,z));
        return T[ans].val;
    }
    inline void zx(int x){
        pushdown(x);
        if(T[x].l)
            zx(T[x].l);
        printf("%d ",T[x].val);
        if(T[x].r)
            zx(T[x].r);
    }
}fhq;
vector<pair<int,int>> xl;
int main(){
    //freopen("in.txt", "r", stdin);
    int n,m,k;
    rd(n),rd(m),rd(k);
    for(int i=1;i<=n;i++){
        fhq.root=fhq.merge(fhq.root,fhq.newnode(i));
    }
    int l,r;
    for(int i=0;i<m;i++){
        rd(l),rd(r);
        fhq.reverse(l,r);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",fhq.getnum(i));
    puts("");
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
struct node
{
        int l, r, val;
        int size, fact;
        bool exsit;
};
class tzy_tree
{
    public:
    double alpha=0.75;
    node tzy[1100000];
    int root=0,cnt=0;
    vector<int> tt;
    inline void newnode(int &now,int v){
        now=++cnt;
        tzy[now].val=v;
        tzy[now].l=tzy[now].r=0;
        tzy[now].size=tzy[now].fact=tzy[now].exsit=1;
    }
    inline bool imbalanced(int now){
        if(max(tzy[tzy[now].l].size,tzy[tzy[now].r].size)>tzy[now].size*alpha||tzy[now].size-tzy[now].fact>tzy[now].size*0.3)
            return true;
        return false;
    }
    void zhongxu(int now){
        if(!now)
            return;
        zhongxu(tzy[now].l);
        if(tzy[now].exsit)
            tt.push_back(now);
        zhongxu(tzy[now].r);   
    }
    void lift(int l,int r,int &now){
        if(l==r){
            now=tt[l];
            tzy[now].l=tzy[now].r=0;
            tzy[now].fact=tzy[now].size=1;
            return;
        }
        int m=(l+r)>>1;
        while(l<m&&tzy[tt[m]].val==tzy[tt[m-1]].val)
            m--;
        now=tt[m];
        if(l<m) lift(l,m-1,tzy[now].l);
        else tzy[now].l=0;
        lift(m+1,r,tzy[now].r);
        tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1; 
        tzy[now].fact=tzy[tzy[now].l].fact+tzy[tzy[now].r].fact+1;
    }
    void rebuild(int &now){
        tt.clear();
        zhongxu(now);
        if(tt.empty()){
            now=0;
            return;
        }
        lift(0,tt.size()-1,now);
    }
    void update(int now,int end){
        if(!now)return;
        if(tzy[end].val<tzy[now].val)
            update(tzy[now].l,end);
        else update(tzy[now].r,end);
        tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
    }
    void check(int &now,int end){
        if(now==end)
            return;
        if(imbalanced(now)){
            rebuild(now);
            update(root,now);
            return;
        }
        if(tzy[end].val<tzy[now].val)
            check(tzy[now].l,end);
        else 
            check(tzy[now].r,end);
    }
    inline void init(){
        root=1;
        cnt=0;
    }
    void insert(int &now,int val){

        if(!now){
            newnode(now,val);
            check(root,now);
            return;
        }
        tzy[now].fact++,tzy[now].size++;
        if(val<tzy[now].val)
            insert(tzy[now].l,val);
        else
            insert(tzy[now].r,val);
    }
    void erase(int now,int val){
        if(tzy[now].exsit&&tzy[now].val==val){
            tzy[now].exsit=false;
            tzy[now].fact--;
            check(root,now);
            return;
        }
        tzy[now].fact--;
        if(val<tzy[now].val)
            erase(tzy[now].l,val);
        else erase(tzy[now].r,val);
    }
    int getrank(int val){
        int now=root,rk=1;
        while(now){
            if(val<=tzy[now].val)
                now=tzy[now].l;
            else rk+=tzy[now].exsit+tzy[tzy[now].l].fact,now=tzy[now].r;
        }
        return rk;
    }
    int getnum(int rk){
        int now=root;
        while(now){
            if(tzy[now].exsit&&tzy[tzy[now].l].fact+tzy[now].exsit==rk)
                break;
            else if(tzy[tzy[now].l].fact>=rk){
                now=tzy[now].l;
            }else{
                rk-=tzy[tzy[now].l].fact+tzy[now].exsit;
                now=tzy[now].r;
            }
        }
        return tzy[now].val;
    }
}tree;
signed main()
{
   // freopen("in.txt", "r", stdin);
    int t;
    int a, b;
    rd(t);
    for(int q=0;q<t;q++){
        rd(a),rd(b);
        if(a==1){
            tree.insert(tree.root,b);
        }else if(a==2){
            tree.erase(tree.root,b);
        }else if(a==3){
            printf("%lld\n",tree.getrank(b));
        }else if(a==4){
            printf("%lld\n",tree.getnum(b));
        }else if(a==5){
            printf("%lld\n",tree.getnum(tree.getrank(b)-1));
        }else if(a==6){
            printf("%lld\n",tree.getnum(tree.getrank(b+1)));
        }
    }
}
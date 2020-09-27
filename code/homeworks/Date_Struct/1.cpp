#include<bits/stdc++.h>
using namespace std;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
struct link_list{
    struct node{
        node* nxt;
        int v;
        node(int a):v(a), nxt(NULL){}
    };
    node* head= NULL;
    void insert(int v){
        if(head==NULL){
            head=new node(v);
            return;
        }
        node* now=head,*tmp=new node(v);
        while(now!=NULL){
            if(now->nxt==NULL||now->nxt->v>=v){
                tmp->nxt=now->nxt;
                now->nxt=tmp;
                return;
            }
            now=now->nxt;
        }
    }
    void unique(){
        node *now=head;
        while(now!=NULL){
            while(now->nxt!=NULL&&now->nxt->v==now->v){
                node* tt=now->nxt;
                now->nxt=now->nxt->nxt;
                delete tt;
            }
            now=now->nxt;
        }
    }
    bool del(int v){
        node* now=head;
        while(now!=NULL){
            int flag=0;
            while(now->nxt!=NULL&&now->nxt->v==v){
                flag=1;
                node* tt=now->nxt;
                now->nxt=now->nxt->nxt;
                delete tt;
            }
            if(flag)
                return true;
            now=now->nxt;
        }
        return false;
    }
    void output(){
        node *now=head;
        printf("The element in link_list is:\n");
        while(now!=NULL){
            wt(now->v),putchar(' ');
            now=now->nxt;
        }
        putchar('\n');
    }
}test;
int main(){
    int n;
    rd(n);//输入原始数据 
    int tmp;
    for(int i=1;i<=n;i++){
        rd(tmp);
        test.insert(tmp);
    }
    //有三个操作
    //操作1 插入一个数 
    //操作2 删除一个数和所有和他一样的数
    //操作3 去重操作
    test.output();
    int m;//操作数
    int opt,val;
    rd(m);
    for(int i=1;i<=m;i++){
        rd(opt);
        if(opt==1){
            rd(val);
            test.insert(val);
            printf("insert sucessful!\n");
        }else if(opt==2){
            rd(val);
            if(test.del(val)){
                printf("delete sucessful!\n");
            }else {
                printf("delete failed!(element does not exists)\n");
            }
        }else test.unique();
        test.output();
    }
}
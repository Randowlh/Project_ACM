#include<bits/stdc++.h>
using namespace std;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
struct liner_table{
    int sz=0;
    int limit=0;
    int *date;
    void expand(int a){
        limit+=a;
        int* tdate=new int[limit];
        for(int i=0;i<sz;i++)
            tdate[i]=date[i];
        swap(tdate,date);
        delete[] tdate;
    }
    void ins(int v){
        if(sz==limit)
            expand(10);
        for(int i=0;i<sz;i++){
            if(date[i]>v){
                for(int j=sz;j>i;j--){
                    date[j]=date[j-1];
                }
                date[i]=v;
                sz++;
                return;
            }
        }
        date[sz]=v;
        sz++;
    }
    bool del(int v){
        int fr=-1,ed=-1;
        for(int i=0;i<sz;i++){
            if(fr==-1&&date[i]==v){
                fr=i;
            }
            if(date[i]!=v&&fr!=-1){
                for(int j=i;j<sz;j++)
                    date[fr+j-i]=date[j];
                sz-=i-fr;
                return true;
            }
        }
        if(fr==-1)
            return false;
        sz=fr;
        return true;
    }
    void unique(){
        int tail=1;
        for(int i=1;i<sz;i++){
            if(date[i]!=date[i-1]){
                date[tail]=date[i];
                tail++;
            }
        }
        sz=tail;
        return;
    }
    void output(){
        for(int i=0;i<sz;i++){
            printf("%d ",date[i]);
        }
        putchar('\n');
    }
}a;
int main(){
    int n,m;//初始有n个数，之后进行m个操作
    //有三个操作
    //操作1 插入一个数 
    //操作2 删除一个数和所有和他一样的数
    //操作3 去重操作
    rd(n);
    int tmp;
    for(int i=1;i<=n;i++){
        rd(tmp);
        a.ins(tmp);
    }
    rd(m);
    a.output();
    int opt,x;
    for(int i=1;i<=m;i++){
        rd(opt);
        if(opt==1){
            rd(x);
            a.ins(x);
        }else if(opt==2){
            rd(x);
            if(a.del(x))
                printf("delete successful\n");
            else printf("delete failed\n");
        }else{
            a.unique();
            printf("uniqued\n");
        }
        a.output();
    }
}
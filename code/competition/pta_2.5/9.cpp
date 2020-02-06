#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int n,m;
int date[10010];
struct node
{   
    int w;
    int u;
    /* data */
}rd[10010];
bool fl[10010];
int find(int x){
    if(date[x]==x){
        return x;
    }else{
        date[x]=find(date[x]);
        return date[x];
    }
}
void mg(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l==r){
        return;
    }else date[l]=r;
    return;
}
int init(){
    for(int i=0;i<=n;i++){
        date[i]=i;
      //  fl[i]=true;
    }
    return 0;
}
int tj(set<int> t){
    set<int> s;
    for(int i=1;i<=n;i++){
        if(t.count(i)==0)
        s.insert(date[i]);
    }
    return s.size();
}
void work(){
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++){
        scanf("%d%d",&rd[i].u,&rd[i].w);
    }
    int k;
    cin>>k;
    for(int q=0;q<k;q++){
        int tn;
        cin>>tn;
        init();
        set<int> t;
        int tmp;
        for(int i=0;i<tn;i++){
            scanf("%d",&tmp);
            t.insert(tmp);
        }
        for(int i=0;i<m;i++){
            if(t.count(rd[i].u)==0&&t.count(rd[i].w)==0){
                mg(rd[i].u,rd[i].w);
            }
        }
        if(tj(t)<n-tn){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
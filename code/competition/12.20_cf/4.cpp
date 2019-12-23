#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
struct node{
    int l;
    int r;
    int id;
    bool operator<(node a){
        return  this->l<a.l;
    }
}date[500010];
int d[500010];
int find(int x){
    if(d[x]!=x){
        return d[x]=find(d[x]);
    }else 
    return d[x];
}
void merg(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l!=r){
        d[l]=r;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&date[i].l,&date[i].r);
        date[i].id=i+1;
        d[i+1]=i+1;
    }
    sort(date,date+n);
    set<pair<int,int>> s;
    set<pair<int,int>>::iterator it;
    int tol=0;
    for(int i=0;i<n;i++){
        pair<int,int> k;
        k.first=date[i].l;
        k.second=date[i].id;
        s.insert(k);
    }
    for(int i=0;i<n;i++){
        if(tol>n-1){
            printf("NO3\n");
            return 0;
        }
        pair<int,int> t;
        t.first=date[i].l;
        t.second=date[i].id;
        it=s.lower_bound(t);
        while(it!=s.end()){
             if(it->first>date[i].r){
                 break;
             }
             if(find(date[i].id)==find(it->second)){
                 printf("NO2\n");
                 return 0;
             }else{
                 merg(date[i].id,it->second);
                 tol++;
             }
             it++;
        }
        t.first=date[i].r;
        s.insert(t);
    }
    if(tol==n+1){
        cout<<"YES"<<endl;
    }else {
        cout<<"NO1"<<endl;
    }
    return 0;
}
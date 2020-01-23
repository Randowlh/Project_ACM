#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node{
    int x;
    int y;
    bool operator<(node a){
        if(x==a.x)
        return y<a.y;
        else 
        return x<a.x;
    }
};
void work(){
    int n;
    node date[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&date[i].x,&date[i].y);
    }
    sort(date,date+n);
    int tx=0;
    int ty=0;
    int fl=0;
    for(int i=0;i<n;i++){
        if(date[i].x<tx){
            fl=1;
            break;
        }
        if(date[i].y<ty){
           fl=1;
           break; 
        }
        tx=max(tx,date[i].x);
        ty=max(ty,date[i].y);
    }
    if(fl==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    tx=0;
    ty=0;
    for(int i=0;i<n;i++){
        if(tx<date[i].x){
            for(int j=0;j<date[i].x-tx;j++){
                cout<<"R";
            }
            tx=date[i].x;
        }
        if(ty<date[i].y){
            for(int j=0;j<date[i].y-ty;j++){
                cout<<"U";
            }
            ty=date[i].y;
        }
    }
    cout<<endl;
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
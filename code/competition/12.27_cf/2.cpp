#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{   
    int num;
    int date;
    bool operator<(node a)const{
        return date<a.date;
    }
    /* data */
};
void work(){
    ll n,t;
    cin>>n>>t;
    ll tol=0;
    int date[110000];
    priority_queue<node> q;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    int flag=0;
    for(int i=0;i<n;i++){
        node a;
        a.date=date[i];
        a.num=i+1;
        q.push(a);
        tol+=date[i];
        if(tol>t){
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<0<<endl;
    else
    cout<<q.top().num<<endl;
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{   int v;
    int pos;
    bool operator<(node a){
        return this->v<a.v;
    }
    /* data */
};
node mi(vector<node> a){
    node ni=a[0];
    for(int i=1;i<a.size();i++){
        if(ni.v>a[i].v){
            ni.v=a[i].v;
            ni.pos=a[i].pos;
        }
    }
    return ni;
}
int flag[1000];
void work(){
    int n;
    int k;
    int pos,num;
    cin>>n>>k;
    //int cnt=k+1;
    vector<node> ans;
    cout<<"? ";
    for(int i=1;i<=k;i++){
        cout<<i<<' ';
    }cout<<endl;
    cin>>pos>>num;
    node a;
    flag[pos]=1;
    a.pos=pos;
    a.v=num;
    ans.push_back(a);
    while(ans.size()<k){
        int ct=0;
        int cnt=1;
        cout<<"? ";
        int fl=0;
        while(ct<k){
            if(cnt>n){
            fl=1;
             break;   
            }
            if(flag[cnt]==0){
                cout<<cnt<<' ';
                ct++;
            }
            cnt++;
        }
        if(fl=1){
            for(int i=0;i<k-ct;i++){
                cout<<ans[i].pos<<' ';
            }
        }
        cout<<endl;
        cin>>pos>>num;
        node a;
        flag[pos]==1;
        a.pos=pos;
        a.v=num;
        ans.push_back(a);
    }
    sort(ans.begin(),ans.end());
    cout<<"? ";
    for(int i=0;i<k;i++){
        cout<<ans[i].pos<<' ';
    }
    cout<<endl;
    cin>>pos>>num;
    for(int i=0;i<ans.size();i++){
        if(ans[i].pos==pos){
            cout<<"! "<<i+1<<endl;
            return;
        }
    }
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
  //  cin>>t;
    while(t--){
        work();
    }
    return 0;
}
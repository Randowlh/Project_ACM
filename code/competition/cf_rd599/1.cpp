#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node{
    int a,b;
};
void work(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;  
    int mp[300];
    memset(mp,0,sizeof(mp));
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        mp[b[i]]++;
    }
    int fl=0;
    for(int i=0;i<300;i++){
        if(mp[i]%2!=0){
            fl=1;
            break;
        }
    }
    if(fl){
        cout<<"NO"<<endl;
        return;
    }
    vector<node> ans;
    for(int i=0;i<n;i++){
        char now=a[i];
        if(b[i]==now){
            continue;
        }
        int flag=0;
        for(int j=i+1;j<n;j++){
            if(a[j]==now){
                node x;
                x.a=j;
                x.b=i;
                ans.push_back(x);
                swap(a[x.a],b[x.b]);
                break;
            }
            if(b[j]==now){
                node x;
                x.a=i+1;
                x.b=j;
                 swap(a[x.a],b[x.b]);
                ans.push_back(x);
                x.a=i+1;
                x.b=i;
                 swap(a[x.a],b[x.b]);
                ans.push_back(x);
                break;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].a+1<<' '<<ans[i].b+1<<endl;
    }

}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
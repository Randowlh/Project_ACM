#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{
    string a,b;
};
struct ps
{
    int j;
    string name;
    /* data */
};
void work(){
    int n;
    cin>>n;
    vector<ps> s;
    for(int i=0;i<n;i++){
        int a;
        string b;
        cin>>a>>b;
        ps x;
        x.j=a;
        x.name=b;
        s.push_back(x);
    }  
    int cnt=0;
    int flag[100];
    memset(flag,1,sizeof(flag));
    vector<node> ans;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(s[i].j!=s[j].j&&flag[j]){
                flag[i]=0;
                flag[j]=0;
                node x;
                x.a=s[i].name;
                x.b=s[j].name;
                ans.push_back(x);
                cnt+=2;
                break;
            }
        }
        if(cnt==n)
        break;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].a<<' '<<ans[i].b<<endl;
    }
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
  //  cin>>t;
    while(t--){
        work();
    }
    return 0;
}
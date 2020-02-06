#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    char c;
    int n;
    cin>>c>>n;
    getchar();
   // cout<<n<<endl;
    string ans[1000];
    string in[1000];
    for(int i=0;i<n;i++){
        getline(cin,in[i]);
      //  cout<<in[i]<<endl;
    }
    for(int i=0;i<n;i++){
        ans[i]=in[n-1-i];
      //  cout<<"das"<<endl;
        reverse(ans[i].begin(),ans[i].end());
    }
    int fl=1;
    for(int i=0;i<n;i++){
        if(ans[i]!=in[i]){
            fl=0;
        }
    }
    if(fl){
        cout<<"bu yong dao le"<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){
            if(ans[i][j]=='@')
            cout<<c;
            else 
            cout<<' ';
        }
        cout<<endl;
    }
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
//bu yong dao le

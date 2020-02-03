#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{   
    string name;
    set<int> s;
    int cnt=0;
    bool operator<(node a){
        if(s.size()==a.s.size()){
            return cnt<a.cnt;
        }
        return  s.size()>a.s.size();
    }
    /* data */
};
void work(){
    int n;
    string tmp;
    int t;
    cin>>n;
    vector<node> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
       // cout<<tmp<<endl;
        node x;
        x.name=tmp;
        int m;
        cin>>m;
        x.cnt=m;
        for(int j=0;j<m;j++){
            cin>>t;
            x.s.insert(t);
        }
        v.push_back(x);
    }
  //  cout<<"es"<<endl;
    sort(v.begin(),v.end());
    if(v.size()<3){
        for(int i=0;i<v.size();i++){
            cout<<v[i].name<<' ';
        }
        for(int i=0;i<3-v.size()-1;i++){
            cout<<"- ";
        }
        cout<<'-'<<endl;
    }else{
        for(int i=0;i<3-1;i++){
            cout<<v[i].name<<' ';
        }
        cout<<v[2].name<<endl;
    }
 //   cout<<endl;
}
int main(){
  //  freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
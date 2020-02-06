#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node{
    string n;
    int b;
    bool operator<(node a ) {
        return n<a.n;
    }
};
void work(){
    int n;
    set<string> gz;
    cin>>n;
    string tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        gz.insert(tmp);
    }
    int m;
    cin>>m;
    vector<node> t;
    int z;
    double pj=0;
    for(int i=0;i<m;i++){
        cin>>tmp>>z;
        node x;
        pj+=z;
        x.n=tmp;
        x.b=z;
        t.push_back(x);
    }
  //  cout<<m<<endl;
    pj/=m;
    int fl=1;
    sort(t.begin(),t.end());
    for(int i=0;i<m;i++){
        if((double)t[i].b>pj&&gz.count(t[i].n)==0){
            cout<<t[i].n<<endl;
            fl=0;
        }
    }
    if(fl)
    cout<<"Bing Mei You"<<endl;
    return;
    
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
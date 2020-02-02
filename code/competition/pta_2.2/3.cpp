#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
bool cmp(char a,char b){
    return  a>b;
}
void work(){
    string k;
    map<int,int> m;
    cin>>k;
    vector<int> t;
    vector<int> ans;
    string tmp;
    tmp=k;
    sort(tmp.begin(),tmp.end(),cmp);
    for(int i=0;i<tmp.size();i++){
        if(m.count(tmp[i]-'0')==0){
            m[tmp[i]-'0']=t.size();
            t.push_back(tmp[i]-'0');
        }
    }
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<t.size()-1;i++){
        cout<<t[i]<<',';
    }
    cout<<t[t.size()-1]<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    for(int i=0;i<k.size()-1;i++){
        cout<<m[k[i]-'0']<<',';
    }
      cout<<m[k[k.size()-1]-'0']<<"};"<<endl;
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

//int[] arr = new int[]{8,3,2,1,0};
//int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};

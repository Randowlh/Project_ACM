#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){   
   
    int n,m,k;
    cin>>n>>m>>k;
    int mp[100][1010];
    for(int q=0;q<k;q++){
        for(int i=0;i<n;i++){
           //  cout<<12312<<endl;
            cin>>mp[q][i];
        }
    }
    // cout<<12312<<endl;
    //cout<<"sda"<<endl;
    for(int q=0;q<k;q++){
        set<int> s;
        stack<int> v;
       // v.clear();
        s.clear();
       // int tmp;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(mp[q][i]==cnt){
                cnt++;
            }else
            {
                 v.push(mp[q][i]);
                 s.insert(mp[q][i]);
            }
            while(s.count(cnt)!=0){
                int ct=0;
                stack<int> k;
                while(true){
                    ct++;
                    if(v.top()==cnt){
                        while(!k.empty()){
                            v.push(k.top());
                            k.pop();
                        }
                        break;
                    }
                    k.push(v.top());
                    v.pop();
                }
               // cout<<ct<<endl;
                if(ct>=m){
                    cout<<"NO"<<endl;
                    break;
                }
                cnt++;
            }
        }
        if(cnt>=n+1){
            cout<<"YES"<<endl;
        }
    }
    return;
}
int main(){
 //   freopen("in.txt","r",stdin);
    int t=1;
  //  cin>>t;
    while(t--){
        work();
    }
    return 0;
}
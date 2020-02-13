#include<bits/stdc++.h>
using namespace std;
struct pai{
    int hs;
    int v;
    bool operator<(pai a){
        if(v==a.v){
            return hs<a.hs;
        }else return v<a.v;
    }
};
string biao="23456789TJQKA";
string biao2="CDSH";
pai self[510];
int n;
pai dui[510];
int book[510];
int ans;
int pr[510];
int mp[510][510];
map<char,int> M1,M2;
bool dfs(int x){
    for(int i=0;i<n;i++){
        if(mp[x][i]&&book[i]==0){
            book[i]=1;
            //cout<<">>"<<endl;
            if(pr[i]==-1||dfs(pr[i])){
                pr[i]=x;
             //   cout<<"das"<<endl;
                return true;
            }
        }
    }
    return false;
}
void xyl(){
     ans=0;
    memset(pr, -1, sizeof(pr));
    for(int i=0;i<n;i++){
        memset(book, 0, sizeof(book));
        if(dfs(i)){
           // cout<<"lol"<<endl;
            ans++;
        }
    }
    return ;
}
void work(){
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        pai x;
        x.hs=M2[a[1]];
        x.v=M1[a[0]];
        dui[i]=x;
    //    cout<<x.v<<" "<<x.hs<<endl;
    }
    for(int i=0;i<n;i++){
        cin>>a;
        pai x;
        x.hs=M2[a[1]];
        x.v=M1[a[0]];
        self[i]=x;
      //  cout<<x.v<<" "<<x.hs<<endl;
    }
    memset(mp,0,sizeof(mp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dui[j]<self[i]){
                mp[i][j]=1;
            }
           // cout<<mp[i][j]<<' ';
        }
       // cout<<endl;
    }
    xyl();
    cout<<ans<<endl;
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    for(int i=0;i<biao.size();i++){
        M1[biao[i]]=i+1;
    }
    for(int i=0;i<biao2.size(); i++){
        M2[biao2[i]]=i+1;
    }
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
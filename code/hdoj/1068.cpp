#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int n;
int mp[510][510];
int ans = 0;
int pr[510];
int book[510];
bool dfs(int x){
    for(int i=0;i<n;i++){
        if(mp[x][i]&& !book[i]){
            book[i] = 1;
            if(pr[i]==-1||dfs(pr[i])){
                pr[i] = x;
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
            ans++;
        }
    }
    return;
}
void work(){
    memset(mp,0, sizeof(mp));
    for(int i=0;i<n;i++){
        int f;
        int k;
         scanf("%d: (%d)",&f,&k);
        //cout<<k<<endl;
        int tmp;
        for(int j=0;j<k;j++){
           //  cout<<"da"<<endl;
            cin>>tmp;
            mp[f][tmp]=1;
        }
    }
    xyl();
    cout<<n-ans/2<<endl;
    return ;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(cin>>n){
        work();
    }
    return 0;
}  
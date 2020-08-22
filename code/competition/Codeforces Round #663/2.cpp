#include <bits/stdc++.h>
using namespace std;
char mp[110][110];
void work(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    int ans=0;
    for(int i=1;i<n;i++)
        if(mp[i][m]!='D')
            ans++;
    for(int i=1;i<m;i++)
        if(mp[n][i]!='R')
            ans++;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
}
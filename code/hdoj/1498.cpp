#include<bits/stdc++.h>
using namespace std;
int mp[110][110];
int book[110];
int pr[110];
int n,k;
int now;
int ans[110];
bool dfs(int x){
    for(int i = 0;i < n;i++)
    {
        if(mp[x][i] == now && !book[i])
        {
            book[i] = true;
            if(pr[i]== -1 || dfs(pr[i]))
            {
                pr[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
void xyl(){
    ans[now]=0;
    memset(pr, -1, sizeof(pr));
    for(int i=0; i < n; i++){
        memset(book, 0, sizeof(book));
        ans[now]+=dfs(i);
    }
    return;
}
int main(){
    //freopen("in.txt", "r", stdin);
    while(cin>>n>>k){
        if(n==k&&k==0)
        break;
        memset(mp,0,sizeof(mp));
        memset(ans, 0, sizeof(ans));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            cin>>mp[i][j];
        }
        for(int i=1;i<=50;i++){
            now=i;
            xyl();            
        }
        vector<int> v;
        for(int i=0;i<51;i++){
            if(ans[i]>k)
            v.push_back(i);
        }
        if(v.empty()){
            cout<<-1<<endl;
        }else{
            for(int i=0;i<v.size()-1; i++){
                cout<<v[i]<<' ';
            }
            cout<<v[v.size()-1]<<endl;
        }
    }
    return 0;
}
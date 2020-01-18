#include<bits/stdc++.h>
using namespace std;
const int inf =1000000;
typedef long long ll;
int dis[1010];
int mp[1010][1010];
int t,s,d;
struct cmp
{
    bool operator()(int a,int b){
        return  dis[a]>dis[b];
    }
};

void work(){
    int n=1010;
    memset(mp,inf,sizeof(mp));
    for(int i=0;i<n;i++){
        mp[i][i]=0;
    }
    int w,u,v;
    for(int i=0;i<t;i++){
        scanf("%d%d%d",&w,&u,&v);
        mp[w][u]=min(v,mp[w][u]);
        mp[u][w]=mp[w][u];
    }
    for(int i=0;i<s;i++){
        scanf("%d",&w);
        mp[0][w]=0;
        mp[w][0]=0;
    }
    vector<int> ans;
    for(int i=0;i<d;i++){
        scanf("%d",&w);
        ans.push_back(w);
    }
    for(int i=0;i<=n;i++){
        dis[i]=inf;
    }
    dis[0]=0;
    priority_queue<int,vector<int>,cmp> q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    while(!q.empty()){
        for(int i=0;i<n;i++){
            dis[i]=min(dis[i],dis[q.top()]+mp[q.top()][i]);
        }
        q.pop();
    }
    //cout<<t<<' '<<s<<' '<<d<<"lol"<<endl;
    int mi=inf;
    for(int i=0;i<d;i++){   
        mi=min(dis[ans[i]],mi);
    }
    cout<<mi<<endl;
    return;
}
int main(){
    freopen("in.txt","r",stdin);
  //  int t=1;
    //cin>>t;
    while(cin>>t>>s>>d){
        work();
    }
    return 0;
} 
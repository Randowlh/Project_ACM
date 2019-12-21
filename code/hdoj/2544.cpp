#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf =0x7FFFFFFF;
struct node
{   
    int num;
    int date;
};
int n,m;
int dis[110];
int book[110];
vector<node> lb[110];
bool spfa(){
    queue<int> q;
    q.push(1);
    book[1]++;
    while(!q.empty()){
        for(int i=0;i<lb[q.front()].size();i++){
            if(dis[lb[q.front()][i].num]>dis[q.front()]+lb[q.front()][i].date){
                int tmp=lb[q.front()][i].num;
                dis[tmp]=dis[q.front()]+lb[q.front()][i].date;
                if(book[tmp]%2==0){
                    book[tmp]++;
                    q.push(tmp);
                }
            }
        }
        book[q.front()]++;
        q.pop();
    }
    return true;
}
int main(){
        while(cin>>n>>m){
            if(n==m&&m==0){
                break;
            }
            int u,w,v;
            for(int i=0;i<=n;i++){
                dis[i]=inf;
                lb[i].clear();
            }
            for(int i=0;i<m;i++){
                scanf("%d%d%d",&u,&w,&v);
                node a;
                a.date=v;
                a.num=w;
                lb[u].push_back(a);
                a.num=u;
                lb[w].push_back(a);
            }
            dis[1]=0;
            spfa();
            cout<<dis[n]<<endl;
        }
        return 0;
}
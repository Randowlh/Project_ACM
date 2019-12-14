#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
//priority_queue<int> qe;
int map[1010][1010];
int dis[1010];
int book[1010];
int n;
struct node{
 int x;
 bool operator < (const node &a) const{
     return dis[this->x]<dis[a.x];
 }
};
//bool cmp(int a,int b){
 //   return dis[a]<dis[b];
//}
//priority_queue<node> qe;
struct cmp
{
    bool operator()(int a,int b){
        return dis[a]<dis[b];
    }
};
void Dijkstra()
{
    priority_queue<int, std::vector<int>, cmp> pq;
    pq.push(0);
    dis[0] = 0;
    while (!pq.empty())
    {
        int tmp = pq.top();pq.pop();
        for (int i = 0;i < n;++i)
        {
            if (dis[i] > dis[tmp] + map[tmp][i])
            {
                dis[i] = dis[tmp] + map[tmp][i];
                pq.push(i);
            }
        }
    }
}
int main(){
    int t,s,d;
    //priority_queue<node> q;
    //q.push(a.x);
    while(cin>>t>>s>>d){
        int b,e,v;
         n=min(t+s+d+100,1010);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                map[i][j]=inf;
                if(i==j){
                    map[i][j]=1;
                }
            }
        for(int i=0;i<t;i++){
            scanf("%d%d%d",&b,&e,&v);
            map[s][t]=min(map[s][t],v);
            map[t][s]=map[s][t];  
        }
        for(int i=0;i<s;i++){
            scanf("%d",&s);
            map[0][s]=0;
        }
        for(int i=0;i<n;i++){
            book[i]=0;
        }
       dis[0]=0;
       priority_queue<int,vector<int> ,cmp > qe;
            qe.push(0);
    for(int i=0;i<n;i++){
        if(book[qe.top()]||qe.empty()==1){
            break;
        }
        book[qe.top()]=1;
        int tmp=qe.top();
        qe.pop();
        for(int j=0;j<n;j++){
            if(map[tmp][j]<inf){
                if(dis[j]>dis[tmp]+map[tmp][j]){
                    dis[j]=dis[tmp]+map[tmp][j];
                    qe.push(j); 
                }
            }
        }
    }
    */
    int mi=inf;
    for(int i=0;i<d;i++){
        scanf("%d",&e);
        if(dis[e]<mi)
        mi=dis[e];
    }
    cout<<mi<<endl;
    }
    return 0;

}
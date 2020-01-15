#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<queue>
using namespace std;
const int inf =0x7FFFFFFF;
struct node
{   
    int num;
    int date;
    /* data */
};
int fl=0;
map<string, int> mp;
map<int,string> mq;
//int u[10010];
//int n;
int cnt;
int dis[10010];
vector<node> c[10010];
vector<int> road[10010];
int flag[10010]; 
bool spfa(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        for(int i=0;i<c[q.front()].size();i++){
            if(dis[c[q.front()][i].num]>dis[q.front()]+c[q.front()][i].date){
                int tmp=c[q.front()][i].num;                
                dis[tmp]=dis[q.front()]+c[q.front()][i].date;
                road[tmp].push_back(q.front());
                if(flag[tmp]%2==0){
                    flag[tmp]++;
                    q.push(tmp);
                }
            }
        }
        flag[q.front()]++;
        q.pop();
    }
    return true;
}
int main()
{   freopen("in.txt","r",stdin);
    int n;
    while (true)
    {   fl=0;
        cin >> n;
        if (n == -1)
            break;
        for(int i=0;i<n;i++){
        dis[i]=inf;
        flag[i]=0;
        road[i].clear();
        c[i].clear();
        }
        mp.clear();
        string u,w;
        int v;
        int sx,sy;
        cin>>u>>w;
        if(u==w){
            fl=1;
        }
        mp[u]=1;
        mq[1]=u;
        mp[w]=2;
        mq[2]=w;
        sx=1;
        sy=2;
         cnt=3;
        for(int i=0;i<n;i++){
            cin>>u>>w>>v;
            int fr,ed;
            if(mp.count(u)==0){
                mp[u]=cnt;
                mq[cnt]=u;
                fr=cnt;
                cnt++;
            }else fr=mp[u];
            if(mp.count(w)==0){
                mp[w]=cnt;
                mq[cnt]=w;
                ed=cnt;
                cnt++;
            }else ed=mp[w];
            node a;
            a.date=v;
            a.num=ed;
            c[fr].push_back(a);
            a.num=fr;
            c[ed].push_back(a);
        }
        flag[1]=1;
        
        dis[1]=0;
        if(fl==1)
        cout<<0<<endl;
        else
        if(spfa()){
            cout<<dis[2]<<endl;
        }
    }
    return 0;
}
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int x,y;
    int t;
}queue[1000000];
int head,tail;
int biao[8][2]={{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1}};
int flag[10][10];
int sx,sy,ex,ey;
bool check(int k){
    if(queue[head].x+biao[k][0]<8&&queue[head].x+biao[k][0]>=0&&queue[head].y+biao[k][1]<8&&queue[head].y+biao[k][1]>=0){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s,e;
    while(cin>>s>>e){
        sx=s[0]-'a';
        sy=s[1]-'1';
        ex=e[0]-'a';
        ey=e[1]-'1';
        memset(flag,0,sizeof(flag));
        head=0;
        tail=0;
        flag[sx][sy]=1;
        queue[tail].x=sx;
        queue[tail].y=sy;
        queue[tail].t=0;
        tail++;
        int ans=-1;
        //cout<<ex<<' '<<ey<<endl;
        while(tail^head){
           // cout<<queue[head].x<<' '<<queue[head].y<<' '<<queue[head].t<<endl;
            if(queue[head].x==ex&&queue[head].y==ey){
                ans=queue[head].t;
                break;
            }
            for(int i=0;i<8;i++){
                if(check(i)&&flag[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]]==0){
                    flag[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]]=1;
                    queue[tail].x=queue[head].x+biao[i][0];
                    queue[tail].y=queue[head].y+biao[i][1];
                    queue[tail].t=queue[head].t+1;
                    tail++;
                }
            }
            head++;
        }
        cout<<"To get from "<<s<<" to "<<e<<" takes "<<ans<<" knight moves."<<endl;
    }
    return 0;
}
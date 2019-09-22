#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int x;
    int y;
    int col;
} queue[100000];
int head=0;
int tail=0;
int n;
int biao[8][2]={{1,2},{2,1},{-1,2},{-1,-2},{2,-1},{-2,-1},{2,-1},{1,-2}};
int map[110][110];
int main(){
    cin>>n;
    queue[tail].x=0;
    queue[tail].y=0;
    queue[tail].col=1;
    map[0][0]=1;
    tail++;
    while(head!=tail){
        for(int i=0;i<8;i++){
            if(queue[head].x+biao[i][0]>=0&&queue[head].x+biao[i][0]<n&&queue[head].y+biao[i][1]>=0&&queue[head].y+biao[i][1]<n&&map[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]]==0){
                 map[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]]=0-queue[head].col;
                    queue[tail].x=queue[head].x+biao[i][0];
                    queue[tail].y=queue[head].y+biao[i][1];
                    queue[tail].col=0-queue[head].col;
                    tail++;
            }
            
        }head++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1){
                printf("W");
            }
            else{
                printf("B");
            }
        }
        cout<<endl;
    }
    return 0;
}
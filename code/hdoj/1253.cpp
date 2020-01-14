#include <cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
   // int t;
} queue[10000000];
int tail;
int biao[6][3]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
int a, b, c, t;
int head;
int map[51][51][51];
int book[51][51][51];
int time[51][51][51];
int main()
{
    int n;
    scanf("%d", &n);
    for (int q = 0; q < n; q++)
    {
        // int a,b,c;
        scanf("%d%d%d%d", &a, &b, &c,&t);
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int k = 0; k < c; k++)
                {
                    scanf("%d", &map[i][j][k]);
                    time[i][j][k]=999999;
                    book[i][j][k]=0;
                }
                head=0;
                tail=0;
        queue[tail].x=0;
        queue[tail].y=0;
        queue[tail].z=0;
        tail++;
        time[0][0][0]=0;
        book[0][0][0]=1;
        while(head^tail){
            for(int i=0;i<6;i++){
                if(queue[head].x+biao[i][0]>=0&&queue[head].x+biao[i][0]<a&&queue[head].y+biao[i][1]>=0&&queue[head].y+biao[i][1]<b&&queue[head].z+biao[i][2]>=0&&queue[head].z+biao[i][2]<c&&map[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]][queue[head].z+biao[i][2]]==0&&book[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]][queue[head].z+biao[i][2]]==0){
                    queue[tail].x=queue[head].x+biao[i][0];
                    queue[tail].y=queue[head].y+biao[i][1];
                    queue[tail].z=queue[head].z+biao[i][2];
                    book[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]][queue[head].z+biao[i][2]]=1;
                    time[queue[head].x+biao[i][0]][queue[head].y+biao[i][1]][queue[head].z+biao[i][2]]=1+time[queue[head].x][queue[head].y][queue[head].z];
                    tail++;
                }
            }
            head++;
        }
        if(time[a-1][b-1][c-1]<=t){
            cout<<time[a-1][b-1][c-1]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
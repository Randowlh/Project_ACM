#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int x;
    int y;
}que[250000];
int q[520];
int head,tail;
int m,n;
int tail1;
int map[520][520];
int book[520][520];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    if(map[0][0]>=map[0][1]){
        q[tail1]=0;
        tail1++;
    }
    if(map[0][m-1]>=map[0][m-2]){
        q[tail1]=m-1;
        tail1++;
    }
    for(int i=1;i<m-1;i++){
        if(map[0][i]>=map[0][i-1]&&map[0][i]>=map[0][i+1]){
            q[tail]=
        }
    }
}
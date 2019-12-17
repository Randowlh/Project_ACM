#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
//long long a[4];
struct node
{
    long long x;
    int num;
    bool operator<(node a){
        return this->x>a.x;
    }
    /* data */
}a[4];

long long sx,sy;
int main(){
    int n;
    cin>>n>>sx>>sy;
    int tmpx,tmpy;
    for(int i=0;i<n;i++){
        scanf("%d%d",&tmpx,&tmpy);
        if(tmpx==sx&&tmpy>sy){
            a[0].x++;
        }else
        if(tmpx>sx&&tmpy==sy){
            a[1].x++;
        }else
        if(tmpx==sx&&tmpy<sy){
            a[2].x++;
        }else 
        if(tmpy<sx&&tmpy==sy){
            a[3].x++;
        }else if(tmpx>sx&&tmpy>sy){
            a[0].x++;
            a[1].x++;
        }else if(tmpx>sx&&tmpy<sy){
            a[2].x++;
            a[1].x++;
        }else if(tmpx<sx&&tmpy<sy){
            a[3].x++;
            a[2].x++;
        }else {
            a[3].x++;
            a[0].x++;
        }
    }
    for(int i=0;i<4;i++){
        a[i].num=i;
    }
    sort(a,a+4);
    cout<<a[0].x<<endl;
    if(a[0].num==0){
        cout<<sx<<' '<<sy+1<<endl;
    }else if(a[0].num==1){
        cout<<sx+1<<' '<<sy<<endl;
    }else if(a[0].num==2){
        cout<<sx<<' '<<sy-1<<endl;
    }else cout<<sx-1<<' '<<sy<<endl;
    return 0;
}
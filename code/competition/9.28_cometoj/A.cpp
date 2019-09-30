#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int tail;
int dis[100010];
int date[100010];
int flag[100010];
int  main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        scanf("%d",&date[i]);
        flag[date[i]]=1;
    }
    tail=0;
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
           dis[tail]=i;
            tail++; 
        }
    }
    int head1=0;
    int head2=0;
    sort(dis,dis+tail);
    for(int i=0;i<n;i++){
        if(head1>=m){
            for(int j=head2;j<n-m;j++){
                printf("%d\n",dis[head2]);
            }
            return 0;
        }else   if(head2>=n-m){
            for(int j=head1;j<m;j++){
                printf("%d\n",date[head1]);
                return 0;
            }
        }
        if(date[head1]>dis[head2]){
            printf("%d\n",dis[head2]);
            head2++;
        }else{
            printf("%d\n",date[head1]);
            head1++;
        }
    }
    return 0;
}
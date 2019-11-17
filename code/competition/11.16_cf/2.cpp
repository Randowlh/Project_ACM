#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int date[100100];
int n;
int tail=0;
int st[100100];
int maps[1000100];
//int sw[100100];
int main(){
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(date[i]<0){
            if(maps[-date[i]]!=tail+1){
                printf("-1\n");
                return 0;
            }
            maps[-date[i]]=-tail-1;
            k--;
        }else
        if(date[i]>0){
            if(maps[date[i]]==tail+1||maps[date[i]]==-tail-1){
                printf("-1\n");
                return 0;
            }
            maps[date[i]]=tail+1;
            k++;
            cnt++;
        }
        if(k==0){
            /*
            if(tail==0){
                for(int j=0;j<=i;j++){
                if(date[j]>0){
                    maps[date[j]]=0;
                }
            }
            }else
            for(int j=st[tail-1];j<=i;j++){
                if(date[j]>0){
                    maps[date[j]]=0;
                }
            }
            */
            st[tail]=cnt*2;
            cnt=0;
            tail++;
        }
    }
    if(k!=0){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",tail);
    for(int i=0;i<tail;i++){
        printf("%d ",st[i]);
    }
    cout<<endl; 
    return 0;
}
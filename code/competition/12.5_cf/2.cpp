#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int ans[300100];
int tail;
int date[300100];
int main(){
    int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++){
        int n;
        tail=0;
        scanf("%d",&n);
        int l=0;
        int r=0;
        int max=1;
        int tol=1;
        for(int i=0;i<n;i++){
            scanf("%d",&date[i]);
            if(date[i]==1){
                r=i;
                l=i;
            }
        }
        while(tol<=n){
            if(max==tol){
                ans[tail]=max;
                tail++;
            }
            int flag1=0;
            if(r+1<n&&date[r+1]<max){
                tol++;
                r++;
                flag1=1;
            }
            if(l-1>=0&&date[l-1]<max){
                tol++;
                l--;
                flag1=1;
            }
            //cout<<max<<endl;
            if(flag1==0){
                int flag=0;
                int in=99999999;
                if(r+1<n){
                    in=date[r+1];
                    flag=1;
                }
                if(l-1>=0&&date[l-1]<in){
                    in=date[l-1];
                    flag=-1;
                }
                if(flag==1){
                    tol++;
                    max=date[r+1];
                    r++;
                }else{
                    tol++;
                    max=date[l-1];
                    l--;
                }
            }
        }
        int head=0;
        for(int i=0;i<n;i++){
            if(head<=(tail-1)&&i+1==ans[head]){
                cout<<1;
                
                    head++;
            }else cout<<0;
        }
        cout<<endl;
    }
}

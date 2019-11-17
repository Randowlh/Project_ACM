#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int k;
int t;
int n;
int a[100100];
int b[100100];
int main(){
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int flag=0;
        int fr=-1;
        int ed=-1;
        int flagt=-1;
        for(int i=0;i<n;i++){
            if(a[i]<b[i]&&flag==0){
                flag=1;
                flagt=b[i]-a[i];
                fr=i;
                ed=i;
            }else
            if(flag==1&&a[i]<b[i]){
                if(b[i]-a[i]==flagt&&ed==i-1){
                    ed++;
                }else{
                    flag=2;
                    break;
                }
            }else
            if(a[i]>b[i]){
                flag=2;
                break;
            }
        }
        if(flag==2){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}
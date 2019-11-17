#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int abs(int a){
    if(a<0)return -a;
    else return a;
}
int main(){
    int a[100];
    int st[100];
    int tail=0;
    int max=1<<29;
    int maxt=0;
    int n;
    cin>>n;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    //sort(a,a+n);
    for(int i=0;i<10;i++){
        if(abs(n-a[i])<max){
            max=abs(n-a[i]);
            tail=0;
            st[tail]=i;
            tail++;
        }else{
            if(abs(n-a[i])==max){
                st[tail]=i;]
                tail++;
            }
        }
    }
    for(int i=0;i<tail;i++){
        cout<<st[i]<<' ';
    }cout<<endl;
    printf("%.1f",(double)n/(double)(tail));
    return 0;
}